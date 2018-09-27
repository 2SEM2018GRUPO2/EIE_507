#include <stdio.h>
#include <stdlib.h>

float chicharra (int sound);
float conv_FAaC (float FA);

int main() {
	
	char exit;
	int s, FA;
	float C, Z;
	
	
	// do{
	
	printf("Ingrese la cantidad de sonidos producidos por la chicharra, \npercibidos en un minuto: ");
	scanf("%d", &s);
	
	FA= chicharra(s);
	
	C= conv_FAaC (FA);
		
	printf ("La temperatura corresponde a: %0.1f [Grados Celsius] \n", C);
	
	/*printf("\nDesea salir del programa  (S / N) ? \n");
	scanf("%c", &exit); 
	
	}while ( exit!='s' && exit!='S'); */

	system("PAUSE");
	return 0;
}


float chicharra(int sound){
	
	float fa;
		
	fa=(sound)/4 +40;
	
	return fa;
	
}

float conv_FAaC(float FA){
	
	float C;
	
	C= (FA-32)/1.8;
	
	return C;
	
}
