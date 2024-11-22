#include "TADgrafo.h"
#include <limits.h>

/**
 * @brief Realiza un recorrido en anchura (BFS) en un grafo a partir de un nodo inicial.
 *
 * Esta función implementa el algoritmo Breadth-First Search (BFS) para explorar un grafo desde un nodo dado. 
 * Marca los nodos como visitados para evitar ciclos y devuelve una lista de vértices visitados durante el recorrido.
 *
 * @param graphRoot Puntero a la raíz del grafo que contiene las listas de vértices y aristas.
 * @param nodeValue Valor del nodo inicial desde el cual se realizará el recorrido en anchura.
 * @return VertexNode* Puntero a la lista de vértices visitados en el orden en que fueron explorados. 
 * Si el nodo inicial no existe, devuelve NULL.
 */
VertexNode *BFS(nodeGraph *graphRoot, int nodeValue)
{
    // Verificamos que el grafo y la lista de vértices no estén vacías
    if (graphRoot == NULL || graphRoot->vertices == NULL)
        return NULL;

    // Buscar el nodo desde el cual se realizará el recorrido
    VertexNode *current = graphRoot->vertices;
    while (current != NULL && current->value != nodeValue)
    {
        current = current->next;
    }

    // Verificar si el nodo inicial existe en el grafo
    if (current == NULL)
    {
        printf("Nodo con valor %d no encontrado.\n", nodeValue);
        return NULL;
    }

    // Obtener los hijos del nodo inicial y marcarlo como visitado
    markVertex(&graphRoot, nodeValue, 1);
    VertexNode *vertexList = getChildVertices(graphRoot, current->value);

    // Marcamos a los nodos hijos como visitados
    VertexNode *currentVertex = vertexList;
    while (currentVertex != NULL)
    {
        markVertex(&graphRoot, currentVertex->value, 1);
        currentVertex = currentVertex->next;
    }

    VertexNode *headVertexList = NULL;
    insertVertex(&headVertexList, current->value);
    headVertexList->next = vertexList;

    // Realizar el recorrido BFS
    while (vertexList != NULL)
    {
        // Obtener los hijos del nodo actual
        VertexNode *childVertices = getChildVertices(graphRoot, vertexList->value);

        // Procesar cada hijo del nodo actual
        while (childVertices != NULL)
        {
            if (childVertices->marked == 0) // Solo procesar nodos no visitados
            {
                printf("Insertando %d\n", childVertices->value);
                markVertex(&graphRoot, childVertices->value, 1); // Marcar como visitado
                insertVertex(&vertexList, childVertices->value); // Insertar en la lista de vértices
            }

            childVertices = childVertices->next; // Pasar al siguiente hijo
        }

        vertexList = vertexList->next; // Pasar al siguiente nodo en la lista
    }

    // Retornar la lista de nodos visitados
    return headVertexList;
}

/**
 * @brief Realiza un recorrido en profundidad (DFS) en un grafo a partir de un nodo inicial.
 *
 * Esta función implementa el algoritmo de Depth-First Search (DFS) para recorrer un grafo desde un nodo dado. 
 * Marca los nodos como visitados para evitar ciclos y devuelve una lista de vértices visitados durante el recorrido.
 *
 * @param graphRoot Puntero a la raíz del grafo que contiene las listas de vértices y aristas.
 * @param nodeValue Valor del nodo inicial desde el cual se realizará el recorrido en profundidad.
 * @return VertexNode* Puntero a la lista de vértices visitados en el orden en que fueron explorados. 
 * Si el nodo inicial no existe, o si el nodo ya fue visitado, devuelve NULL.
 */
VertexNode *DFS(nodeGraph *graphRoot, int nodeValue)
{
    // Verificamos que el grafo y la lista de vértices no estén vacías
    if (graphRoot == NULL || graphRoot->vertices == NULL)
        return NULL;

    // Buscar el nodo desde el cual se realizará el recorrido
    VertexNode *current = graphRoot->vertices;
    while (current != NULL && current->value != nodeValue)
    {
        current = current->next;
    }

    // Verificar si el nodo inicial existe en el grafo
    if (current == NULL)
    {
        printf("Nodo con valor %d no encontrado.\n", nodeValue);
        return NULL;
    }

    // Verificar si el nodo ya fue visitado
    if (current->marked == 1)
        return NULL;

    // Marcar el nodo como visitado y crear la lista de nodos visitados
    markVertex(&graphRoot, nodeValue, 1);
    VertexNode *headVertexList = NULL; // Crear un nuevo nodo para la lista
    insertVertex(&headVertexList, nodeValue);

    // Obtener los hijos del nodo actual
    VertexNode *vertexList = getChildVertices(graphRoot, current->value);

    // Recorrer recursivamente los hijos
    while (vertexList != NULL)
    {
        if (vertexList->marked == 0) // Solo visitar nodos no marcados
        {
            VertexNode *childVertices = DFS(graphRoot, vertexList->value);

            // Insertar los nodos visitados en la lista principal
            while (childVertices != NULL)
            {
                insertVertex(&headVertexList, childVertices->value);
                childVertices = childVertices->next;
            }
        }

        vertexList = vertexList->next;
    }

    return headVertexList;
}

