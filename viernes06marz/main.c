#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N=4;
    float temp[N];


    for(int i = 0; i < N; i++){
        printf("Ingresa la temperatura %d: ", i+1);
        scanf("%f", &temp[i]);
    }

    for(int i = 0; i < N; i++){
        printf("%f\n", temp[i]);
    }

    return 0;
}
