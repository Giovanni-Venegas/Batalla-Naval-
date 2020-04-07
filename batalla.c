
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <unistd.h>
#include<ctype.h>
void pvp (void);
void pvc (void);
void cargar (void);
void inst (void);
void cerrar (void);
void seleccionar (void);
void ani1 (void);
void ani2 (void);
void impresion_de_tiros(void);
int diagonal (int c);
void seleccionar (void);
int i, j, tablerop1[10][10], tablerop2[10][10], tiro, pasar=0, nju=1, x, y, ganar=0, z, cont=1, a, intent=0, nbg, nbm, nbp;
void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }

int main(){
int op;
	system("clear");
	cargar();
	a:
	do{
		system("clear");
		gotoxy(27,8);
    	printf("\t\t\tBienvenido a B A T A L L A  N A V A L");
			printf("\n\t\tDesarrollado por programadores Giovanni Venegas y Elian Rueda");
			//printf("\n\t\t\t\t\t\tProfesor: Fernando Sancen ");
			//printf("\n\t\t\t\t\t\tMateria: Fundamentos de Programacion");


    
		gotoxy(27,10);
    	printf("************** M E N U *************");
    	gotoxy(27,12);
    	printf("1. ¿Como jugar?");
    
		gotoxy(27,16);
	    printf("3. Cerrar");
    
		gotoxy(27,14); 
	    printf("2. Juega ya!! Jugador vs Computadora");
	    
		gotoxy(27,18);
	    printf("¿Que opcion deseas elegir? ");
	    scanf("%d",&op);
	    system("clear");
	    if (op!=1 && op!=2 && op!=3){
	    	system("clear");
			gotoxy(27,11);
			printf("La opcion elegida es incorrecta. Pulsa enter para continuar");
	    	getchar();
	    	getchar();
	    	system("clear");
		}
		system("clear");
	}	
	
	while(op!=1 && op!=2 && op!=3);
 	switch (op) {
		case 1:
			inst();
			goto a;
		break;
		case 2:
			pvc();
			goto b;
		break;
		case 3:
			b:
			cerrar();
		break;
	}   
    return 0;
}


void pvc (void){
	char cy, hor;
	int cox, coy, pasarb=0, horb, pasara=0;
	int coxa, coya;
	
	for (i=0;i<10;i++){
		for(j=0;j<10;j++){
			tablerop1[i][j]=0;
			tablerop2[i][j]=0;
		}
	}

	system("clear");
	printf("\n\n                           TU  TABLERO                 ");
	printf("\n         _1___2___3___4___5___6___7___8___9___10_ \n");
	printf("       A|___|___|___|___|___|___|___|___|___|___|  \n");
	printf("       B|___|___|___|___|___|___|___|___|___|___| \n");	
	printf("       C|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       D|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       E|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       F|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       G|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       H|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       I|___|___|___|___|___|___|___|___|___|___| \n");
	printf("       J|___|___|___|___|___|___|___|___|___|___| \n");
	gotoxy(1,16);	
	printf("Bienvenido, ahora es tu turno de elegir donde quieres colocar tus barcos\n");
	/****************************************************************Elegir barcos 2X1***************************************************	*/
	gotoxy(1,17);	
	printf("Barcos de 2X1\n");
	for(nbp=2;nbp>0;nbp--){
	do{
	reg:
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	gotoxy(1,18);
	printf("Te quedan %d barcos de 2X1\nElige las coordenadas del barco: ", nbp);
	scanf(" %c",&cy);
	gotoxy(36,19);	
	scanf("%d",&cox);
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	cy=toupper(cy);
	cox--;
	coy=cy-65;
	if(tablerop1[cox][coy]!=0){
		gotoxy(1,18);
		printf("Por favor, elige otra coordenada ya que esta esta ocupada\nPulsa enter para continuar");
		getchar();
		getchar();
	}
	}while(tablerop1[cox][coy]!=0);
	do{	
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	gotoxy(1,18);
	printf("Elige hacia donde quieres que este orientado (arriba(a), abajo(b), izquierda(i) o derecha(d)): ");
	scanf(" %c",&hor);
	hor=toupper(hor);
	gotoxy(1,18);	
	printf("                                                                                                  ");
	gotoxy(1,19);	
	printf("                                                                                                  ");
	switch (hor) {
		case 'A': 
			if((coy-1)>-1){
				pasarb=1;
			}
			else{
				pasarb=0;
			}
		break;
		case 'B': 
			if((coy+1)<10){
				pasarb=2;
			}
			else{
				pasarb=0;
			}
		break;
		case 'I': 
			if((cox-1)>-1){
				pasarb=3;
			}
			else{
				pasarb=0;
			}
		break;
		case 'D': 
			if((cox+1)<10){
				pasarb=4;
			}
			else{
				pasarb=0;
			}
		break;
		default:
		gotoxy(1,18);
		printf("No se existe esa opcion, por favor ingresa otra\nPulsa enter para continuar");
		getchar();
		getchar();
		goto reg;
		break;
	}
	if(pasarb==0){
	gotoxy(1,18);
	printf("ERROR----No cabe en la orientacion seleccionada, por favor escribe otra\nPulsa enter para continuar");
	getchar();
	getchar();
	goto reg;
	
	}
	switch (pasarb){
		case 1:
			if(tablerop1[cox][coy-1]==0){
				pasara=1;
				coxa=cox*4;
				coya=coy-1;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-1]=8-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 2:
			if(tablerop1[cox][coy+1]==0){
				pasara=1;
				coxa=cox*4;
				coya=coy+1;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+1]=8-nbp;
			}
			else{
				pasara=0;
			}

		break;
		case 3:
			if(tablerop1[cox-1][coy]==0){
				pasara=1;
				coxa=(cox-1)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-1][coy]=8-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 4:
			if(tablerop1[cox+1][coy]==0){
				pasara=1;
				coxa=(cox+1)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox+1][coy]=8-nbp;
			}
			else{
				pasara=0;
			}
		break;
	}
	
	if(pasara==0){
	gotoxy(1,18);
	printf("El barco interrumpe con otro ya anteriormente colocado, por favor escribe otra\nPulsa enter para contiuar");
	getchar();
	getchar();
	}
	} while (pasara==0);
	coxa=cox*4;
	coya=coy;
	gotoxy(11+coxa,5+coya);
	printf("X");
	tablerop1[cox][coy]=8-nbp;
	}
