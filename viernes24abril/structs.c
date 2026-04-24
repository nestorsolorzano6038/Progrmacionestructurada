#include <stdio.h>
#include <stdlib.h>

/*
struct clase {
    char nombre[20];
    float promedio;
    int edad;
};

int main() {
    struct clase alumno;

    printf("Nombre: ");
    fgets(alumno.nombre, 20, stdin);

    printf("Edad: ");
    scanf("%d", &alumno.edad);
    printf("Promedio: ");
    scanf("%f", &alumno.promedio);

    printf("\nDatos del alumno\n");
    printf("Nombre: %s", alumno.nombre);
    printf("Edad: %d\n", alumno.edad);
    printf("Promedio: %.2f\n", alumno.promedio);

    return 0;
}
*/

struct alumno {
    char nombre[20];
    int edad;
    float promedio;
    char carrera[40];
};

int main(){
    int n;

    printf("Cuántos alumnos tiene la clase?\n");
    scanf("%d", &n);
    getchar();

    struct alumno clase[n];

for(int i=0; i<n; i++){
printf("\nDatos del alumno\n");
    printf("Nombre: ");
    fgets(clase[i].nombre, 20, stdin);
    printf("Edad: ");
    scanf("%d", &clase[i].edad);
    printf("Promedio: ");
    scanf("%f", &clase[i].promedio);
          getchar();
    printf("Carrera: ");
    fgets(clase[i].carrera, 40, stdin);
}
printf("\nLista de la clase\n");
    for(int i=0; i<n; i++){
    printf("\nALUMNO %d\n", i + 1);
    printf("Nombre: %s", clase[i].nombre);
    printf("Edad: %d\n", clase[i].edad);
    printf("Promedio: %.2f\n", clase[i].promedio);
     printf("carrera: %s", clase[i].carrera);
    }
    return 0;
}

/*
union dato{
    int entero;
    float decimal;
};

int main(){
    union dato x;

    x.entero=10
    printf("%d\n", x.entero)
}
*/
