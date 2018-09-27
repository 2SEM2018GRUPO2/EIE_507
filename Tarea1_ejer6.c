#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (){
	char cad[50], letra;
	time_t t;
	int i, largo, cont = 0;
	
	srand((unsigned)time(&t));
	largo = (rand() %49);
	
	for(i=0; i<=largo; i++){
		cad[i] = ('a' + rand()% (('z' - 'a') + 1));
		printf("%d) %c\n ",i,cad[i]);	
			
	}
	printf("Ingrese la letra que desea contar: ");
	scanf("%c", &letra);
	printf("\n");
	
	for(i=0; i<=largo; i++){	
			if(cad[i] == letra)
			cont++;		
	}
	
	printf("La letra '%c' se encuentra %d veces\n", letra, cont);
	
	system("pause");
	
	
return 0;	
}