/**
 * @brief Implementa el algoritmo de Dijkstra para encontrar el camino más corto entre un nodo inicial y un nodo destino en un grafo dirigido y ponderado.
 *
 * Este algoritmo calcula las distancias más cortas desde un nodo fuente hasta todos los demás nodos del grafo.
 *
 * @param graphRoot Puntero a la raíz del grafo, que contiene la lista de vértices y aristas.
 * @param initialValue Vértice de inicio desde el cual se calcularán las distancias más cortas.
 * @param finishValue Vértice de destino al cual se busca encontrar el camino más corto desde el nodo inicial.
 * @return EdgeNode* Puntero a la lista de aristas que forman el camino más corto entre el nodo inicial y el nodo final. 
 * Si no existe un camino válido o el grafo contiene un ciclo negativo, retorna NULL.
 */
EdgeNode *Dijkstra(nodeGraph *graphRoot, int initialValue, int finishValue)
{
  // Verificar si el grafo, los vértices o los arcos son nulos
  if (graphRoot == NULL || graphRoot->vertices == NULL || graphRoot->edges == NULL)
  {
    return NULL;
  }

  // Inicializar las distancias mínimas y los nodos previos
  VertexNode *currentVertex = graphRoot->vertices;
  int numVertices = 0;

  int minDistances[100]; // Arreglo para almacenar las distancias mínimas desde el nodo inicial
  int previous[100];     // Arreglo para rastrear el nodo previo en el camino más corto

  for (int i = 0; i < 100; i++)
  {
    minDistances[i] = INT_MAX; // Inicializar todas las distancias como infinito
    previous[i] = -1;          // Inicializar todos los nodos previos como inexistentes
  }

  // Inicializar el estado de no visitado para cada vértice y configurar la distancia inicial
  while (currentVertex != NULL)
  {
    currentVertex->marked = 0; // Marcamos todos los vértices como no visitados
    if (currentVertex->value == initialValue)
    {
      minDistances[currentVertex->value] = 0; // La distancia al nodo inicial es 0
    }
    numVertices++; // Contar el número de vértices en el grafo
    currentVertex = currentVertex->next;
  }

  // Paso principal del algoritmo: procesar todos los vértices del grafo
  for (int i = 0; i < numVertices; i++)
  {
    printf("Paso %i\n", i + 1);

    // Encontrar el nodo no visitado con la distancia mínima
    int minDistance = INT_MAX;
    VertexNode *minVertex = NULL;

    currentVertex = graphRoot->vertices;
    while (currentVertex != NULL)
    {
      // Si el nodo no ha sido visitado y su distancia es menor que la actual mínima
      if (!currentVertex->marked && minDistances[currentVertex->value] < minDistance)
      {
        minDistance = minDistances[currentVertex->value];
        minVertex = currentVertex; // Actualizamos el nodo con menor distancia
      }
      currentVertex = currentVertex->next;
    }

    // Si no encontramos un nodo no visitado, terminamos el proceso
    if (minVertex == NULL)
    {
      break;
    }

    // Marcar el nodo seleccionado como visitado
    minVertex->marked = 1;

    // Relajar los vecinos del nodo seleccionado
    EdgeNode *currentEdge = graphRoot->edges;
    while (currentEdge != NULL)
    {
      // Buscar los arcos que parten del nodo actual
      if (currentEdge->from == minVertex->value)
      {
        int weight = currentEdge->cost; // Costo del arco actual

        // Buscar el vértice destino en la lista de vértices
        VertexNode *neighborVertex = graphRoot->vertices;
        while (neighborVertex != NULL && neighborVertex->value != currentEdge->to)
        {
          neighborVertex = neighborVertex->next;
        }

        // Imprimir detalles del proceso de relajación
        printf("%i -> %i distancia: %i + %i < %i\n",
               neighborVertex->value, minVertex->value,
               minDistances[minVertex->value], weight, minDistances[currentEdge->to]);

        // Si encontramos un camino más corto hacia el nodo vecino
        if (neighborVertex != NULL &&
            minDistances[minVertex->value] + weight < minDistances[currentEdge->to])
        {
          // Actualizamos la distancia mínima y el nodo previo
          minDistances[currentEdge->to] = minDistances[minVertex->value] + weight;
          previous[currentEdge->to] = minVertex->value;
        }
      }
      currentEdge = currentEdge->next; // Continuar con el siguiente arco
    }
    printf("-------\n");
  }

  // Reconstruir el camino más corto utilizando el arreglo `previous`
  EdgeNode *shortestPath = NULL;

  int currentNode = finishValue;
  while (currentNode != -1 && previous[currentNode] != -1)
  {
    // Insertar el arco en la lista de arcos que representa el camino más corto
    insertEdge(&shortestPath, previous[currentNode], currentNode,
               minDistances[currentNode] - minDistances[previous[currentNode]]);
    currentNode = previous[currentNode]; // Avanzar al nodo previo
  }

  // Verificar si existe un camino válido al nodo destino
  if (shortestPath == NULL || minDistances[finishValue] == INT_MAX)
  {
    printf("No hay camino del nodo %d al nodo %d.\n", initialValue, finishValue);
    return NULL;
  }

  // Retornar la lista de arcos que forman el camino más corto
  return shortestPath;
}

