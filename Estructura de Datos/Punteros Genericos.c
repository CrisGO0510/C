#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void clear()
{
  // if (system("cls"))
  // {
  //   system("clear");
  // }
}

typedef struct ageComparationStruct
{
  int greater;
  int less;
} ageComparationStruct;

typedef struct peopleInfo
{
  char typeID[5];
  int id;
  char name[50];
  int age;
  unsigned long int landline;
  unsigned long int cellphone;
  int isActive;
} peopleInfo;

typedef struct list
{
  peopleInfo *userInfo;
  struct list *nextNode;
} list;

typedef int (*CondicionalFunc)(peopleInfo *, void *);
typedef void (*CRUDFunc)(list *);

void searchUser(list *, CondicionalFunc, CRUDFunc, void *, int);
int getNone(peopleInfo *, void *);
int getAll(peopleInfo *, void *);
int getName(peopleInfo *, void *);
int getNumber(peopleInfo *, void *);
int getId(peopleInfo *, void *);
int getAge(peopleInfo *, void *);
void createUser(list *);
void printUserInfo(list *);
void deleteUser(list *);
void menu(int *, int *, void **, int *);

int main()
{
  list *userList = NULL;
  int funtionalOption = 1;
  int condicionalOption = 1;
  void *targetInfo = NULL;

  int countPeople = 0;

  int (*condicionalArray[6])(peopleInfo *user, void *data) = {getName, getNumber, getAge, getAll, getId, getNone};
  void (*functionalArray[3])(list *head) = {createUser, printUserInfo, deleteUser};

  peopleInfo person;

  strcpy(person.typeID, "ID123");
  person.id = 1;
  strcpy(person.name, "Cris");
  person.age = 30;
  person.landline = 123456789;
  person.cellphone = 1;
  person.isActive = 1;

  list node;
  node.userInfo = &person;
  node.nextNode = NULL;

  userList = &node;

  while (funtionalOption != 4)
  {
    countPeople = 0;
    clear();
    menu(&funtionalOption, &condicionalOption, &targetInfo, &countPeople);

    if (funtionalOption != 4)
      searchUser(userList, condicionalArray[condicionalOption - 1], functionalArray[funtionalOption - 1], targetInfo, countPeople);
    getchar();
    getchar();
  }

  printf("Adios");

  return 0;
}

void menu(int *funtionalOption, int *condicionalOption, void **targetInfo, int *countPeople)
{
  *targetInfo = NULL;

  printf("\tBienvenido al sistema de gestion de usuarios\n");
  printf("1) Ingreso de datos al sistema\n");
  printf("2) Mostrar datos de una persona del sistema\n");
  printf("3) Eliminar una persona del sistema\n");
  printf("4) Salir\n");
  printf("Pulsa una opcion: ");
  scanf("%d", funtionalOption);
  getchar();

  if (*funtionalOption < 1 || *funtionalOption > 4)
  {
    clear();
    printf("Error, opcion no valida\n\n\n");
    menu(funtionalOption, condicionalOption, targetInfo, countPeople);
    return;
  }

  if (*funtionalOption == 4)
    return;

  if (*funtionalOption == 1 || *funtionalOption == 3)
  {
    clear();
    printf("Donde deseas insertear el usuario?\n");
    printf("1) Despues de una persona por ID\n");
    printf("2) Despues de una persona por posicion\n");
    printf("3) De ultimo lugar\n");
    printf("Pulsa una opcion: ");
    scanf("%d", condicionalOption);
    clear();

    if (*condicionalOption == 1 || *condicionalOption == 2)
    {
      printf("ingrese el numero: ");
      scanf("%d", countPeople);
    }

    if (*condicionalOption != 2)
      *condicionalOption = 5;

    if (*condicionalOption == 2)
      *condicionalOption = 6;

    return;
  }

  clear();
  printf("\n\tComo deseas hacer la busqueda?\n");
  printf("1) Buscar por nombre\n");
  printf("2) Buscar por numero de telefono\n");
  printf("3) Buscar por rango de edad\n");
  printf("4) Mostrar todos los usuarios\n");
  printf("Pulsa una opcion: ");
  scanf("%d", condicionalOption);

  if (*condicionalOption < 1 || *condicionalOption > 4)
  {
    clear();
    printf("Error, opcion no valida\n\n\n");
    menu(funtionalOption, condicionalOption, targetInfo, countPeople);
    return;
  }

  if (*condicionalOption == 1)
  {
    char temp[50];
    printf("Ingrese el nombre del usuario: ");
    scanf("%s", temp);

    *targetInfo = (char *)malloc(sizeof(char[50]));

    strcpy(*targetInfo, temp);

    getchar();
  }

  if (*condicionalOption == 2)
  {
    printf("Ingrese el numero de telefono del usuario: ");
    int phoneNumber;
    scanf("%d", &phoneNumber);

    *(int *)targetInfo = phoneNumber;
  }

  if (*condicionalOption == 3)
  {
    *targetInfo = (ageComparationStruct *)malloc(sizeof(ageComparationStruct));

    printf("Ingrese el rango de edad del usuario:\n");

    printf("Ingrese el numero menor: ");
    scanf("%d", &((ageComparationStruct *)(*targetInfo))->less);

    printf("Ingrese el numero mayor: ");
    scanf("%d", &((ageComparationStruct *)(*targetInfo))->greater);
  }

  if (*condicionalOption == 4)
    *targetInfo = (int *)1;
}

