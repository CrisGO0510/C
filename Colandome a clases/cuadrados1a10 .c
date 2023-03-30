#include <stdio.h>

void imp(int n)
{
    if (n > 10)
    {
        // Para la función
    }
    else
    {
        printf("%i² = %i\n",n ,n * n);
        imp(n + 1);
    }
}

int main()
{
    imp(1);
}