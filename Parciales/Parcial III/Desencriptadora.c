#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mostrartodo();
void encriptapalabra();
void encriptadesplaza();

int main()
{

    // encriptadesplaza();
    encriptapalabra();
    mostrartodo();

    return 0;
}

void mostrartodo()
{
    unsigned char valor = 0;
    FILE *archivo = NULL;
    archivo = fopen("F_palabraclaveR.txt", "r");
    if (archivo == NULL)
    {
        printf("\nError en la apertura del archivo...\n");
        printf("\n\n\n\tPresione enter para regresar al menu principal...\n");
        getchar();
    }
    else
    {
        printf("\n\tContenido visual del archivo original.txt \n");
        printf("---------------------------------------------------------------------------------------------------------------\n");
        while (!feof(archivo))
        {
            valor = fgetc(archivo);
            printf("%i, ", valor);
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
        // printf("\n\n\n\tPresione enter para regresar al menu principal...\n");
        // getchar();
    }
    fclose(archivo);
}

void encriptapalabra()
{
    // char p_clave[256] = "";
    char p_clave[256] = "++++++++++z+y+sS+++cv+u+tTr+++qP k";
    int esta = 0;
    int i = 0, j = 0, nbyte = 0;
    char valor = 0;
    FILE *desplazado = NULL;
    desplazado = fopen("F_desplazado", "r");
    FILE *apc = NULL;
    apc = fopen("F_palabraclaveR.txt", "w");
    if (apc == NULL || desplazado == NULL)
    {
        printf("\n Al abrir algun archivo se presentaron problemas ");
        getchar();
    }
    else
    {
        while (!feof(desplazado))
        {
            valor = fgetc(desplazado);
            nbyte = nbyte + 1;
            esta = 0;
            j = 0;
            for (i = 0; p_clave[i] != '\0' && esta == 0; i = i + 1)
            {
                if (i == valor)
                {
                    esta = 1;
                    j = i;
                }
            }
            if (esta == 1)
                fputc(p_clave[j], apc);
            else
                fputc(valor, apc);
        }
        printf("\nTamaño archivo desplazado y encriptado x PC %li bytes", ftell(apc));
        fclose(apc);
        fclose(desplazado);
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
    }
    return;
}

void encriptadesplaza()
{
    int vd = 0;
    char valor = 0;
    FILE *archivo = fopen("confidencial08.txt", "r");
    FILE *desplazado = fopen("F_desplazado", "w");
    if (archivo == NULL || desplazado == NULL)
    {
        printf("\n Al abrir original.txt o crear el archivo F_desplazado, se presentaron problemas ");
        getchar();
    }
    else
    {
        printf("\nEntre valor a desplazar: ");
        scanf("%i", &vd);
        vd = 256 - vd;

        while (!feof(archivo))
        {
            valor = fgetc(archivo);
            valor = valor + vd;
            fputc(valor, desplazado);
        }
    }
    fclose(archivo);
    fclose(desplazado);
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    return;
}