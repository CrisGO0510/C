#include <stdio.h>

int imp(int n)
{
    if (n == 1)
    {
        // Para la función
        printf("%i = ", n);
        return 1;
    }
    else
    {
        printf("%i + ", n);
        return n + imp(n - 1);
    }
}

int main()
{
    printf("%i", imp(10));
}