/**********************************Termina colocar 2********************/

/****************************************************************Elegir barcos 3X1****************************************************/	
	gotoxy(1,17);
	printf("Barcos de 3X1\n");
	for(nbp=2;nbp>0;nbp--){
	do{
	reg2:
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	gotoxy(1,18);	
	printf("Te quedan %d barcos de 3X1\nElige las coordenadas del barco: ", nbp);
	scanf(" %c",&cy);
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	scanf("%d",&cox);
	cy=toupper(cy);
	cox--;
	coy=cy-65;
	if(tablerop1[cox][coy]!=0){
		gotoxy(1,18);
    	printf("Elige otra coordenada ya que esta esta ocupada\nPulsa enter para continuar");
		getchar();
		getchar();
	}
	}while(tablerop1[cox][coy]!=0);
	do{	
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	gotoxy(1,18);
	printf("Digite hacia donde quieres que este orientado (arriba(a), abajo(b), izquierda(i) o derecha(d)): ");
	scanf(" %c",&hor);
	hor=toupper(hor);
		gotoxy(1,18);	
	printf("                                                                                                     ");
	gotoxy(1,19);	
	printf("                                                                                                      ");
	switch (hor) {
		case 'A': 
			if((coy-2)>-1){
				pasarb=1;
			}
			else{
				pasarb=0;
			}
		break;
		case 'B': 
			if((coy+2)<10){
				pasarb=2;
			}
			else{
				pasarb=0;
			}
		break;
		case 'I': 
			if((cox-2)>-1){
				pasarb=3;
			}
			else{
				pasarb=0;
			}
		break;
		case 'D': 
			if((cox+2)<10){
				pasarb=4;
			}
			else{
				pasarb=0;
			}
		break;
		default:
		printf("ERROR----No existe esa opcion por favor ingresa otra\nPulsa enter para continuar");
		getchar();
		getchar();
		goto reg2;
		break;
	}
	if(pasarb==0){
	gotoxy(1,18);
	printf("No cabe en la orientacion seleccionada, por favor escribe otra\nPulsa enter para continuar");
	getchar();
	getchar();
	goto reg2;
	}
	switch (pasarb){
		case 1:
			if(tablerop1[cox][coy-1]==0 && tablerop1[cox][coy-2]==0){
				pasara=1;
				coxa=cox*4;
				coya=coy-1;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-1]=10-nbp;
				coxa=cox*4;
				coya=coy-2;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-2]=10-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 2:
			if(tablerop1[cox][coy+1]==0 && tablerop1[cox][coy+2]==0){
				pasara=1;
				coxa=(cox)*4;
				coya=coy+1;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+1]=10-nbp;
				coxa=(cox)*4;
				coya=coy+2;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+2]=10-nbp;
			}
			else{
				pasara=0;
			}

		break;
		case 3:
			if(tablerop1[cox-1][coy]==0 && tablerop1[cox-2][coy]==0){
				pasara=1;
				coxa=(cox-1)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-1][coy]=10-nbp;
				coxa=(cox-2)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-2][coy]=10-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 4:
			if(tablerop1[cox+1][coy]==0 && tablerop1[cox+2][coy]==0){
				pasara=1;
				coxa=(cox+1)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox+1][coy]=10-nbp;
				coxa=(cox+2)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox+2][coy]=10-nbp;
			}
			else{
				pasara=0;
			}
		break;
	}
	
	if(pasara==0){
	gotoxy(1,18);
	printf("El barco interrumpe con otro ya anteriormente colocado, por favor escribe otra\nPulsa enter para contiuar");
	getchar();
	getchar();
	}
	} while (pasara==0);
	coxa=cox*4;
	coya=coy;
	gotoxy(11+coxa,5+coya);
	printf("X");
	tablerop1[cox][coy]=10-nbp;
	}
