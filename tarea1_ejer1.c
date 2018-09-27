#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, j, num, CLA, CAT, ANT, SAL, RES;
	int planilla[10][5];
	
	printf("Ingrese la cantidad de empleados a evaluar: ");
	scanf("%d", &num);
	
	printf("\nIngrese las caracteristicas requeridas para la clasificacion: \n");
	
	for (i=0; i<num; i++){
		
		printf("\n\nCLAVE DEL TRABAJADOR: ");
		scanf("%d", &CLA);
		planilla[i][0]=CLA;
		
		printf("\nDATOS DEL EMPLEADO #%d", CLA);
		
		printf("\nCATEGORIA: ");
		scanf("%d", &CAT);
		planilla[i][1]=CAT;
		
		printf("\nANTIGUEDAD: ");
		scanf("%d", &ANT);
		planilla[i][2]=ANT;
		
		printf("\nPRETENCION DE SUELDO:  \n\n");
		scanf("%d", &SAL);
		planilla[i][3]=SAL;
		
	}
	
	for(i=0; i<num; i++){
	
		if( ( ( (planilla[i][1]==3) ||(planilla[i][1]==4) )&& planilla[i][2] >5 ) || ( planilla[i][1]==2 && planilla[i][2] >7 ) ){
			
			planilla[i][4]= 1;
			
		}else{
			
			planilla[i][4]=0;
		}
	}
	
	printf("Se han analizado %d empleados.\n \n", num);
	printf("  	CLAVE	    CATEGORIA      ANTIGUEDAD      	SALARIO      RESOLUCION\n");
	printf("________________________________________________________________________________\n");
	
	for(i=0; i<num; i++){
		for(j=0; j<5; j++){
			
			printf("|	%d	|", planilla[i][j]);
		}
		printf("\n");
	}
	
	printf("________________________________________________________________________________\n \n");
	
	printf("\nLos siguientes empleados cumplen las condiciones para el puesto de trabajo: \n\n");
	
	for(i=0; i<num; i++){
		
		if(planilla[i][4]==1){
			
		printf("EMPLEADO CLAVE #%d \n", planilla[i][0]);	
			
		}
		
	}
	printf("\n\n");
	system ("PAUSE");
	return 0;
	
}

