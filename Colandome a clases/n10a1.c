#include <stdio.h>

void imp(int n)
{
    if (n == 0)
    {
        // Para la función
    }
    else
    {
        printf("%i\n", n);
        imp(n - 1);
    }
}

int main()
{
    imp(10);
}