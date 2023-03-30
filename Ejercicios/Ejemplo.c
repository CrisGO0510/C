#include <stdio.h>
#include <math.h>

int main()
{
    printf("La serie es: %i", serie(3));
}

int serie(int a)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return serie(a - 1) + pow(2, a);
    }
}