/**
 * @brief Implementa el algoritmo de Bellman-Ford para encontrar el camino más corto en un grafo dirigido y ponderado.
 *
 * Este algoritmo calcula las distancias más cortas desde un nodo fuente hasta todos los demás nodos del grafo.
 *
 * @param graphRoot Puntero a la raíz del grafo, que contiene la lista de vértices y aristas.
 * @param initialValue Vértice de inicio desde el cual se calcularán las distancias más cortas.
 * @param finishValue Vértice de destino al cual se busca encontrar el camino más corto desde el nodo inicial.
 * @return EdgeNode* Puntero a la lista de aristas que forman el camino más corto entre el nodo inicial y el nodo final. 
 * Si no existe un camino válido o el grafo contiene un ciclo negativo, retorna NULL.
 */
EdgeNode *BellmanFord(nodeGraph *graphRoot, int initialValue, int finishValue)
{
    // Verifica si el grafo tiene vértices y aristas válidas
    if (graphRoot == NULL || graphRoot->vertices == NULL || graphRoot->edges == NULL)
    {
        return NULL;  // Si no hay vértices o aristas, retorna NULL
    }

    // Inicializar las distancias y los nodos previos
    VertexNode *currentVertex = graphRoot->vertices;
    int numVertices = 0;

    // Inicializar las distancias con infinito y los nodos previos con -1
    int minDistances[100];
    int previous[100];

    for (int i = 0; i < 100; i++)
    {
        minDistances[i] = INT_MAX; // Inicializar con infinito
        previous[i] = -1;          // Inicializar sin nodo previo
    }

    // Establecer la distancia del nodo inicial a 0
    minDistances[initialValue] = 0;

    // Contar el número de vértices en el grafo
    while (currentVertex != NULL)
    {
        numVertices++;
        currentVertex = currentVertex->next;
    }

    // Paso 1: Realizar la relajación de aristas (V - 1) veces
    for (int i = 1; i < numVertices; i++) // Se realizan (V-1) iteraciones
    {
        EdgeNode *currentEdge = graphRoot->edges;
        while (currentEdge != NULL)
        {
            int from = currentEdge->from;
            int to = currentEdge->to;
            int weight = currentEdge->cost;

            // Si la distancia desde el nodo origen no es infinita, intentar relajar la arista
            if (minDistances[from] != INT_MAX &&
                minDistances[from] + weight < minDistances[to])
            {
                minDistances[to] = minDistances[from] + weight;
                previous[to] = from; // Actualizar el nodo previo
            }
            currentEdge = currentEdge->next;
        }
    }

    // Paso 2: Verificar la existencia de ciclos negativos
    EdgeNode *currentEdge = graphRoot->edges;
    while (currentEdge != NULL)
    {
        int from = currentEdge->from;
        int to = currentEdge->to;
        int weight = currentEdge->cost;

        // Si se puede relajar nuevamente, significa que hay un ciclo negativo
        if (minDistances[from] != INT_MAX &&
            minDistances[from] + weight < minDistances[to])
        {
            printf("El grafo contiene un ciclo negativo.\n");
            return NULL; // No se puede calcular un camino más corto válido
        }
        currentEdge = currentEdge->next;
    }

    // Paso 3: Reconstruir el camino más corto utilizando el arreglo `previous`
    EdgeNode *shortestPath = NULL;
    int currentNode = finishValue;

    // Recorre el camino desde el nodo destino hasta el nodo fuente
    while (currentNode != -1 && previous[currentNode] != -1)
    {
        // Insertar arista en el camino más corto
        insertEdge(&shortestPath, previous[currentNode], currentNode, minDistances[currentNode] - minDistances[previous[currentNode]]);
        currentNode = previous[currentNode];
    }

    // Si no se encontró un camino válido, retornar NULL
    if (shortestPath == NULL || minDistances[finishValue] == INT_MAX)
    {
        printf("No hay camino del nodo %d al nodo %d.\n", initialValue, finishValue);
        return NULL;
    }

    // Retornar el camino más corto como una lista de aristas
    return shortestPath;
}

