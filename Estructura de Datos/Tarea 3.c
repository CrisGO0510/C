#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void clear()
{
  if (system("clear"))
  {
    system("cls");
  }
}

// Structures

typedef struct studentInfo
{
  unsigned int docNumber;
  char name[50];
  char address[75];
  unsigned long int cellphone;
  char status[15];
} studentInfo;

typedef struct studentPerformance
{
  int academicPeriod;
  int semester;
  int numberOfSubjectsTaken;
  float average;
  struct studentPerformance *nextAcademicPeriod;
} studentPerformance;

typedef struct listStudents
{
  unsigned int docNumber;
  studentInfo *studentInfoList;
  studentPerformance *studentPerformanceList;

  struct listStudents *nextStudent;
} listStudents;

// Prototypes
void createUser(listStudents **);
void addNewAcademicPeriod(studentPerformance **);
void defineStudentStatus(listStudents *);
void printStudentInfo(listStudents *, int);
void printStudentPerformance(studentPerformance *);

int main()
{
  clear();
  listStudents *list = NULL;

  int option = 0;

  while (option != 6)
  {
    option = 0;

    printf("\tBienvenido al sistema de gestion de estudiantes\n");
    printf("1. Ingresar un estudiante al sistema\n");
    printf("2. Agregar informacion de un periodo academico\n");
    printf("3. Definir estado de los estudiantes\n");
    printf("4. Mostrar estudiantes en estado FUERA\n");
    printf("5. Mostrar toda la informacion de los estudiantes\n");
    printf("6. Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%i", &option);

    if (option == 1)
    {
      createUser(&list);
    }

    if (option == 2)
    {
      unsigned int number = 0;

      printf("Ingrese el numero documento del estudiante: ");
      scanf("%i", &number);

      listStudents *current = list;

      int i = 0;

      while (current != NULL)
      {
        if (current->docNumber == number)
        {
          i++;
          addNewAcademicPeriod(&(current)->studentPerformanceList);
        }
        current = current->nextStudent;
      }

      printf("%s\n", i ? "Se ha agregado correctamente el periodo academico" : "No se encontro el usuario\n");
    }

    if (option == 3)
    {
      defineStudentStatus(list);
    }

    if (option == 4)
    {
      printStudentInfo(list, 0);
    }

    if (option == 5)
    {
      printStudentInfo(list, 1);
    }

    if (option == 6)
    {
      printf("Saliendo del programa.\n");
    }

    printf("Presione enter para continuar\n");
    getchar();
    getchar();
    clear();
  }

  printf("Hasta luego.\n");

  return 0;
}

void createUser(listStudents **list)
{
  listStudents *tempList = (listStudents *)malloc(sizeof(list));
  tempList->nextStudent = NULL;

  studentInfo *user = (studentInfo *)malloc(sizeof(studentInfo));
  studentPerformance *userPerformance = NULL;

  int docNumber = 0;

  printf("Ingrese el documento del usuario: ");
  scanf("%i", &docNumber);

  user->docNumber = docNumber;

  printf("Ingrese el nombre del usuario: ");
  scanf("%s", user->name);
  getchar();

  printf("Ingrese la direccion del usuario: ");
  scanf("%s", user->address);
  getchar();

  printf("Ingrese el numero de celular del usuario: ");
  scanf("%li", &user->cellphone);

  strcpy(user->status, "NO VALIDO");

  if (!user->docNumber || !strlen(user->address) || !strlen(user->name) || !user->cellphone)
  {
    clear();
    printf("Error: No se permiten datos vacios.\n");
    free(tempList);
    free(user);
    free(userPerformance);
    createUser(list);
    return;
  }

  addNewAcademicPeriod(&userPerformance);
  tempList->docNumber = docNumber;
  tempList->studentPerformanceList = userPerformance;
  tempList->studentInfoList = user;
  tempList->nextStudent = NULL;

  if (*list == NULL)
  {
    *list = tempList;
    return;
  }

  listStudents *current = *list;
  while (current->nextStudent != NULL)
  {
    current = current->nextStudent;
  }

  current->nextStudent = tempList;

  printf("\nUsuario agregado con exito.\n");
}

