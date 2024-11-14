#include "TADgrafo.h"

int main()
{
  Grafo g = crearGrafo();

  // Insertar vertices
  insertarVertice(g, 1);
  insertarVertice(g, 2);
  insertarVertice(g, 3);
  insertarVertice(g, 4);
  insertarVertice(g, 5);
  insertarVertice(g, 6);

  // Insertar arcos
  insertarArco(g, 1, 2, 1);


  return 0;
}