/**
 * @brief Implementa el algoritmo de Prim para encontrar el Árbol de Expansión Mínima (MST) de un grafo no dirigido y ponderado.
 *
 * Este algoritmo comienza desde un vértice inicial y agrega las aristas de menor peso que conectan un nodo visitado con un nodo no visitado.
 * El proceso continúa hasta que todos los nodos están conectados, formando así el MST.
 *
 * @param graphRoot Puntero a la raíz del grafo, que contiene la lista de vértices y aristas.
 * @param startVertex Vértice desde el cual comenzar a construir el MST.
 * @return EdgeNode* Puntero al primer nodo de la lista de aristas del MST. Si el grafo no es conexo, retorna NULL.
 */
EdgeNode *Prim(nodeGraph *graphRoot, int startVertex)
{
    // Verifica si el grafo es válido (si tiene vértices y aristas)
    if (graphRoot == NULL || graphRoot->vertices == NULL || graphRoot->edges == NULL)
    {
        return NULL;  // Si no hay vértices o aristas, retorna NULL
    }

    // Inicializar los conjuntos de vértices visitados y no visitados
    VertexNode *currentVertex = graphRoot->vertices;
    int numVertices = 0;

    // Array para marcar los nodos visitados
    int marked[100]; 
    for (int i = 0; i < 100; i++)
    {
        marked[i] = 0; // Ningún nodo ha sido visitado al inicio
    }

    // Contar el número de vértices en el grafo
    while (currentVertex != NULL)
    {
        numVertices++;
        currentVertex = currentVertex->next;
    }

    // Marcar el nodo inicial como visitado
    marked[startVertex] = 1;

    // Inicializar el árbol de expansión mínimo como una lista de arcos
    EdgeNode *minimumSpanningTree = NULL;

    // Paso 2: Iterar (V-1) veces para construir el MST
    for (int i = 0; i < numVertices - 1; i++)
    {
        EdgeNode *currentEdge = graphRoot->edges;
        EdgeNode *minEdge = NULL;

        // Buscar el borde con el menor peso que conecta un nodo visitado con uno no visitado
        while (currentEdge != NULL)
        {
            int from = currentEdge->from;
            int to = currentEdge->to;
            int weight = currentEdge->cost;

            // Considerar solo bordes que conecten nodos visitados con no visitados
            if ((marked[from] && !marked[to]) || (!marked[from] && marked[to]))
            {
                // Actualizar el borde mínimo encontrado
                if (minEdge == NULL || weight < minEdge->cost)
                {
                    minEdge = currentEdge;
                }
            }
            currentEdge = currentEdge->next;
        }

        // Si no encontramos un borde válido, significa que el grafo no es conexo
        if (minEdge == NULL)
        {
            printf("El grafo no es conexo, no se puede construir un árbol de expansión mínimo.\n");
            return NULL;
        }

        // Añadir el borde mínimo al MST
        insertEdge(&minimumSpanningTree, minEdge->from, minEdge->to, minEdge->cost);

        // Marcar ambos nodos del borde como visitados
        marked[minEdge->from] = 1;
        marked[minEdge->to] = 1;
    }

    // Retornar el árbol de expansión mínimo como una lista de arcos
    return minimumSpanningTree;
}

