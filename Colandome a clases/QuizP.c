/*
    Quiz programación II

    Haremos un programa que saque el promedio general de 3 materias y cual será el
    promedio que obtendrá en cada una de ellas. Se evaluará de la siguiente forma:

    - Matematicas: 90% Examen, 10% el promedio de tareas (3 tareas)
    - Fisica: 80% Examen, 20% el promedio de tareas (2 tareas)
    - Quimica: 85% Examen, 15% el promedio de tareas (3 tareas)

    Presentado a: Ing Luis Eduardo Muñoz
    Autor: Ing(c) Cristhian Giraldo Orozco
*/

#include <stdio.h>

float mate(float, float, float, float);
float fisica(float, float, float);
float qui(float, float, float, float);

int main()
{

    printf("El promedio total de matematicas es: %.1f\n", mate(2.5, 2.4, 3.4, 5.0));
    printf("El promedio total de Fisica es: %.1f\n", fisica(4.5, 3.4, 4.0));
    printf("El promedio total de quimica es: %.1f\n", qui(3.5, 4.6, 2.4, 3.5));

    return 0;
}

/*
    Haremos una función que como parametro reciba las notas de los examenes y tareas
    Esta función retornará el promedio total de matematicas
*/
float mate(float examen, float nota1, float nota2, float nota3)
{

    // Variable que usaremos para guardar el promedio de las notas
    float promedioN = (nota1 + nota2 + nota3) / 3;

    return (examen * 0.9 + promedioN * 0.1);
}

/*
    Haremos una función que como parametro reciba las notas de los examenes y tareas
    Esta función retornará el promedio total de fisica
*/
float fisica(float examen, float nota1, float nota2)
{

    // Variable que usaremos para guardar el promedio de las notas
    float promedioN = (nota1 + nota2) / 2;

    return (examen * 0.8 + promedioN * 0.2);
}

/*
    Haremos una función que como parametro reciba las notas de los examenes y tareas
    Esta función retornará el promedio total de quimica
*/
float qui(float examen, float nota1, float nota2, float nota3)
{

    // Variable que usaremos para guardar el promedio de las notas
    float promedioN = (nota1 + nota2 + nota3) / 3;

    return (examen * 0.85 + promedioN * 0.15);
}