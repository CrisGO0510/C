// Esta vez haremos un fibonacci como el problema 11, pero con recursividad

int main()
{
    /* Declaramos una variable que usaremos para pedirle el usuario cuantos
    numeros de la sucesión quiere ver*/
    int cantidad = 0;

    // Le pedimos al usuario la cantidad de datos que desea ver
    printf("Ingrese la cantidad de numeros que desea ver en la sucesión de fibonacci:\n");
    scanf("%i",&cantidad);

    // Ejecutamos la función "fibo" con la cantidad establecida por el usuario
    fibo(1, 0, 0, cantidad);
}

/*
x ^ y: Son las variables que se estarán sumando para hacer el fibo
aux: Será una variable de apoyo que servirá para almacenar el dato de X de
    manera temporal, para luego reasignarsela a Y
cont: Será una variable contadora, es decir la que determinará cuantas
    veces se repetirá el fibo, ó cuantos numeros imprimirá
*/
int fibo(int x, int y, int aux, int cont)
{
    if (cont > 1)
    {
        // Si la condición es cierta ejecuturá lo siguiente:

        // Imprimimos el valor de X
        printf("%i, ", x);
        // Asignamos de manera temporal la variable X en la variable aux
        aux = x;
        // Asignamos a x la suma de x ^ y
        x = x + y;
        // Recuperamos el valor anterior de X con el aux y lo asignamos a Y
        y = aux;
        // Volvemos a llamar la función pero restandole 1 a la cantidad (CONT)
        fibo(x, y, aux, cont - 1);
    }
    else
    {
        // Cuando la condición sea imprimimos el valor de X
        printf("%i.\n Fin Del Programa ", x);

        /* NOTA: Este no erá necesario para la función pero queria
        darle un comentario cuando finalizara ademas de poner un
        punto en vez de una coma*/
    }
}