#include <stdio.h>
#include <stdlib.h>

int main(){

    int x;
    int suma = 0;

    //lee el primer numero
    printf("introduce numeros para sumar (0 termina la suma): \n");
    scanf("%d", &x);

        //Mientras no sea 0 el while seguira acumulando numeros para sumar
        while(x!=0){
            suma+=x;
            scanf("%d", &x);
    }
    //Muestra el resultado
    printf("La suma es: %d\n", suma);

return 0;
}
