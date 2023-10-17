#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen()
{
  if (system("clear"))
  {
    system("cls");
  }
}

typedef struct channelProgramsList
{
  int time;
  char program_name[50];
  int duration;

  struct channelProgramsList *next;
  struct channelProgramsList *previous;
} channelProgramsList;

typedef struct channelList
{
  int channel_id;
  char channel_name[50];
  struct channelProgramsList *programs;

  struct channelList *next;
  struct channelList *previous;
} channelList;

int main()
{
  channelList *list;

  list = (channelList *)malloc(sizeof(channelList));

  return 0;
}

// Función para agregar programas a la lista de programas de un canal
void addProgram(channelProgramsList **head)
{
  int time;
  char program_name[50];
  int duration;

  printf("Enter the program time: ");
  scanf("%d", &time);

  printf("Enter the program duration: ");
  scanf("%d", &duration);

  printf("Enter the program name: ");
  scanf("%s", program_name);
  getchar();

  channelProgramsList *newProgram;

  newProgram = (channelProgramsList *)malloc(sizeof(channelProgramsList));

  newProgram->time = time;
  strcpy(newProgram->program_name, program_name);
  newProgram->duration = duration;

  if (*head == NULL)
  {
    newProgram->next = newProgram;
    newProgram->previous = newProgram;
    *head = newProgram;
  }
  else
  {
    newProgram->next = *head;
    newProgram->previous = (*head)->previous;
    (*head)->previous->next = newProgram;
    (*head)->previous = newProgram;
  }
}

// Función para crear canales
void createChannel(channelList **head)
{
  int channel_id;
  char channel_name[50];

  printf("Enter the channel id: ");
  scanf("%d", &channel_id);

  printf("Enter the channel name: ");
  scanf("%s", channel_name);
  getchar();

  channelList *newChannel;
  newChannel = (channelList *)malloc(sizeof(channelList));

  newChannel->channel_id = channel_id;
  strcpy(newChannel->channel_name, channel_name);

  // Crear la lista de programas

  channelProgramsList *newProgram;
  newProgram = (channelProgramsList *)malloc(sizeof(channelProgramsList));

  createChannel(&newProgram);
  newChannel->programs = newProgram;

  // Enlazamos el nuevo canal a la lista de canales

  if (*head == NULL)
  {
    newChannel->next = newChannel;
    newChannel->previous = newChannel;
    *head = newChannel;
  }
  else
  {
    newChannel->next = *head;
    newChannel->previous = (*head)->previous;
    (*head)->previous->next = newChannel;
    (*head)->previous = newChannel;
  }
}

// Función para consultar la información de un canal
void printInfoChannel(channelList *head)
{
  char channel_name[50];
  int channel_id;
  int option;

  printf("\tComo deseas hacer la busqueda?\n");
  printf("1. Por nombre\n");
  printf("2. Por id\n");
  scanf("%d", &option);

  if (option == 1)
  {
    printf("Ingresa el nombre del canal: ");
    scanf("%s", channel_name);
    getchar();

    channelList *aux = head;

    do
    {
      if (strcmp(aux->channel_name, channel_name) == 0)
      {
        printf("Nombre del canal: %s\n", aux->channel_name);
        printf("Id del canal: %d\n", aux->channel_id);
        printf("Lista de programas: \n");

        channelProgramsList *auxPrograms = aux->programs;

        do
        {
          printf("Nombre del programa: %s\n", auxPrograms->program_name);
          printf("Hora de inicio: %d\n", auxPrograms->time);
          printf("Duración: %d\n", auxPrograms->duration);

          auxPrograms = auxPrograms->next;
        } while (auxPrograms != aux->programs);
      }
      
      aux = aux->next;
    } while (aux != head);
    
  }
}