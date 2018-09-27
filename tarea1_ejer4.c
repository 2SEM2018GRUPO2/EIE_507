#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void promedio(int TEM[]){
	int i,sum=0, prom;
	for(i=0; i<=23; i++){
		sum = sum + TEM[i];
	}
	prom = sum/24;
	printf("El promedio de la temeperatura registrada en 24 h es: %d grados", prom);
}

void maxmin(int TEM[]){
	int i, max=0, min=40, horamax, horamin;
	for(i=0; i<=23; i++){
		if((TEM[i]) >= max){
			max = TEM[i];
			horamax=i+1;
		}
		if((TEM[i] )<= min){
			min = TEM[i];
			horamin=i+1;
		}
		
	}
	printf("\nLa temperatura maxima fue: %d grados a las %d:00",max,horamax);
	printf("\nLa temperatura minima fue: %d grados a las %d:00",min,horamin);
	
}

int main() {
	
	int TEM[24], i=0;
	time_t t;
	
	srand((unsigned) time(&t));
	printf("Temperatura medida por hora a lo largo de un dia\n");
	
	for(i=0; i<=23; i++){
		TEM[i] = (rand() %40);	
		printf("Hora %d:00, temperatura: %d\n",i+1,TEM[i]);
	}
	
	promedio(TEM);
	maxmin(TEM);
	
return 0;	
}