void addNewAcademicPeriod(studentPerformance **list)
{

  studentPerformance *tempList = (studentPerformance *)malloc(sizeof(studentPerformance));
  tempList->nextAcademicPeriod = NULL;

  printf("Ingrese el periodo academico (202301): ");
  scanf("%i", &tempList->academicPeriod);

  printf("Ingrese el semestre: ");
  scanf("%i", &tempList->semester);

  printf("Ingrese el # de materias cursadas: ");
  scanf("%i", &tempList->numberOfSubjectsTaken);

  printf("ingrese el promedio del estudiante: ");
  scanf("%f", &tempList->average);

  if (!tempList->academicPeriod || !tempList->semester || !tempList->numberOfSubjectsTaken)
  {
    clear();
    printf("Error: No se permiten datos vacios.\n");
    free(tempList);
    addNewAcademicPeriod(list);
    return;
  }

  if (*list == NULL)
  {
    *list = tempList;
    return;
  }

  studentPerformance *current = *list;

  while (current->nextAcademicPeriod != NULL)
  {
    current = current->nextAcademicPeriod;
  }

  current->nextAcademicPeriod = tempList;

  int option = 0;
  printf("Desea agregar otro periodo academico? (1. Si / 2. No): ");
  scanf("%i", &option);

  if (option == 1)
  {
    addNewAcademicPeriod(list);
    return;
  }

  printf("\nPeriodo academico agregado con exito.\n");
}

void defineStudentStatus(listStudents *list)
{
  float subAverage = 0;
  int count = 0;

  if (list == NULL)
  {
    clear();
    printf("Error: No se encontraron datos para definir estatus.\n");
    return;
  }

  studentPerformance *tempStudentPerformanceList = list->studentPerformanceList;

  while (tempStudentPerformanceList != NULL)
  {
    count++;
    subAverage += tempStudentPerformanceList->average;

    tempStudentPerformanceList = tempStudentPerformanceList->nextAcademicPeriod;
  }

  float average = subAverage / count;

  if (average >= 3.0)
  {
    strcpy(list->studentInfoList->status, "NORMAL");
  }
  else if (average >= 2.5 && average < 3.0)
  {
    strcpy(list->studentInfoList->status, "PRUEBA");
  }
  else if (average < 2.5)
  {
    strcpy(list->studentInfoList->status, "FUERA");
  }

  printf("Estado actualizado con exito.\n");
}

void printStudentInfo(listStudents *list, int allStudent)
{
  if (list == NULL)
  {
    clear();
    printf("Error: No se encontraron datos para imprimir.\n");
  }

  while (list != NULL)
  {
    int statusValue = strcmp(list->studentInfoList->status, "FUERA") == 0;

    if (allStudent || statusValue)
    {
      clear();
      printf("Numero de documento: %u\n", list->studentInfoList->docNumber);
      printf("Nombre: %s\n", list->studentInfoList->name);
      printf("Direccion: %s\n", list->studentInfoList->address);
      printf("Numero de celular: %lu\n", list->studentInfoList->cellphone);
      printf("Estado: %s\n\n", list->studentInfoList->status);

      printf("Periodos academicos de %s:\n", list->studentInfoList->name);
      printStudentPerformance(list->studentPerformanceList);
      printf("Presione enter para ver al siguiente estudiante\n");
      getchar();
      getchar();
    }

    list = list->nextStudent;
  }

  printf("Fin de los resultados%s\n", allStudent ? "." : " con el estado \"FUERA\".");
}

void printStudentPerformance(studentPerformance *list)
{
  if (list == NULL)
  {
    clear();
    printf("Error: No se encontraron periodos academicos.\n");
    return;
  }

  studentPerformance *tempList = list;

  while (tempList != NULL)
  {
    printf("Periodo Academico: %i\n", tempList->academicPeriod);
    printf("Semestre: %i\n", tempList->semester);
    printf("Numero de Materias Tomadas: %i\n", tempList->numberOfSubjectsTaken);
    printf("Promedio: %.2f\n\n", tempList->average);

    tempList = tempList->nextAcademicPeriod;
  }
}