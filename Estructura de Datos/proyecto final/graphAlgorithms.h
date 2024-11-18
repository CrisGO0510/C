#include "TADgrafo.h"

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
