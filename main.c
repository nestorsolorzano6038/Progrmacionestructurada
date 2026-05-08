#include <stdio.h>
#include <stdlib.h>

int f_double(int a){
    a=a*2;
    printf("\nEl doble es: %d", a);
return 0;
}

int f_triple(int *a){
    *a=*a*3;
    printf("\nEl triple es: %d", *a);
return 0;
}

int main()
{
    int a;
    int answer=1;
    int x=5;
    int *p;

    p=&x;

    while(answer==1){
    printf("\nDame un NO. del 1 al 100\n");
    scanf("%d", &a);

    if (a<1||a>100){
        printf("numero no valido\n");
    }
    else{
        answer=2;
        f_double(a);
        f_triple(&a);

    }
}
    printf("\nAhora <a> vale = %d\n", a);

        printf("\nX = %d\n", x);
        printf("p = %d\n", p);
        printf("*p = %d\n", *p);

return 0;
}
