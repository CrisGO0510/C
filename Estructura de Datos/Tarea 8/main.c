#include <stdio.h>

#include "abb.h"
#include "avl.h"
#include "rbt.h"

int main()
{
  RBT *root = NULL;

  insertRBT(&root, 10);
  insertRBT(&root, 8);
  insertRBT(&root, 15);
  insertRBT(&root, 18);
  insertRBT(&root, 14);
  insertRBT(&root, 20);
  insertRBT(&root, 3);
  insertRBT(&root, 4);
  insertRBT(&root, 2);
  insertRBT(&root, 9);
  insertRBT(&root, 20);
  insertRBT(&root, 25);
  insertRBT(&root, 7);
  insertRBT(&root, 16);
  insertRBT(&root, 29);
  insertRBT(&root, 28);
  insertRBT(&root, 26);

  printf("Pasos realizados: %d\n", searchRBT(root, 26));

  return 0;
}
