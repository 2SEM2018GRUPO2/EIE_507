#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <wiringPi.h>

void binario(int arreglo) 
{ 
   int aux;
    
   if(arreglo==0) 
      return; 

   aux=arreglo%2; 
   arreglo=arreglo/2; 
   binario(arreglo); 
   
   printf("%d",aux); 
   led(aux);
   
}

void led(int aux){
	wiringPiSetup();
	PinMode(0,OUTPUT);
	digitalWrite(0,aux);
	delay(100);
}


int main (){
	int arreglo[256];
	int i;
	time_t t;
	
	srand((unsigned) time(&t));
	
	for(i=0; i<=255; i++){
		arreglo[i] = (rand() %255);
		printf("\nArreglo[%d]= %d\nArreglo[%d] =",i,arreglo[i],i);
		binario(arreglo[i]);
			
	}
	
	system("pause");
	return 0;
	
}
