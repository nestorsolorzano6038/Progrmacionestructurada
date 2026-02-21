#include<stdio.h>


void promedios(){

float suma=0;
float x;
int calificaciones;

    printf("\nCuantas calificaciones quieres ingresar: \n");
    scanf("%d", &calificaciones);

    for(int i=0; i<calificaciones; i++){
        do{
            printf("ingresa tu nota (0-100): \n");
            scanf("%f", &x);
                if(x<0||x>100){
                printf("Te digo que tus notas deben ser del 0 al 100\nVuelve a ingresa tu nota\n\n");
                }
        }

            while (x<0||x>100);

            suma+=x;

    }

            if(calificaciones>0){
                printf("Tu promedio es: %.2f\n\n", suma/calificaciones);
            }
            else{
                printf("No ingresaste ningun numero.\n\n");
            }
}

int main(){

int opcion;

    do{
        printf("1. Sacar promedio\n");
        printf("2. Salir\n");
        scanf("%d", &opcion);

        if(opcion==1)
            promedios();

        }
        while(opcion != 2);

printf("\nfin del programa");

return 0;
}
