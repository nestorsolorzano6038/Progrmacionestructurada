#include <stdio.h>
#include <stdlib.h>

void cambiar(int x){
    x=100;
}

int suma(int a, int b){
    return a + b;
}

void mostrar(int v[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d", v[i]);
    }
    printf("\n");
}

void matriz(int m[2][3]){
    int i, j;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void punteros(int *x){
    *x=(*x)*2;
}

int main(){

    int n=4;
    int datos[5]={1,2,3,4,5};
    int f=5;
    int resultado;
    int a, b;
    int matraca[2][3]={{1,2,3},{4,5,6}};

    printf("Escribe dos numeros que quieras sumar:\n");
    scanf("%d %d", &a, &b);
    resultado = suma(a,b);
    printf("\nResultado: %d", resultado);

    cambiar(f);
    printf("\n\nEl valor es: %d\n\n", f);

    mostrar(datos,5);

    printf("\n");

    matriz(matraca);

    punteros(&n);
    printf("\n%d\n", n);

    return 0;
}
