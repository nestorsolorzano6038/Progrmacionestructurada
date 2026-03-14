#include <stdio.h>
#include <string.h>

int main(){
    char Alumno1[32]="Nestor";
    char Alumno2[32];

    //sacnf solo guarda una palabra
    printf("Cual es tu nombre? ");
        scanf("%s",Alumno2); //%s se usa en strings
    printf("(scanf) Tu nombre es: %s", Alumno2);
while(getchar() != '\n');

    //fgets
    printf("\n\nCual es tu nombre y apellido?\n");
        fgets(Alumno2,sizeof(Alumno2),stdin); //fgets( DondeLoGuardo, sizeof(Tamaño), DondeLeo)
    printf("(fgets) Tu nombre es: %s", Alumno2);

    //lista bidimensional
    char lista [5][32]; //[filas][columnas]

    printf("\n\nLISTA\n");
    for(int i = 0; i < 3; i++) { //Pide 3 nombres
        printf("Cual es tu nombre? ");
        fgets(lista[i],sizeof(lista[i]),stdin); //lo guarda en la lista, donde i es la fila
    }
    printf("\n");

    for(int i = 0; i < 3; i++) { //imprime las primeras 3 filas de la lista
        printf("Tu nombre es: %s", lista[i]);
    }

    //strlen
    printf("\nLONGITUD\n");
    int longitud;

    for(int i = 0; i < 3; i++) { //imprime las primeras 3 filas de la lista
        longitud=strlen(lista[i]); //Strlen cuenta la longitud del string y despues la imprime
        printf("\nLa longitud de %s es de %d", lista[i],longitud-1);
    }

    //strcpy
    printf("\n\nCOPIA DE LISTA\n");
    char copia[32];

    for(int i = 0; i < 3; i++) { //imprime las primeras 3 filas de la lista
        strcpy(copia,lista[i]); //sirve para copiar un string y guardarlo en otra variable
        printf("%s", copia);
    }
    printf("\n");

    //strcat
    printf("\nCONCATENACION\n");
    char nombre[32];
    char apellido[32];

    printf("Cual es tu nombre? ");
    scanf("%s",nombre);
    printf("Cual es tu apellido? ");
    scanf("%s",apellido);

    strcat(nombre, " "); //une strings  al final del primero
    strcat(nombre, apellido);
    printf("Tu nombre completo es: %s", nombre);

    //strcmp
    printf("\n\nCOMPARACION\n");

    char nombre2[32];

    printf("Cual es tu nombre? ");
    scanf("%s",nombre);
    printf("Confirma tu nombre ");
    scanf("%s",nombre2);

    strcmp(nombre, nombre2); //sirve para comparar strings y devolver si son iguales o diferentes
    if(strcmp(nombre,nombre2) == 0){
        printf("Los nombres SI coinciden");
    }
    else if(strcmp(nombre,nombre2)!=0){
        printf("Los nombres NO coinciden");
    }
    //no puedes comparar strings con `==` en C

    return 0;
}