/**********************************Termina colocar 3********************/

/****************************************************************Elegir barcos 5X1***************************************************	*/
	gotoxy(1,17);	
	printf("Barcos de 5X1\n");
	for(nbp=1;nbp>0;nbp--){
	do{
	reg3:
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	gotoxy(1,18);
	printf("Te quedan %d barcos de 5X1\nElige las coordenadas del barco: ", nbp);
	scanf(" %c",&cy);
	gotoxy(36,19);
	scanf("%d",&cox);
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	cy=toupper(cy);
	cox--;
	coy=cy-65;
	if(tablerop1[cox][coy]!=0){
		gotoxy(1,18);
		printf("Elige otra coordenada ya que esta esta ocupada\n Pulsa enter para continuar");
		getchar();
		getchar();
	}
	}while(tablerop1[cox][coy]!=0);
	do{	
	gotoxy(1,18);	
	printf("                                                                                          ");
	gotoxy(1,19);	
	printf("                                                                                          ");
	gotoxy(1,18);
	printf("Digite hacia donde quieres que este orientado (arriba(a), abajo(b), izquierda(i) o derecha(d)): ");
	scanf(" %c",&hor);
	hor=toupper(hor);
	gotoxy(1,18);	
	printf("                                                                                                   ");
	gotoxy(1,19);	
	printf("                                                                                                    ");
	switch (hor) {
		case 'A': 
			if((coy-4)>-1){
				pasarb=1;
			}
			else{
				pasarb=0;
			}
		break;
		case 'B': 
			if((coy+4)<10){
				pasarb=2;
			}
			else{
				pasarb=0;
			}
		break;
		case 'I': 
			if((cox-4)>-1){
				pasarb=3;
			}
			else{
				pasarb=0;
			}
		break;
		case 'D': 
			if((cox+4)<10){
				pasarb=4;
			}
			else{
				pasarb=0;
			}
		break;
		default:
		gotoxy(1,18);
		printf("ERROR---No existe esa opcion porfavor ingresa otra\nPulsa enter para continuar");
		getchar();
		getchar();
		goto reg3;
		break;
	}
	if(pasarb==0){
	gotoxy(1,18);
	printf("ERROR----No cabe en la orientacion seleccionada, porfavor escribe otra\nPulsa enter para continuar");
	getchar();
	getchar();
	goto reg3;
	}
	switch (pasarb){
		case 1:
			if(tablerop1[cox][coy-1]==0 && tablerop1[cox][coy-2]==0 && tablerop1[cox][coy-3]==0 && tablerop1[cox][coy-4]==0){
				pasara=1;
				coxa=cox*4;
				coya=coy-1;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-1]=10;
				coxa=cox*4;
				coya=coy-2;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-2]=10;
				coxa=cox*4;
				coya=coy-3;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-3]=10;
				coxa=cox*4;
				coya=coy-4;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy-4]=10;
			}
			else{
				pasara=0;
			}
		break;
		case 2:
			if(tablerop1[cox][coy+1]==0 && tablerop1[cox][coy+2]==0 && tablerop1[cox][coy+3]==0 && tablerop1[cox][coy+4]==0){
				pasara=1;
				coxa=cox*4;
				coya=coy+1;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+1]=10;
				coxa=cox*4;
				coya=coy+2;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+2]=10;
				coxa=cox*4;
				coya=coy+3;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+3]=10;
				coxa=cox*4;
				coya=coy+4;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox][coy+4]=10;
			}
			else{
				pasara=0;
			}

		break;
		case 3:
			if(tablerop1[cox-1][coy]==0 && tablerop1[cox-2][coy]==0 && tablerop1[cox-3][coy]==0 && tablerop1[cox-4][coy]==0){
				pasara=1;
				coxa=(cox-1)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-1][coy]=10;
				coxa=(cox-2)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-2][coy]=10;
				coxa=(cox-3)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-3][coy]=10;
				coxa=(cox-4)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox-4][coy]=10;
			}
			else{
				pasara=0;
			}
		break;
		case 4:
			if(tablerop1[cox+1][coy]==0 && tablerop1[cox+2][coy]==0 && tablerop1[cox+3][coy]==0 && tablerop1[cox+4][coy]==0){
				pasara=1;
				coxa=(cox+1)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox+1][coy]=10;
				coxa=(cox+2)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox+2][coy]=10;
				coxa=(cox+3)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");
				tablerop1[cox+3][coy]=10;
				coxa=(cox+4)*4;
				coya=coy;
				gotoxy(11+coxa,5+coya);
				printf("X");				
				tablerop1[cox+4][coy]=10;
			}
			else{
				pasara=0;
			}
		break;
	}
	
	if(pasara==0){
	gotoxy(1,18);
	printf("ERROR----El barco interrumpe con otro ya colocado, porfavor escribe otra\nPulsa enter para contiuar");
	getchar();
	getchar();
	}
	} while (pasara==0);
	coxa=cox*4;
	coya=coy;
	gotoxy(11+coxa,5+coya);
	printf("X\n");
	tablerop1[cox][coy]=10;
}
/**********************************Termina colocar 3********************/
	
	gotoxy(1,1);
	system("clear");
	gotoxy(30,12);
	printf("Haz seleccionarado todos tus barcos. Ahora es turno de la computadora.");
	gotoxy(30,13);
	printf("Espere unos segundos por favor... \n");



