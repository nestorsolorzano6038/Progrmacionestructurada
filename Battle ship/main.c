#include <stdio.h>

///Batalla naval///
int main(){
///Variables///
    int n=4;
    int m=4;

    int jugador1[n][m];
    int jugador2[n][m];


    int ax1,ay1,ax21,ay21,ax22,ay22; //variables para guardar coordenadas del JUGADOR 1
    int bx1,by1,bx21,by21,bx22,by22; //variables para guardar coordenadas del JUGADOR 2

///Jugador1 creación de tablero///

    for(int i=0; i<n; i++){
            jugador1[i][0]=i;
        }
    for(int i=0; i<m; i++){
            jugador1[0][i]=i;
        }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
        jugador1[i][j]= 79;
        }
    }
   printf("Tablero Jugador 1 \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", jugador1[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", jugador1[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

///Jugador2 creación de tablero///

    for(int i=0; i<n; i++){
            jugador2[i][0]=i;
        }
    for(int i=0; i<m; i++){
            jugador2[0][i]=i;
        }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
        jugador2[i][j]= 79;
        }
    }
   printf("Tablero Jugador 2 \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", jugador2[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", jugador2[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

///Colocar barcos 1///
int si=1; //variable para salir del bucle while cuando la coordenada es correcta
    //Jugador 1
    //Coordenada 1:
    while(si==1){
        printf("\n\nJUGADOR 1\nIngresa las coordenadas del bote 1 (x,y):\n");
        scanf("%d %d",&ax1,&ay1);

        if ((ax1>3 || ax1<1)||(ay1>3||ay1<1)){
                printf("\nERROR: fuera del rango");
        }
        else{ //Si no se repite la coordenada sale del bucle
            jugador1[ax1][ay1]=254;
            si=0;
        }
    }
    printf("Tablero Jugador 1 \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", jugador1[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", jugador1[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    //Jugador 2:
    si=1;
    while(si==1){
        printf("\n\nJUGADOR 2\nIngresa las coordenadas del bote 1 (x,y):\n");
        scanf("%d %d",&bx1,&by1);

        if ((bx1>3 || bx1<1)||(by1>3||by1<1)){
                printf("\nERROR: fuera del rango");
        }
        else{ //Si no se repite la coordenada sale del bucle
            jugador2[bx1][by1]=254;
            si=0;
        }
    }
    printf("Tablero Jugador 2 \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", jugador2[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", jugador2[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

///Colocar barcos 2///
 si=1; //variable para salir del bucle while cuando la coordenada es correcta
    //Jugador 1
    //Coordenada 1:
    while(si==1){
        printf("\n\nJUGADOR 1\nIngresa las coordenadas del bote 2 (x1,y1):\n");
        scanf("%d %d",&ax21,&ay21);

         if ((ax21>3 || ax21<1)||(ay21>3||ay21<1)){
                printf("\nERROR: fuera del rango");
        }
        else if(ax1==ax21 && ay1==ay21){ //Validación de coordenada repetida
            printf("\nERROR: invadiste el lugar del Barco 1");
        }
        else{ //Si no se repite la coordenada sale del bucle
            jugador1[ax21][ay21]=254;
            si=0;
        }
    }
    //Coordenada 2:
    si=2; //reutilización de variable para entrar al bucle 2
    while(si==2){
        printf("\nIngresa las coordenadas del bote 2 (x2,y2):\n");
        scanf("%d %d",&ax22,&ay22);

        if ((ax22>3 || ax22<1)||(ay22>3||ay22<1)){
                printf("\nERROR: fuera del rango");
        }
        else if((ax1==ax22 && ay1==ay22)||(ax21==ax22 && ay21==ay22)){ //validación de coordenada repetida
            printf("\nERROR: coordenada repetida");
        }
        else if((ax22>=ax21+2 || ax22<=ax21-2)||(ay22>=ay21+2 || ay22<=ay21-2)){ //Validacion solo permitir cordenadas adyacentes
            printf("\nERROR: coordenada invalida. El barco debe estar en la misma fila o columna");
        }
        else if(ax21==ay22 && ay21==ax22){
            printf("\nERROR: coordenada invalida. El barco debe estar en la misma fila o columna");
        }
        else {
            jugador1[ax22][ay22]=254;
            si=3;
        }
    }

    //Coloca '1' en la ubicación del barco 2
    jugador1[ax21][ay21]=254;
    jugador1[ax22][ay22]=254;

    //Imprime la matriz completa del Jugador 1
    printf("\n PARTIDA JUGADOR 1\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", jugador1[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", jugador1[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    jugador1[ax1][ay1]=254;
    jugador1[ax21][ay21]=254;
    jugador1[ax22][ay22]=254;

    //Ya que completemos la validación del barco 2 para el jugador 1, copiamos y pegamos para el jugador 2.

    si=1; //variable para salir del bucle while cuando la coordenada es correcta
    //Jugador 2
    //Coordenada 1:
    while(si==1){
        printf("\n\nJUGADOR 2\nIngresa las coordenadas del bote 2 (x1,y1):\n");
        scanf("%d %d",&bx21,&by21);

         if ((bx21>3 || bx21<1)||(by21>3||by21<1)){
                printf("\nERROR: fuera del rango");
        }
        else if(bx1==bx21 && by1==by21){ //Validación de coordenada repetida
            printf("\nERROR: invadiste el lugar del Barco 1");
        }
        else{ //Si no se repite la coordenada sale del bucle
            jugador2[bx21][by21]=254;
            si=0;
        }
    }
    //Coordenada 2:
    si=2; //reutilización de variable para entrar al bucle 2
    while(si==2){
        printf("\nIngresa las coordenadas del bote 2 (x2,y2):\n");
        scanf("%d %d",&bx22,&by22);

        if ((bx22>3 || bx22<1)||(by22>3||by22<1)){
                printf("\nERROR: fuera del rango");
        }
        else if((bx1==bx22 && by1==by22)||(bx21==bx22 && by21==by22)){ //validación de coordenada repetida
            printf("\nERROR: coordenada repetida");
        }
        else if((bx22>=bx21+2 || bx22<=bx21-2)||(by22>=by21+2 || by22<=by21-2)){ //Validacion solo permitir cordenadas adyacentes
            printf("\nERROR: coordenada invalida. El barco debe estar en la misma fila o columna");
        }
        else if(bx21==by22 && by21==bx22){
            printf("\nERROR: coordenada invalida. El barco debe estar en la misma fila o columna");
        }
        else {
            jugador2[bx22][by22]=254;
            si=3;
        }
    }

    //Coloca '1' en la ubicación del barco 2
    jugador2[bx21][by21]=254;
    jugador2[bx22][by22]=254;

    //Imprime la matriz completa del Jugador 2
    printf("\n PARTIDA JUGADOR 2\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", jugador2[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", jugador2[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    jugador2[bx1][by1]=254;
    jugador2[bx21][by21]=254;
    jugador2[bx22][by22]=254;

//Mecanismos de ataque
//variables para los turnos, definir el ganador y para la matriz nueva
    int turno = 1;
    int ataques1[n][m];
    int ataques2[n][m];
    int ab0, ba0;
    int victoria1 = 0;
    int victoria2 = 0;

     for(int i=0; i<n; i++){
            ataques1[i][0]=i;
        }
    for(int i=0; i<m; i++){
            ataques1[0][i]=i;
        }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
        ataques1[i][j]= 79;
        }
    }

    for(int i=0; i<n; i++){
            ataques2[i][0]=i;
        }
    for(int i=0; i<m; i++){
            ataques2[0][i]=i;
        }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
        ataques2[i][j]= 79;
        }
    }

    while ((victoria1<3)&&(victoria2<3)){

    if(turno==1){
//imprime el tablero del jugador 1 y se actualiza con cada ciclo dependiendo los valores que ingrese el usuario
    printf("\n\nfase de ataque\nTABLERO DE ATAQUES JUGADOR %d\n", turno);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", ataques1[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", ataques1[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    printf("Turno del jugador %d", turno);
    printf("\nA que coordenada quieres atacar\n");
    scanf("%d %d",&ab0,&ba0);

//validaciones por si los numeros se salen del rango o repite una cordenada
        if ((ab0>3 || ab0<1)||(ba0>3||ba0<1)){
                printf("\nERROR: fuera del rango");
            continue;
        }
        else if (ataques1[ab0][ba0]==47 || ataques1[ab0][ba0]==88){
            printf("\nERROR: coordenada repetida");
            continue;
        }

//compara las cordenadas con las del jugador 2 y determina si dio a un barco o al agua
            else if((ab0==bx22 && ba0==by22)||(ab0==bx21 && ba0==by21)||(ab0==bx1 && ba0==by1)){

            ataques1[ab0][ba0]=88;
            victoria1 = victoria1 + 1;
        }
            else{
            ataques1[ab0][ba0]=47;
            }

//imprime el tablero maracndo si dio a un barco o no, y cada ciclo lo actualiza con los nuevos disparos
    printf("\n\nTABLERO DE ATAQUES JUGADOR %d\n", turno);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", ataques1[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", ataques1[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    turno = (turno == 1) ? 2 : 1; //cuando el turno es 1 cambia a 2 y si es 2 cambia 1
    }

    else if (turno==2){
    printf("\n\nfase de ataque\nTABLERO DE ATAQUES JUGADOR %d\n", turno);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", ataques2[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", ataques2[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    printf("Turno del jugador %d", turno);
    printf("\nA que coordenada quieres atacar\n");
    scanf("%d %d",&ab0,&ba0);

        if ((ab0>3 || ab0<1)||(ba0>3||ba0<1)){
                printf("\nERROR: fuera del rango");
            continue;
        }
        else if (ataques2[ab0][ba0]==47 || ataques2[ab0][ba0]==88){
            printf("\nERROR: coordenada repetida");
            continue;
        }

            else if((ab0==ax22 && ba0==ay22)||(ab0==ax21 && ba0==ay21)||(ab0==ax1 && ba0==ay1)){

            ataques2[ab0][ba0]=88;
            victoria2 = victoria2 + 1;
        }
            else{
            ataques2[ab0][ba0]=47;
            }

    printf("\n\nTABLERO DE ATAQUES JUGADOR %d\n", turno);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                        if(i==0||j==0){
                printf("%d ", ataques2[i][j]);
                printf(" ");
                printf(" ");
            }
            else{
               printf("%c ", ataques2[i][j]);
               printf(" ");
               printf(" ");
            }
        }
        printf("\n\n");
        }
        printf("\n");

    turno = (turno == 1) ? 2 : 1;
    }
}

//imprime el ganador
    if(victoria1==3){
    printf("\nGANADOR JUGADOR 1\n");
    }
        else{
        printf("\nGANADOR JUGADOR 2\n");
        }

return 0;
}


