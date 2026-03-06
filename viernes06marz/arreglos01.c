#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp1, temp2;
    float temp[24];
    int dummy;

    printf("Dirrecion de mem de 2 flotantes:\n%i\n%i\n", &temp1, &temp2);
    printf("Direecion de temp[24]: %i\n", temp);
    printf("Direecion de temp[24]: %i\n", &temp[24]);
    printf("Dirrecion de dummy: %i\n", &dummy);

    return 0;
}

