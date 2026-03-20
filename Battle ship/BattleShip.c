#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

///Batalla naval///

void tablero1(int n, int m, int jugador1[n][m]) { //Tablero 1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0){
                printf("%d   ", jugador1[i][j]);
            }
            else{
                printf("%c   ", jugador1[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("\n");
}

void tablero2(int n, int m, int jugador2[n][m]) { //Tablero 2
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0){
                printf("%d   ", jugador2[i][j]);
            }
            else{
                printf("%c   ", jugador2[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("\n");
}

void tabataques1(int n, int m, int ataques1[n][m]){ //Zona ataque 1
    for(int i = 0; i < n; i++) { //Imprimir tablero 1
        for(int j = 0; j < m; j++) {
            if(i==0||j==0){
                printf("%d   ", ataques1[i][j]);
            }
            else{
                printf("%c   ", ataques1[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("\n");
}

void tabataques2(int n, int m, int ataques2[n][m]){ //Zona ataque 2
    for(int i = 0; i < n; i++) { //Imprimir tablero 1
        for(int j = 0; j < m; j++) {
            if(i==0||j==0){
                printf("%d   ", ataques2[i][j]);
            }
            else{
                printf("%c   ", ataques2[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("\n");
}

void limpiar(){
    Sleep(5000);
    fflush(stdout);  // 1. Limpia el búfer de salida
    system("cls");   // 2. Llama al comando de Windows
}

int main(){

///Variables///

    int n=6, m=n;// Variables generales aplicada al tamaño de las matrices

    int jugador1[n][m];// Tablero del jugador 1
    int jugador2[n][m];// Tablero del jugador 2

    int ax1,ay1,ax21,ay21,ax22,ay22; // Coordenadas de los barcos del jugador 1
    int bx1,by1,bx21,by21,bx22,by22; //Coordenadas de los barcos del jugador 1

    char brc1[15]="Bote";//Tipo de barco 1
    char brc2[15]="Destructor";//Tipo de barco 2

    char players[1][20];//Nombres de jugadores

    int si=1; // Variable para salir de los bucles while cuando la coordenada es correcta

    int turno = 1; // Variable turno
    int ataques1[n][m];
    int ataques2[n][m];  // Matrices de ataque
    int ab0, ba0;
    int victoria1=0, victoria2=0;
    int vav=1;

    int p;//Escoger al ganador de la lista

    printf("           _      _      _ \n");
    printf("        __( )____( )____( )__ \n");
    printf("       |                    | \n");
    printf("       |    B A T T L E     | \n");
    printf("  _____|      S H I P       |____ \n");
    printf("  \\     [ ]  [ ]  [ ]  [ ]      / \n");
    printf("   \\___________________________/ \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    limpiar();

///Asignar los jugadores///

printf("Jugadores cuales son sus nombres? \n"); //Hacer una lista de nombres y apellidos
    for(int i = 0; i < 2; i++) { //Recorer la cadena para registrar
        printf("Escribe el nombre del jugador %d\n", i+1);
        scanf("%s", players[i]);
        }

///Jugador1 creación de tablero///

    for(int i=0; i<n; i++){ // Numeros izquierda 1
            jugador1[i][0]=i;
        }
    for(int i=0; i<m; i++){ // Numeros arriba 1
            jugador1[0][i]=i;
        }
    for(int i=1; i<n; i++){ // Relleno del tablero 1
        for(int j=1; j<m; j++){
                jugador1[i][j]= 126;
            }
        }

   printf("INICIALIZANDO\n");
   printf("Tablero de %s \n",players[0]); // Impresion del tablero 1
   tablero1(n, m, jugador1);

///Jugador2 creación de tablero///

    for(int i=0; i<n; i++){ // Numeros izquierda 2
            jugador2[i][0]=i;
        }
    for(int i=0; i<m; i++){ // Numeros arriba 2
            jugador2[0][i]=i;
        }
    for(int i=1; i<n; i++){ // Relleno del tablero
        for(int j=1; j<m; j++){
        jugador2[i][j]= 126;
        }
    }
   printf("Tablero de %s \n",players[1]); // Impresion del tablero
    tablero2(n, m, jugador2);
    //system("cls");
    limpiar();

///Colocar barcos Jugador 1///

    while(si==1){// Jugador 1 barco 1
        printf("%s\nIngresa las coordenadas del bote 1 (x,y):\n",players[0]);
        scanf("%d %d",&ax1,&ay1);
        if((ax1>n || ax1<1)||(ay1>n||ay1<1)){ // Mantener el barco dentro del rango
            printf("\nERROR: fuera del rango");
        }
        else{ // Asignacion de cordenada y salir del bucle
            jugador1[ax1][ay1]=254;
            si=0;
        }
    }
    printf("\nTablero de %s \n",players[0]); // Imprimir tablero para verificar
    tablero1(n, m, jugador1);

    si=1;
    while(si==1){ // Jugador 1 barco 2 coordenada 1
        printf("\nIngresa las coordenadas del bote 2 (x1,y1):\n");
        scanf("%d %d",&ax21,&ay21);
        if((ax21>n|| ax21<1)||(ay21>n||ay21<1)){ // Mantener el barco dentro del rango
            printf("\nERROR: fuera del rango");
        }
        else if(ax1==ax21 && ay1==ay21){ //Validación de coordenada repetida
            printf("\nERROR: invadiste el lugar del Barco 1");
        }
        else{ // Salir del bucle y aplicar la cordenada
            jugador1[ax21][ay21]=219;
            si=0;
        }
    }
    si=2;
    while(si==2){ // jugador 1 barco 2 coordenada 2
        printf("\nIngresa las coordenadas del bote 2 (x2,y2):\n");
        scanf("%d %d",&ax22,&ay22);
        if ((ax22>m || ax22<1)||(ay22>m||ay22<1)){ //Mantener el barco dentro del rango
            printf("\nERROR: fuera del rango");
        }
        else if((ax1==ax22 && ay1==ay22)||(ax21==ax22 && ay21==ay22)){ // Validacion coordenada repetida
            printf("\nERROR: coordenada repetida");
        }
        else if((ax22>=ax21+2 || ax22<=ax21-2)||(ay22>=ay21+2 || ay22<=ay21-2)){ // Validacion coordenadas adyacentes
            printf("\nERROR: coordenada invalida. El barco no puede medir mas de 2 casillas de distancia.\n");
        }
        else if(ax21!=ax22 && ay21!=ay22){ // Impedir barcos en diagonal
            printf("\nERROR: coordenada invalida. El barco debe estar en la misma fila o columna (no diagonales).\n");
        }
        else { // Asignacion de cordenada y salir del bucle
            jugador1[ax22][ay22]=219;
            si=3;
        }
    }
    printf("\nPARTIDA DE %s \n",players[0]); //Imprimir tablero para verificar
    tablero1(n, m, jugador1);
    limpiar();

///Colocar barcos Jugador 2///

    si=1;
    while(si==1){ // Jugador 2 barco 1
        printf("%s\nIngresa las coordenadas del bote 1 (x,y):\n",players[1]);
        scanf("%d %d",&bx1,&by1);
        if((bx1>n || bx1<1)||(by1>n||by1<1)){ // Mantener el barco dentro del rango
            printf("\nERROR: fuera del rango");
        }
        else{ // Asignacion de cordenada y salir del bucle
            jugador2[bx1][by1]=254;
            si=0;
        }
    }
    printf("\nTablero de %s \n",players[1]); // Imprimir tablero para verificar
    tablero2(n, m, jugador2);

    si=1;
    while(si==1){ // Jugador 2 barco 2 coordenada 1
        printf("\nIngresa las coordenadas del bote 2 (x1,y1):\n");
        scanf("%d %d",&bx21,&by21);
        if ((bx21>n || bx21<1)||(by21>n||by21<1)){//Mantener el barco dentro del rango
            printf("\nERROR: fuera del rango");
        }
        else if(bx1==bx21 && by1==by21){ //Validación de coordenada repetida
            printf("\nERROR: invadiste el lugar del Barco 1");
        }
        else{ // Asignacion de cordenada y salir del bucle
            jugador2[bx21][by21]=219;
            si=0;
        }
    }

    si=2;
    while(si==2){ // Jugador 2 barco 2 coordenada 2
        printf("\nIngresa las coordenadas del bote 2 (x2,y2):\n");
        scanf("%d %d",&bx22,&by22);

        if ((bx22>n || bx22<1)||(by22>n||by22<1)){ //Mantener el barco dentro del rango
                printf("\nERROR: fuera del rango");
        }
        else if((bx1==bx22 && by1==by22)||(bx21==bx22 && by21==by22)){ //validación de coordenada repetida
            printf("\nERROR: coordenada repetida");
        }
        else if((bx22>=bx21+2 || bx22<=bx21-2)||(by22>=by21+2 || by22<=by21-2)){ //Validacion cordenadas adyacentes
            printf("\nERROR: coordenada invalida. El barco no puede medir mas de 2 casillas de distancia.\n");
        }
        else if(bx21!=bx22 && by21!=by22){ // Impedir barcos en diagonal
            printf("\nERROR: coordenada invalida. El barco debe estar en la misma fila o columna (no diagonales).\n");
        }
        else {
            jugador2[bx22][by22]=219;
            si=3;
        }
    }
    printf("\nPARTIDA DE %s\n",players[1]); //Imprimir tablero para verificar
    tablero2(n, m, jugador2);
    limpiar();

///Mecanismo de ataque///

    for(int i=0; i<n; i++){ // Numero de fila  1
        ataques1[i][0]=i;
    }
    for(int i=0; i<m; i++){ // Numero de columna 1
        ataques1[0][i]=i;
    }
    for(int i=1; i<n; i++){ // Relleno 1
        for(int j=1; j<m; j++){
            ataques1[i][j]= 126;
        }
    }

    for(int i=0; i<n; i++){ // Numeor de fila 2
            ataques2[i][0]=i;
        }
    for(int i=0; i<m; i++){ // Numero de columna 2
            ataques2[0][i]=i;
        }
    for(int i=1; i<n; i++){ // Relleno 2
        for(int j=1; j<m; j++){
        ataques2[i][j]= 126;
        }
    }

    while ((victoria1<3)&&(victoria2<3)){ // Mientras que ningun jugador llegue a 3 puntos

        if(turno==1){ // Turno del jugador 1
            printf("Puntuacion actual: %s:%d | %s:%d \n", players[0],victoria1,players[1],victoria2);
            printf("\n Zona de ataque enemiga  \n");
            tabataques1(n, m, ataques1);
                printf("Turno de %s\n",players[0]);
                while(vav==1){
                    printf("\nA que coordenada quieres atacar\n");
                    scanf("%d %d",&ab0,&ba0); // Registro de cordenadas a atacar
                    if ((ab0>n || ab0<1)||(ba0>n||ba0<1)){ // Validacion coordenanas dentro del rango
                        printf("\nERROR: fuera del rango");
                    }
                    else if (ataques1[ab0][ba0]==158 || ataques1[ab0][ba0]==207){ // Validacion coordenadas repetidas
                    printf("\nERROR: coordenada repetida");
                    }
                    else if((jugador2[ab0][ba0]==254)||(jugador2[ab0][ba0]==219)){// Comparar cordenadas con las de los barcos
                        if(jugador2[ab0][ba0]==254){
                            printf("Le diste a el %s\n", brc1);
                        }
                        else if(jugador2[ab0][ba0]==219){
                            printf("Le diste a el %s\n", brc2);
                        }
                    ataques1[ab0][ba0]=158;
                    victoria1 = victoria1+1;
                    vav=0;
                    }
                    else{
                    printf("Tiro fallido \n");
                    ataques1[ab0][ba0]=207;
                    vav=0;
                    }
                }

                vav=1;
                printf("\ Zona de ataque enemiga \n"); // Actualización del tablero
                tabataques1(n, m, ataques1);
        limpiar();
        turno = (turno == 1) ? 2 : 1; // Cambio de turno
        }//Fin de turno 1

        else if (turno==2){ // Turno del jugador 2
            printf("Puntuacion actual: %s:%d | %s:%d\n", players[0],victoria1,players[1],victoria2);
            printf("\ Zona de ataque enemiga \n");
            tabataques2(n, m, ataques2);
                printf("Turno de %s\n",players[1]);
                while(vav==1){
                    printf("\nA que coordenada quieres atacar\n");
                    scanf("%d %d",&ab0,&ba0); // Registro de cordenadas a atacar
                    if ((ab0>n || ab0<1)||(ba0>n||ba0<1)){ // Validacion coordenanas dentro del rango
                        printf("\nERROR: fuera del rango");
                    }
                    else if (ataques2[ab0][ba0]==158 || ataques2[ab0][ba0]==207){ // Validacion coordenadas repetidas
                    printf("\nERROR: coordenada repetida");
                    }
                    else if((jugador1[ab0][ba0]==254)||(jugador1[ab0][ba0]==219)){// Comparar cordenadas con las de los barcos
                        if(jugador1[ab0][ba0]==254){
                            printf("Le diste a el %s\n", brc1);
                        }
                        else if(jugador1[ab0][ba0]==219){
                            printf("Le diste a el %s\n", brc2);
                        }
                    ataques2[ab0][ba0]=158;
                    victoria2 = victoria2+1;
                    vav=0;
                    }
                    else{
                    printf("Tiro fallido \n");
                    ataques2[ab0][ba0]=207;
                    vav=0;
                    }
                }
                vav=1;
                printf("\n Zona de ataque enemiga \n"); // Actualización del tablero
                tabataques2(n, m, ataques2);
                limpiar();
                turno = (turno == 1) ? 2 : 1; // Cambio de turno
        } // Fin del turno 2
    }

    if(victoria1==3){ // Imprimir al ganador
        p=0;
        printf("\nEl ganador es %s\n",players[p]);
        }
    else if(victoria2==3){
        p=1;
        printf("\nEl ganador es %s!!!\n",players[p]);
        }
    printf("Puntuacion final: %s:%d | %s:%d\n", players[0],victoria1,players[1],victoria2);
    printf("\nTABLERO DE %s\n",players[0]);    //IMPRIMIR UBICACIONES
    tablero1(n, m, jugador1);
    printf("\nTABLERO DE %s\n",players[1]);
    tablero2(n, m, jugador2);

return 0;
    }
