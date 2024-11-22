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
  insertVertex(&(graph->vertices), 10);

  // Agregar arcos al grafo
  inserDoubleEdge(&(graph->edges), 1, 2, 3);
  inserDoubleEdge(&(graph->edges), 1, 3, 2);
  inserDoubleEdge(&(graph->edges), 1, 4, 4);

  inserDoubleEdge(&(graph->edges), 2, 5, 2);

  inserDoubleEdge(&(graph->edges), 3, 5, 3);
  inserDoubleEdge(&(graph->edges), 3, 6, 5);
  inserDoubleEdge(&(graph->edges), 3, 7, 4);

  inserDoubleEdge(&(graph->edges), 4, 7, 3);

  inserDoubleEdge(&(graph->edges), 5, 6, 1);
  inserDoubleEdge(&(graph->edges), 5, 8, 3);

  inserDoubleEdge(&(graph->edges), 6, 7, 1);
  inserDoubleEdge(&(graph->edges), 6, 10, 4);

  inserDoubleEdge(&(graph->edges), 7, 9, 2);

  inserDoubleEdge(&(graph->edges), 8, 9, 1);
  inserDoubleEdge(&(graph->edges), 8, 10, 2);

  inserDoubleEdge(&(graph->edges), 9, 10, 2);

  // // Recorrer la lista de vértices
  // VertexNode *a = getChildVertices(graph, 8);
  // printVertices(a);

  // printVertices(graph->vertices);
  // printEdges(graph->edges);

  printf("INICIO\n\n");

  // VertexNode *a = BFS(graph, 1);
  // printVertices(a);

  EdgeNode *e = Kruskal(graph);
  printEdges(e);

  printf("FIN\n");

  return 0;
}