int getAll(peopleInfo *user, void *data __attribute__((unused)))
{
  return user->id ? 1 : 0;
}

int getNone(peopleInfo *user __attribute__((unused)), void *data __attribute__((unused)))
{
  return 0;
}

/*
  Funcion que retornara 1 si los 2 nombres son iguales o 0 si no lo son
  @param user el usuario con el que compararan los valores
  @param string2 string ingresado con el usuario para lograr comparar un valor ya existente
*/
int getName(peopleInfo *user, void *string2)
{
  return strcoll(user->name, (char *)string2) == 0;
}

/*
  Funcion que retornara 1 si los 2 numeros son iguales o 0 si no lo son
  @param user el usuario con el que compararan los valores
  @param number valor ingresado con el usuario para lograr comparar un valor ya existente
*/
int getNumber(peopleInfo *user, void *number)
{
  int *cellphone = (int *)user->cellphone;
  return cellphone == number;
}

int getId(peopleInfo *user, void *number)
{
  int *id = (int *)user->id;
  return id == number;
}

/*
  Funcion que retornara 1 si la edad esta en este rango de edad
  @param user el usuario con el que compararan los valores
  @param numberStruct estructura ingresada con el usuario para lograr comparar el rango de edad
*/
int getAge(peopleInfo *user, void *numberStruct)
{
  ageComparationStruct ageComparationStructNumbers = *(ageComparationStruct *)numberStruct;
  return (user->age >= ageComparationStructNumbers.less) && (user->age <= ageComparationStructNumbers.greater);
}

// Funcion para crear un usuario
void createUser(list *listInfo)
{
  peopleInfo *user = (peopleInfo *)malloc(sizeof(peopleInfo));
  list *tempList = (list *)malloc(sizeof(list));

  printf("Ingrese el tipo de documento del usuario: ");
  scanf("%s", user->typeID);
  getchar();

  printf("Ingrese el documento del usuario: ");
  scanf("%i", &user->id);

  printf("Ingrese el nombre del usuario: ");
  scanf("%s", user->name);
  getchar();

  printf("Ingrese la edad del usuario: ");
  scanf("%i", &user->age);

  printf("Ingrese el numero de telefono fijo del usuario: ");
  scanf("%li", &user->landline);

  printf("Ingrese el numero de celular del usuario: ");
  scanf("%li", &user->cellphone);

  user->isActive = 1;

  if (!strlen(user->typeID) || !strlen(user->name) || !user->age || !user->cellphone)
  {
    clear();
    printf("Error: No se permiten datos vacios.\n");
    createUser(listInfo);
    return;
  }

  if (listInfo != NULL)
  {
    tempList->userInfo = user;
    tempList->nextNode = listInfo->nextNode;
    listInfo->nextNode = tempList;
  }

  if (listInfo == NULL)
  {
    listInfo = (list *)malloc(sizeof(list));
    listInfo->userInfo = user;
    listInfo->nextNode = NULL;
  }

  printf("\nUsuario agregado con exito.\n");
}

// Funcion para imprimir la informacion de un usuario
void printUserInfo(list *listInfo)
{
  if (listInfo->userInfo->isActive == 0)
    return;

  peopleInfo *user = listInfo->userInfo;

  printf("%s: %i\n", user->typeID, user->id);
  printf("Nombre: %s\n", user->name);
  printf("Edad: %i\n", user->age);
  printf("Telefono fijo: %li\n", user->landline);
  printf("Telefono celular: %li\n\n\n", user->cellphone);

  sleep(1);
}

void deleteUser(list *head)
{
  if (head == NULL)
  {
    printf("La lista está vacía.\n");
    return;
  }

  list *temp = head->nextNode;

  if (temp->nextNode == NULL)
  {
    head->nextNode = NULL;
    return;
  }

  head = temp->nextNode;

  free(temp);

  printf("Eliminado completado\n");
}

// Funcion que realiza las busquedas y ejecuta las funcionalidades
void searchUser(list *head, CondicionalFunc condicion, CRUDFunc functionality, void *data, int countPositions)
{
  list *currentList = head;
  list *lastValidNode = NULL;
  int i = 0;

  clear();

  while (currentList != NULL)
  {
    i++;
    printf("Posicion %i\n", i);

    if (countPositions == i)
    {
      functionality(currentList);
      return;
    }

    if (condicion(currentList->userInfo, data))
      functionality(currentList);

    lastValidNode = currentList;
    currentList = currentList->nextNode;
  }

  if (data == NULL)
  {
    functionality(lastValidNode);
    return;
  }

  printf("Presione enter para continuar\n");
  getchar();
}
