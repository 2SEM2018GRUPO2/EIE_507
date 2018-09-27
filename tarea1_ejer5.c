#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

float MediaAritmetica(int ALU[]){
	int i, suma;
	float media;
	
	for(i=0; i<=99; i++){
		suma = suma +ALU[i];
	}
	media=suma/100;
	printf("\nLa media aritmetica es: %0.1f", media);
	
	return media;
}

float Varianza(int ALU[], float media){
	int i;
	float suma=0, varianza;
	
	for(i=0; i<= 99; i++){
		suma = ((ALU[i] - media)*(ALU[i] - media))+ suma;
		}
	
	varianza = suma/99;
	
	printf("\nLa varianza es: %0.3f",varianza);
	
	return varianza;
}

void DesvEstandar(float varianza){
	float desv;
	desv = sqrt(varianza);
	
	printf("\nLa desviacion estandar es: %0.3f",desv);
	
}

void Moda(int ALU[]){
	int i=0, j=0, auxiliar, cont=1, max=0, moda;
	
	for(i=0; i<= 99; i++){
		for(j=0; j<= 98; j++){
			if(ALU[j]< ALU[j+1]){
				auxiliar = ALU[j];
				ALU[j] = ALU[j+1];
				ALU[j+1] = auxiliar; 
				
			}
		}
	}
	//for(i=0; i<=99; i++){
		//printf("\n%d) %d",i, ALU[i]);
	//}	
	
	i=0;
	while(i<=99){
		while(ALU[i] == ALU[i+1]){
			cont++;
			i++;
		}
		
		if(cont >= max){
			max = cont;
			moda = ALU[i];
		}
		
		i++;
		cont = 1;
	}
	
	printf("\nLa moda es: %d\n", moda);
}



int main(){
	int ALU[100], i;
	float media, varianza;
	time_t t;
	
	srand((unsigned)time(&t));
	for(i=0; i<=99; i++){
		ALU[i]= (rand() %100);
		printf("\nAlumno %d, Calificacion: %d",i+1,ALU[i]);
	}
	
	media = MediaAritmetica(ALU);
	varianza = Varianza(ALU, media);
	DesvEstandar(varianza);
	Moda(ALU);
	
	
	system("pause");
return 0;	
}
