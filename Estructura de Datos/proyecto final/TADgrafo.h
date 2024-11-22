#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct VertexNode
{
   int value;
   struct VertexNode *next;
   int marked;
} VertexNode;

typedef struct EdgeNode
{
   int from;
   int to;
   int cost;
   struct EdgeNode *next;
} EdgeNode;

typedef struct nodeGraph
{
   VertexNode *vertices;
   EdgeNode *edges;
} nodeGraph;

// Función para adicionar un vertice a la lista de vértices
void insertVertex(VertexNode **vertices, int value)
{
   VertexNode *newNode = (VertexNode *)malloc(sizeof(VertexNode));
   newNode->value = value;
   newNode->marked = 0;
   newNode->next = NULL;

   if (*vertices == NULL)
   {
      *vertices = newNode;
      return;
   }

   VertexNode *current = *vertices;

   while (current->next != NULL)
   {
      current = current->next;
   }
   current->next = newNode;
}

void printVertices(VertexNode *rootVertexNode)
{
   if (rootVertexNode == NULL)
   {
      printf("No hay vértices\n");
      return;
   }

   // while (rootVertexNode != NULL)
   // {
   //    printf("Vertices: %d     marcado: %s\n", rootVertexNode->value, rootVertexNode->marked ? "Si" : "No");
   //    rootVertexNode = rootVertexNode->next;
   // }

   while (rootVertexNode->next != NULL)
   {
      printf("%d -> ", rootVertexNode->value);
      rootVertexNode = rootVertexNode->next;
   }

   printf("%d\n", rootVertexNode->value);
   
}

// Función para adicionar un arco a la lista de arcos
void inserDoubleEdge(EdgeNode **edges, int fromVertice, int toVertice, int cost)
{
   EdgeNode *newEdge = (EdgeNode *)malloc(sizeof(EdgeNode));
   newEdge->from = fromVertice;
   newEdge->to = toVertice;
   newEdge->cost = cost;
   newEdge->next = NULL;

   if (*edges == NULL)
   {
      *edges = newEdge;
   }
   else
   {
      EdgeNode *current = *edges;
      while (current->next != NULL)
      {
         current = current->next;
      }
      current->next = newEdge;
   }

   EdgeNode *reverseEdge = (EdgeNode *)malloc(sizeof(EdgeNode));
   reverseEdge->from = toVertice;
   reverseEdge->to = fromVertice;
   reverseEdge->cost = cost;
   reverseEdge->next = NULL;

   if (*edges == NULL)
   {
      *edges = reverseEdge;
   }
   else
   {
      EdgeNode *current = *edges;
      while (current->next != NULL)
      {
         current = current->next;
      }
      current->next = reverseEdge;
   }
}
void insertEdge(EdgeNode **edges, int fromVertice, int toVertice, int cost)
{
   EdgeNode *newEdge = (EdgeNode *)malloc(sizeof(EdgeNode));
   newEdge->from = fromVertice;
   newEdge->to = toVertice;
   newEdge->cost = cost;
   newEdge->next = *edges;
   *edges = newEdge;
}



// imprime la lista de arcos
void printEdges(EdgeNode *rootEdgeNode)
{
   if (rootEdgeNode == NULL)
   {
      printf("No hay arcos\n");
      return;
   }

   while (rootEdgeNode != NULL)
   {
      printf("Arco: %d -> %d, costo: %d\n", rootEdgeNode->from, rootEdgeNode->to, rootEdgeNode->cost);
      rootEdgeNode = rootEdgeNode->next;
   }
}

// // elimina un vertice del parent
// Graph eliminarVertice(Graph g, int x)
// {
//    ListaVertice k = g.v, p;
//    if (g.v != NULL)
//    {
//       if (g.v->value == x)
//       {
//          g.v = g.v->next;
//          free(k);
//       }
//       else
//       {
//          while ((k->next != NULL) && (k->next->value != x))
//             k = k->next;
//          if (k->next != NULL)
//          {
//             p = k->next;
//             k->next = p->next;
//             free(p);
//          }
//       }
//    }
//    return g;
// }