/****************************************************************Elegir barcos 2X1***************************************************	*/
	srand(time(0));
	for(nbp=2;nbp>0;nbp--){
	do{
	cox=rand() %10 + 0;
	coy=rand() %10 + 0;
	}while(tablerop2[cox][coy]!=0);
	do{	
	reg4:
	hor=rand() %4 +0;
	switch (hor) {
		case 0: 
			if((coy-1)>-1){
				pasarb=1;
			}
			else{
				pasarb=0;
			}
		break;
		case 1: 
			if((coy+1)<10){
				pasarb=2;
			}
			else{
				pasarb=0;
			}
		break;
		case 2: 
			if((cox-1)>-1){
				pasarb=3;
			}
			else{
				pasarb=0;
			}
		break;
		case 3: 
			if((cox+1)<10){
				pasarb=4;
			}
			else{
				pasarb=0;
			}
		break;
		default:
		goto reg4;
		break;
	}
	if(pasarb==0){
	goto reg4;
	}
	switch (pasarb){
		case 1:
			if(tablerop2[cox][coy-1]==0){
				pasara=1;
				tablerop2[cox][coy-1]=3-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 2:
			if(tablerop2[cox][coy+1]==0){
				pasara=1;
				tablerop2[cox][coy+1]=3-nbp;
			}
			else{
				pasara=0;
			}

		break;
		case 3:
			if(tablerop2[cox-1][coy]==0){
				pasara=1;
				tablerop2[cox-1][coy]=3-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 4:
			if(tablerop2[cox+1][coy]==0){
				pasara=1;
				tablerop2[cox+1][coy]=3-nbp;
			}
			else{
				pasara=0;
			}
		break;
	}
	
	} while (pasara==0);
	tablerop2[cox][coy]=3-nbp;
	}
/**********************************Termina colocar 2********************/

/****************************************************************Elegir barcos 3X1***************************************************	*/
	
	for(nbp=2;nbp>0;nbp--){
	do{
	cox=rand() %10 + 0;
	coy=rand() %10 + 0;
	}while(tablerop2[cox][coy]!=0);
	do{	
	reg6:
	hor=rand() %4 +0;
	switch (hor) {
		case 0: 
			if((coy-2)>-1){
				pasarb=1;
			}
			else{
				pasarb=0;
			}
		break;
		case 1: 
			if((coy+2)<10){
				pasarb=2;
			}
			else{
				pasarb=0;
			}
		break;
		case 2: 
			if((cox-2)>-1){
				pasarb=3;
			}
			else{
				pasarb=0;
			}
		break;
		case 3: 
			if((cox+2)<10){
				pasarb=4;
			}
			else{
				pasarb=0;
			}
		break;
		default:
		goto reg6;
		break;
	}
	if(pasarb==0){
	goto reg6;
	}
	switch (pasarb){
		case 1:
			if(tablerop2[cox][coy-1]==0 && tablerop2[cox][coy-2]==0){
				pasara=1;
				tablerop2[cox][coy-1]=5-nbp;
				tablerop2[cox][coy-2]=5-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 2:
			if(tablerop2[cox][coy+1]==0 && tablerop2[cox][coy+2]==0){
				pasara=1;
				tablerop2[cox][coy+1]=5-nbp;
				tablerop2[cox][coy+2]=5-nbp;
			}
			else{
				pasara=0;
			}

		break;
		case 3:
			if(tablerop2[cox-1][coy]==0 && tablerop2[cox-2][coy]==0){
				pasara=1;
				tablerop2[cox-1][coy]=5-nbp;
				tablerop2[cox-2][coy]=5-nbp;
			}
			else{
				pasara=0;
			}
		break;
		case 4:
			if(tablerop2[cox+1][coy]==0 && tablerop2[cox+2][coy]==0){
				pasara=1;
				tablerop2[cox+1][coy]=5-nbp;
				tablerop2[cox+2][coy]=5-nbp;
			}
			else{
				pasara=0;
			}
		break;
	}
	} while (pasara==0);
	tablerop2[cox][coy]=5-nbp;
	}
/*********************************Termina colocar 3********************/

/****************************************************************Elegir barcos 5X1****************************************************/
	
	for(nbp=1;nbp>0;nbp--){
	do{
	cox=rand() %10 + 0;
	coy=rand() %10 + 0;
	}while(tablerop2[cox][coy]!=0);
	do{	
	reg8:
	hor=rand() %4 +0;
	switch (hor) {
		case 0: 
			if((coy-4)>-1){
				pasarb=1;
			}
			else{
				pasarb=0;
			}
		break;
		case 1: 
			if((coy+4)<10){
				pasarb=2;
			}
			else{
				pasarb=0;
			}
		break;
		case 2: 
			if((cox-4)>-1){
				pasarb=3;
			}
			else{
				pasarb=0;
			}
		break;
		case 3: 
			if((cox+4)<10){
				pasarb=4;
			}
			else{
				pasarb=0;
			}
		break;
		default:
		goto reg8;
		break;
	}
	if(pasarb==0){
	goto reg8;
	}
	switch (pasarb){
		case 1:
			if(tablerop2[cox][coy-1]==0 && tablerop2[cox][coy-2]==0 && tablerop2[cox][coy-3]==0 && tablerop2[cox][coy-4]==0){
				pasara=1;
				tablerop2[cox][coy-1]=5;
				tablerop2[cox][coy-2]=5;
				tablerop2[cox][coy-3]=5;
				tablerop2[cox][coy-4]=5;
			}
			else{
				pasara=0;
			}
		break;
		case 2:
			if(tablerop2[cox][coy+1]==0 && tablerop2[cox][coy+2]==0 && tablerop2[cox][coy+3]==0 && tablerop2[cox][coy+4]==0){
				pasara=1;
				tablerop2[cox][coy+1]=5;
				tablerop2[cox][coy+2]=5;
				tablerop2[cox][coy+3]=5;
				tablerop2[cox][coy+4]=5;
			}
			else{
				pasara=0;
			}

		break;
		case 3:
			if(tablerop2[cox-1][coy]==0 && tablerop2[cox-2][coy]==0 && tablerop2[cox-3][coy]==0 && tablerop2[cox-4][coy]==0){
				pasara=1;
				tablerop2[cox-1][coy]=5;
				tablerop2[cox-2][coy]=5;
				tablerop2[cox-3][coy]=5;
				tablerop2[cox-4][coy]=5;
			}
			else{
				pasara=0;
			}
		break;
		case 4:
			if(tablerop2[cox+1][coy]==0 && tablerop2[cox+2][coy]==0 && tablerop2[cox+3][coy]==0 && tablerop2[cox+4][coy]==0){
				pasara=1;
				tablerop2[cox+1][coy]=5;
				tablerop2[cox+2][coy]=5;
				tablerop2[cox+3][coy]=5;			
				tablerop2[cox+4][coy]=5;
			}
			else{
				pasara=0;
			}
		break;
	}
	} while (pasara==0);
	tablerop2[cox][coy]=5;
	}
	
	usleep(4000000);
	gotoxy(30,14);
	printf("Seleccion finalizada. Pulsa enter para continuar...");
	getchar();
	getchar();
	system("clear");
	gotoxy(30,13);
	printf("¡Comienza el juego!");
	seleccionar ();
	int ne1=2, ne2=2, ne3=3, ne4=3, ne5=5, ne6=2, ne7=2, ne8=3, ne9=3, ne10=5, ntc1=0, ntc2=0;
/******************************************************/
	int tial=0, tial2=0, tial3=1, tial4=0;
	int coxaa, coyaa;
	do{
	impresion_de_tiros();
	//**********Tiro Maquina
	if(nju==2){
	gotoxy(1,18);
	printf("Turno de la maquina... Pensando donde tirar: \n");
	do{
		bah1:
	if(tial==0){
		cox=rand() %10 + 0;
		coy=rand() %10 + 0;
	}
	else{
		bah:
		switch(tial2){
			case 0:
				cox=coxaa+tial3;
				coy=coyaa;
				if(cox>9){
					tial2++;
					goto bah;
				}
			break;
			case 1:
				cox=coxaa;
				coy=coyaa+tial3;
				if(coy>9){
					tial2++;
					goto bah;
				}
			break;
			case 2:
				cox=coxaa-tial3;
				coy=coyaa;
				if(cox<0){
					tial2++;
					goto bah;
				}
			break;
			case 3:	
				cox=coxaa;
				coy=coyaa-tial3;
				if(coy<0){
					tial2=0;
					tial=0;
					goto bah1;
				}
			break;
		}
		if(tablerop1[cox][coy]==11 || tablerop1[cox][coy]==12){
			tial2++;
			goto bah;
		}
	}
	
	}while(tablerop1[cox][coy]==11 || tablerop1[cox][coy]==12);
	usleep(1500000);
	gotoxy(49,18);
	printf("%c %d",coy+65,cox+1);
	nju=1;
	if(tablerop1[cox][coy]!=0){
		switch(tablerop1[cox][coy]){
			case 6:
				ne6--;
				if(ne6==1){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 7:
				ne7--;
				if(ne7==1){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 8:
				ne8--;
				if(ne8==1 || ne8==2){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 9:
				ne9--;
				if(ne9==1 || ne9==2){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 10:
				ne10--;
				if(ne10==1 || ne10==2 || ne10==3 || ne10==4){
					ani1();
				}
				else{
					ani2();
				}
			break;	
		}
		tablerop1[cox][coy]=12;
		impresion_de_tiros();
		gotoxy(1,18);
		printf("Felicidades computadora acertaste tu tiro.                                              \n");
		usleep(5000000);
		gotoxy(1,18);
		printf("                                                                                                  ");
		ntc2++;
		if(tial==1){
			tial3++;
		}
		if(tial==0 && tial2==0 && tial3==1){
		tial=1;
		coxaa=cox;
		coyaa=coy;
		}
		
	}
	else{
		tablerop1[cox][coy]=11;
		impresion_de_tiros();
		gotoxy(1,18);
		printf("Fallaste tu tiro. Suerte para la proxima.                                                      \n");
		usleep(5000000);
		gotoxy(1,18);
		printf("                                                                                                  ");
		if(tial3!=1){
			tial2++;
			tial3=1;
		}
		if(tial==1){
			tial2++;
		}
		if(tial2==4){
			tial=0;
			tial2=0;
			tial3=1;
		}
		
	}
	}
	
	else{
	//**********Tiro Jugador	
		do{
		do{
			gotoxy(1,18);
			printf("Elige las coordenadas del barco: ", nbp);
			scanf(" %c",&cy);
			scanf("%d",&cox);
			gotoxy(1,18);	
			printf("                                                                                          ");
			cox--;
			cy=toupper(cy);
			coy=cy-65;
			if(cox>9||cox<0||coy>9||coy<0){
				gotoxy(1,18);
				printf("ERROR---Este valor no es correcto, por favor ingresa uno adecuado. Pulsa enter para continuar  ");
				getchar();
				getchar();
				gotoxy(1,18);
				printf("                                                                                                  ");
			}
		}
		while(cox>9||cox<0||coy>9||coy<0);
		if(tablerop2[cox][coy]==11 || tablerop2[cox][coy]==12){
				gotoxy(1,18);
				printf("ERROR---No puedes tirar en esta cordenada debido a que ya tiraste ahi. Pulsa enter para continuar. ");
				getchar();
				getchar();
				gotoxy(1,18);
				printf("                                                                                                  ");
		}
		}while(tablerop2[cox][coy]==11 || tablerop2[cox][coy]==12);
	nju=2;
	if(tablerop2[cox][coy]!=0){
		switch(tablerop2[cox][coy]){
			case 1:
				ne1--;
				if(ne1==1){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 2:
				ne2--;
				if(ne2==1){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 3:
				ne3--;
				if(ne3==1 || ne3==2){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 4:
				ne4--;
				if(ne4==1 || ne4==2){
					ani1();
				}
				else{
					ani2();
				}
			break;
			case 5:
				ne5--;
				if(ne5==1 || ne5==2 || ne5==3 || ne5==4){
					ani1();
				}
				else{
					ani2();
				}
			break;	
		}
		tablerop2[cox][coy]=12;
		impresion_de_tiros();
		gotoxy(1,18);
		printf("Felicidades acertaste tu tiro. Pulsa enter para continuar.                                  ");
		getchar();
		getchar();
		gotoxy(1,18);
		printf("                                                                                                  ");
		ntc1++;
	}
	else{
		tablerop2[cox][coy]=11;
		impresion_de_tiros();
		gotoxy(1,18);
		printf("Fallaste tu tiro. Suerte para la proxima. Pulsa enter para continuar.                             ");
		getchar();
		getchar();
		gotoxy(1,18);
		printf("                                                                                                  ");
	}
		
	}
	/***************************************************/
	
	
	
	
} while(ntc1!=15 && ntc2!=15);
system("clear");
if(ntc1==15){
	gotoxy(50,13);
	printf("GANASTE JUGADOR, FELICIDADES. ");
}
else if(ntc2==15){
	gotoxy(50,13);
	printf("MALA SUERTE, LA COMPUTADORA ES MAS LISTA QUE TU. ");
}
	
	printf("Pulsa enter para continuar...");
	getchar();
	getchar();
}

	
void cargar (void){
	   system("clear");  
	int count;
	  for (count=1; count<=100; count++){
	gotoxy(30,13); 
	printf("Cargando . . . %d  %c\n ", count, 37);
	usleep(30000);
	  }
	  
	  gotoxy(20,13);
	  printf("Juego listo. Para continuar pulsa enter...");
  getchar();
}

void inst(void){
	system("clear"); 
	gotoxy(35,4);
	printf("�Como jugar?");
	gotoxy(2,8);
	printf("Bienvenido a B A T A L L A    N A V A L , aqui encontraras el secreto para ganar este juego.");
	gotoxy(2,10);
	printf("Cual es el punto del juego? ");
	gotoxy(2,12);
	printf("Simple hundir los barcos de tu enemigo. Recuerda que se te avisara cuando lo hayas hecho");
	gotoxy(35,20);
	printf("Buena Suerte!");
	getchar();
	getchar();
	system("clear"); 
}

void cerrar(void){
	system("clear"); 
	gotoxy(13,13);
	printf("Saliendo del programa... Gracias por jugar. Presiona enter.");
	getchar();
	getchar();
	system("clear");
}

void seleccionar (void){
	system("clear");  
	int count, n;
	srand(time(0));
	gotoxy(20,13); 
	printf("Ahora seleccionararemos que jugador empezara", count, 37);
	  for (n=1; n<=20; n++){
			count=rand() %2 + 1;
			gotoxy(25,14); 
			printf("El jugador seleccionarado es %d  \n ", count);
			usleep(100000);
	  }
	  nju=count;
	  gotoxy(20,15);
	  printf("Juego listo. Para continuar pulsa enter...");
	  getchar();
}
void impresion_de_tiros (){
	int coxa, coya;
	gotoxy(1,1);
	printf("\n\n\n                           TU  TABLERO                                                   TABLERO ENEMIGO ");
	printf("\n         _1___2___3___4___5___6___7___8___9___10_                    _1___2___3___4___5___6___7___8___9___10_\n");
	printf("       A|___|___|___|___|___|___|___|___|___|___|                  A|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       B|___|___|___|___|___|___|___|___|___|___|                  B|___|___|___|___|___|___|___|___|___|___|\n");	
	printf("       C|___|___|___|___|___|___|___|___|___|___|                  C|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       D|___|___|___|___|___|___|___|___|___|___|   O = No diste   D|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       E|___|___|___|___|___|___|___|___|___|___|   X = Le diste   E|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       F|___|___|___|___|___|___|___|___|___|___|                  F|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       G|___|___|___|___|___|___|___|___|___|___|                  G|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       H|___|___|___|___|___|___|___|___|___|___|                  H|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       I|___|___|___|___|___|___|___|___|___|___|                  I|___|___|___|___|___|___|___|___|___|___|\n");
	printf("       J|___|___|___|___|___|___|___|___|___|___|                  J|___|___|___|___|___|___|___|___|___|___|\n");
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(tablerop1[j][i]==11){
				coxa=j*4;
				coya=i;
				gotoxy(11+coxa,6+coya);
				printf("O",tablerop1[j][i]);	
			}
			if(tablerop1[j][i]==12){
				coxa=j*4;
				coya=i;
				gotoxy(11+coxa,6+coya);
				printf("X",tablerop1[j][i]);	
			}
			if(tablerop2[j][i]==11){
				coxa=j*4;
				coya=i;
				gotoxy(71+coxa,6+coya);
				printf("O",tablerop1[j][i]);	
			}
			if(tablerop2[j][i]==12){
				coxa=j*4;
				coya=i;
				gotoxy(71+coxa,6+coya);
				printf("X",tablerop1[j][i]);	
			}
		}
	}
}

void ani2 (void){
   system("clear");  
gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
gotoxy(1,4); 
printf("\n          __                   %c___/                    ",92);
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                   /   %c                    ",92);
printf("\n         (  )                  %c___/                    ",92);
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                    | |                     ");
printf("\n         (  )                  /   %c                    ",92);
printf("\n        (    )                 %c___/                    ",92);
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                    %c /                     ",92);
printf("\n         (  )                   | |                     ");
printf("\n        (    )                 /   %c                    ",92);
printf("\n         (__)                  %c___/                    ",92);
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                    ___                     ");
printf("\n         (  )                   %c /                     ",92);
printf("\n        (    )                  | |                     ");
printf("\n         (__)                  /   %c                    ",92);
printf("\n        _|__|_______           %c___/                    ",92);
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4);
printf("\n          __                                            ");
printf("\n         (  )                   ___                     ");
printf("\n        (    )                  %c /                     ",92);
printf("\n         (__)                   | |                     ");
printf("\n        _|__|_______           /   %c                    ",92);
printf("\n       |____________|          %c___/                    ",92);
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    ",92);
usleep(350000);
gotoxy(1,4);
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                  ___                     ");
printf("\n         (__)                   %c /                     ",92);
printf("\n        _|__|_______            | |                     ");
printf("\n       |____________|          /   %c                    ",92);
printf("\n       |  O   O   O |          %c___/         _____      ",92);
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    ",92);
usleep(350000);
gotoxy(1,4);
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                   ___                     ");
printf("\n        _|__|_______            %c /                     ",92);
printf("\n       |____________|           | |                     ");
printf("\n       |  O   O   O |          /   %c         _____      ",92);
printf("\n   ____|____________|__________%c___/________|_____|___  ",92);
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    ",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                    __ ___ ___ ____                    ");
printf("\n                  /  (         ) ) )                   ");
printf("\n                 (   (    ) __      )                  ");
printf("\n                (     __        )    )                 ");
printf("\n               (  (         )     )   )                ");
printf("\n                 (           _      )                  ");
printf("\n                    (  ____    _   )                   ");
printf("\n                         |   |                         ");
printf("\n                        |     |                        ");
printf("\n                       |       |                       ");
printf("\n  ____________________|_________|______________________");
usleep(3500000);

gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n                         /  / /  %c                         ",92);
printf("\n                        /__/ /    %c                        ",92);
printf("\n                          / /      %c                      ",92);
printf("\n                         / /        %c                    ",92);
printf("\n                        / /         /                      ");
printf("\n                       / /         /                       ");
printf("\n______________________/_/_________/________________________\n");
usleep(350000); 
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n                         /  / /  %c                         ",92);
printf("\n                        /__/ /    %c                        ",92);
printf("\n                          / /      %c                      ",92);
printf("\n                         / /        %c                    ",92);
printf("\n                        / /         /                      ");
printf("\n_______________________/_/_________/_______________________\n");
usleep(350000); 
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n                         /  / /  %c                         ",92);
printf("\n                        /__/ /    %c                        ",92);
printf("\n                          / /      %c                      ",92);
printf("\n                         / /        %c                    ",92);
printf("\n________________________/_/_________/______________________\n");
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n                         /  / /  %c                         ",92);
printf("\n                        /__/ /    %c                        ",92);
printf("\n                          / /      %c                      ",92);
printf("\n_________________________/_/________%c_______________________\n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n                         /  / /  %c                         ",92);
printf("\n                        /__/ /    %c                        ",92);
printf("\n__________________________/_/______%c_________________________\n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n                         /  / /  %c                         ",92);
printf("\n________________________/__/_/____%c__________________________\n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n                          ___/ /%c                           ",92);
printf("\n_________________________/__/_/__%c___________________________\n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                              /%c                           ",92);
printf("\n_____________________________/_/%c_____________________________\n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n______________________________/%c_______________________________\n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                  HUNDISTE EL BARCO                     ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n                                                        ");
printf("\n_______________________________________________________________\n");
usleep(2800000);
}

void ani1 (void){
   system("clear");  
gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
gotoxy(1,4); 
printf("\n          __                   %c___/                    ",92);
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                   /   %c                    ",92);
printf("\n         (  )                  %c___/                    ",92);
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                    | |                     ");
printf("\n         (  )                  /   %c                    ",92);
printf("\n        (    )                 %c___/                    ",92);
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                    %c /                     ",92);
printf("\n         (  )                   | |                     ");
printf("\n        (    )                 /   %c                    ",92);
printf("\n         (__)                  %c___/                    ",92);
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4); 
printf("\n          __                    ___                     ");
printf("\n         (  )                   %c /                     ",92);
printf("\n        (    )                  | |                     ");
printf("\n         (__)                  /   %c                    ",92);
printf("\n        _|__|_______           %c___/                    ",92);
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000);
gotoxy(1,4);
printf("\n          __                                            ");
printf("\n         (  )                   ___                     ");
printf("\n        (    )                  %c /                     ",92);
printf("\n         (__)                   | |                     ");
printf("\n        _|__|_______           /   %c                    ",92);
printf("\n       |____________|          %c___/                    ",92);
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    ",92);
usleep(350000);
gotoxy(1,4);
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                  ___                     ");
printf("\n         (__)                   %c /                     ",92);
printf("\n        _|__|_______            | |                     ");
printf("\n       |____________|          /   %c                    ",92);
printf("\n       |  O   O   O |          %c___/         _____      ",92);
printf("\n   ____|____________|_______________________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    ",92);
usleep(350000);
gotoxy(1,4);
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                   ___                     ");
printf("\n        _|__|_______            %c /                     ",92);
printf("\n       |____________|           | |                     ");
printf("\n       |  O   O   O |          /   %c         _____      ",92);
printf("\n   ____|____________|__________%c___/________|_____|___  ",92);
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    ",92);
usleep(350000);
gotoxy(1,4); 
printf("\n                    __ ___ ___ ____                    ");
printf("\n                  /  (         ) ) )                   ");
printf("\n                 (   (    ) __      )                  ");
printf("\n                (     __        )    )                 ");
printf("\n               (  (         )     )   )                ");
printf("\n                 (           _      )                  ");
printf("\n                    (  ____    _   )                   ");
printf("\n                         |   |                         ");
printf("\n                        |     |                        ");
printf("\n                       |       |                       ");
printf("\n  ____________________|_________|______________________");
usleep(3500000);

gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |                        _____      ");
printf("\n   ____|____________|________(____)_________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|                                   ");
printf("\n       |  O   O   O |          (   )         _____      ");
printf("\n   ____|____________|________(____)_________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______                                    ");
printf("\n       |____________|            (   )                  ");
printf("\n       |  O   O   O |          (   )         _____      ");
printf("\n   ____|____________|________(____)_________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                                           ");
printf("\n        _|__|_______               (   )                ");
printf("\n       |____________|            (   )                  ");
printf("\n       |  O   O   O |          (   )         _____      ");
printf("\n   ____|____________|________(____)_________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
gotoxy(1,4); 
printf("\n          __                                            ");
printf("\n         (  )                                           ");
printf("\n        (    )                                          ");
printf("\n         (__)                        (   )               ");
printf("\n        _|__|_______               (   )                 ");
printf("\n       |____________|            (   )                  ");
printf("\n       |  O   O   O |          (   )         _____      ");
printf("\n   ____|____________|________(____)_________|_____|___  ");
printf("\n   %c_________________________________________________/  ",92);
printf("\n    %c   o    o    o    o    o    o    o    o    o   /   ",92);
printf("\n     %c_____________________________________________/    \n",92);
usleep(350000); 
}
