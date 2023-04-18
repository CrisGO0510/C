#include <stdio.h>

int main(){
    char cadena[100];
    FILE *archivo;
    
    printf("Ingresa una cadena de caracteres: ");
    scanf("%s", cadena);
    
    archivo = fopen("original.txt", "w");
    
    if(archivo != NULL){
        fputs(cadena, archivo);
        fclose(archivo);
        
        printf("La cadena ingresada se ha guardado exitosamente en el archivo original.txt\n");
    }
    else{
        printf("Error al crear el archivo\n");
    }

    return 0;
}