// // Elimina un arco que parta del from x al to y
// Graph eliminarArco(Graph g, int x, int y)
// {
//    ListaArco k = g.a, p;

//    if (g.a != NULL)
//    {
//       if ((g.a->from == x) && (g.a->to == y))
//       {
//          g.a = g.a->next;
//          free(k);
//       }
//       else
//       {
//          while ((k->next != NULL) && !((k->next->from == x) && (k->next->to == y)))
//             k = k->next;
//          if (k->next != NULL)
//          {
//             p = k->next;
//             printf("\n el arco a borrar es %d   %d", p->from, p->to);
//             k->next = p->next;
//             free(p);
//          }
//       }
//    }
//    return g;
// }

// // retorna el cost del arco desde x hasta y
// int costArco(Graph g, int x, int y)
// {
//    ListaArco k = g.a;

//    while (k != NULL)
//    {
//       if ((k->from == x) && (k->to == y))
//          return k->cost;
//       k = k->next;
//    }
//    return -1; // no encontró el arco
// }

// // retorna el número de vértices asociados al parent
// int ordenGraph(Graph g)
// {
//    int orden = 0;
//    ListaVertice k = g.v;

//    while (k != NULL)
//    {
//       orden++;
//       k = k->next;
//    }
//    return orden;
// }

// // marca un vertice de parent
// Graph marcarVertice(Graph g, int x)
// {
//    ListaVertice k = g.v;

//    while (k != NULL)
//    {
//       if (k->value == x)
//       {
//          k->marked = 1;
//          k = NULL;
//       }
//       else
//          k = k->next;
//    }
//    return g;
// }

// desmarca un vertice de grafo
void markVertex(nodeGraph **graphRoot, int nodeValue, int markValue)
{
   VertexNode *current = (*graphRoot)->vertices;
   while (current != NULL)
   {
      if (current->value == nodeValue)
      {
         current->marked = markValue;
         current = NULL;
      }
      else
         current = current->next;
   }
}

// desmarca todos los vertices del grafo
void markAllVertices(VertexNode **vertices, int value)
{
   VertexNode *current = *vertices;
   while (current != NULL)
   {
      current->marked = value;
      current = current->next;
   }
}

// // Indica si un vértice está marked
// int markedVertice(Graph g, int x)
// {
//    ListaVertice k = g.v;
//    while (k != NULL)
//    {
//       if (k->value == x)
//       {
//          if (k->marked == 0)
//             return 0;
//          else
//             return 1;
//       }
//       else
//          k = k->next;
//    }
//    return 0;
// }

VertexNode *getChildVertices(nodeGraph *graphRoot, int node)
{
   if (graphRoot == NULL || graphRoot->vertices == NULL)
      return NULL;

   EdgeNode *initialNodeEdge = graphRoot->edges;
   VertexNode *childVertices = NULL;

   while (initialNodeEdge != NULL)
   {
      // Si el arco parte del nodo, insertamos el vertice destino
      if (initialNodeEdge->from == node)
      {
         VertexNode *originalVertex = graphRoot->vertices;
         while (originalVertex != NULL && originalVertex->value != initialNodeEdge->to)
         {
            originalVertex = originalVertex->next;
         }

         // Insertamos
         if (originalVertex != NULL)
         {
            VertexNode *newChild = (VertexNode *)malloc(sizeof(VertexNode));
            newChild->value = originalVertex->value;
            newChild->marked = originalVertex->marked;
            newChild->next = NULL;

            if (childVertices == NULL)
            {
               childVertices = newChild;
            }
            else
            {
               VertexNode *current = childVertices;
               while (current->next != NULL)
               {
                  current = current->next;
               }
               current->next = newChild;
            }
         }
      }

      initialNodeEdge = initialNodeEdge->next;
   }

   return childVertices;
}