/**
 * @brief Implementa el algoritmo de Kruskal para encontrar el Árbol de Expansión Mínima (MST) de un grafo no dirigido y ponderado.
 *
 * Este algoritmo selecciona las aristas de menor peso, siempre que no forme ciclos, utilizando una estructura de 
 * conjuntos con optimizaciones de búsqueda de raíz y unión por rango.
 *
 * @param graphRoot Puntero a la raíz del grafo, que contiene la lista de vértices y aristas.
 * @return EdgeNode* Puntero al primer nodo de la lista de aristas del MST. Si no es posible formar un MST, retorna NULL.
 */
EdgeNode *Kruskal(nodeGraph *graphRoot)
{
    // Verifica si el grafo es válido (si tiene vértices y aristas)
    if (graphRoot == NULL || graphRoot->vertices == NULL || graphRoot->edges == NULL)
        return NULL;

    // Array para almacenar las aristas del grafo
    EdgeNode *edges[100];
    // Lista que almacenará las aristas que forman el Árbol de Expansión Mínima (MST)
    EdgeNode *minimumSpanningTree = NULL;

    // Arreglo que implementa la estructura de conjuntos para los vértices
    int parent[100];
    // Arreglo para el rango (altura) de los árboles en la estructura de conjuntos (para optimizar la unión de conjuntos)
    int rank[100] = {0};

    // Variable para contar el número de aristas en el grafo
    int numEdges = 0;

    // Puntero para recorrer la lista de vértices del grafo
    VertexNode *currentVertex = graphRoot->vertices;

    // Inicialización de los vértices: cada vértice es su propio padre (representación de conjunto disjunto)
    while (currentVertex != NULL)
    {
        parent[currentVertex->value] = currentVertex->value;  // Cada vértice se apunta a sí mismo
        currentVertex = currentVertex->next;  // Avanza al siguiente vértice
    }

    // Puntero para recorrer la lista de aristas del grafo
    EdgeNode *currentEdge = graphRoot->edges;

    // Copiar las aristas del grafo a un array para poder ordenarlas más fácilmente
    while (currentEdge != NULL)
    {
        edges[numEdges++] = currentEdge;  // Guardamos la arista en el arreglo 'edges'
        currentEdge = currentEdge->next;  // Avanza a la siguiente arista
    }

    // Ordenar las aristas por el costo (peso) de menor a mayor utilizando el algoritmo de burbuja
    for (int i = 0; i < numEdges - 1; i++)
    {
        for (int j = 0; j < numEdges - i - 1; j++)
        {
            if (edges[j]->cost > edges[j + 1]->cost)  // Si la arista j es más costosa que la j+1
            {
                // Intercambiar las aristas para ordenarlas
                EdgeNode *temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Iterar a través de las aristas ordenadas para construir el MST
    for (int i = 0; i < numEdges; i++)
    {
        // Obtenemos la arista actual
        EdgeNode *edge = edges[i];
        int from = edge->from;  // Vértice de origen de la arista
        int to = edge->to;      // Vértice de destino de la arista

        // Buscar el conjunto (grupo) al que pertenece el vértice 'from'
        int setFrom = from;
        while (setFrom != parent[setFrom])  // Sigue el puntero hasta encontrar la raíz del conjunto
        {
            setFrom = parent[setFrom];  // Subir al padre del conjunto
        }

        // Buscar el conjunto (grupo) al que pertenece el vértice 'to'
        int setTo = to;
        while (setTo != parent[setTo])  // Sigue el puntero hasta encontrar la raíz del conjunto
        {
            setTo = parent[setTo];  // Subir al padre del conjunto
        }

        // Si 'from' y 'to' están en diferentes conjuntos, agregamos la arista al MST
        if (setFrom != setTo)
        {
            // Insertamos la arista en el MST
            insertEdge(&minimumSpanningTree, from, to, edge->cost);

            // Unimos los conjuntos de 'from' y 'to' utilizando la técnica de unión por rango
            if (rank[setFrom] < rank[setTo])  // Si el rango de 'from' es menor, hacer que 'to' sea la raíz
            {
                parent[setFrom] = setTo;  // 'from' se convierte en hijo de 'to'
            }
            else if (rank[setFrom] > rank[setTo])  // Si el rango de 'to' es menor, hacer que 'from' sea la raíz
            {
                parent[setTo] = setFrom;  // 'to' se convierte en hijo de 'from'
            }
            else  // Si los rangos son iguales, uno de los vértices se convierte en la raíz del otro y se aumenta el rango
            {
                parent[setTo] = setFrom;  // 'to' se convierte en hijo de 'from'
                rank[setFrom]++;          // Incrementamos el rango de 'from'
            }
        }
    }

    // Retorna el MST formado por las aristas seleccionadas
    return minimumSpanningTree;
}
