#include "graphAlgorithms.h"

int main()
{
  // Crear el grafo principal
  nodeGraph *graph = (nodeGraph *)malloc(sizeof(nodeGraph)); // Inicializamos la lista de vértices vacía
  graph->vertices = NULL;
  graph->edges = NULL;

  // Agregar vértices al grafo
  insertVertex(&(graph->vertices), 1);
  insertVertex(&(graph->vertices), 2);
  insertVertex(&(graph->vertices), 3);
  insertVertex(&(graph->vertices), 4);
  insertVertex(&(graph->vertices), 5);
  insertVertex(&(graph->vertices), 6);
  insertVertex(&(graph->vertices), 7);
  insertVertex(&(graph->vertices), 8);
  insertVertex(&(graph->vertices), 9);

  // Agregar arcos al grafo
  insertEdge(&(graph->edges), 1, 2, 0);
  insertEdge(&(graph->edges), 1, 3, 0);
  insertEdge(&(graph->edges), 2, 6, 0);
  insertEdge(&(graph->edges), 2, 7, 0);
  insertEdge(&(graph->edges), 3, 7, 0);
  insertEdge(&(graph->edges), 7, 8, 0);

  insertEdge(&(graph->edges), 4, 5, 0);
  insertEdge(&(graph->edges), 4, 9, 0);


  // // Recorrer la lista de vértices
  // VertexNode *a = getChildVertices(graph, 8);
  // printVertices(a);

  // printVertices(graph->vertices);
  // printEdges(graph->edges);

  VertexNode *a = DFS(graph, 1);
  printVertices(a);

  // while (a != NULL)
  // {
  //   printf("%d - ", a->value);
  //   a = a->next;
  // }

  printf("FIN\n");

  return 0;
}
