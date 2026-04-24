#include <stdio.h>


void mostrar(int v[3][3]){
    int i, j;

    printf("\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void capturar(int m[3][3]){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Elemento fila %d, columna %d:\n", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
}

int diagonal(int z[3][3]) {
    int suma = 0;

    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", z[i][i]);
        suma += z[i][i];
    }

    printf("\nSuma de la diagonal: %d\n", suma);
}


int main(){

    int mota[3][3];
    int suma;

    capturar(mota);
    mostrar(mota);
    suma=diagonal(mota);

    printf("\nPPS FOREVER\n");

FILE *archivo;
    archivo=fopen("matriz.txt", "a");

        fprintf(archivo, "El archivo contiene:\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                fprintf(archivo, " %d", mota[i][j]);
            }
        fprintf(archivo, "\n");
        }

    fprintf(archivo, "\nSuma de la diagonal: %d\n", suma);
    fprintf(archivo, "\nPPS FOREVER\n");
    fclose(archivo);

return 0;
}
