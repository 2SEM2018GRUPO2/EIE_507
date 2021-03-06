#include <stdio.h>
#include <wiringPi.h>
#include <sys/time.h>

int pulseIn(int pin, int level)
{
   struct timeval tn, t0, t1;
   int timeout = 1160, micros = 0;
   gettimeofday(&t0, NULL);

   while (digitalRead(pin) != level)
   {
      gettimeofday(&tn, NULL);

      if (tn.tv_sec > t0.tv_sec)
	 micros = 10000L;
      else micros = 0;
      micros += (tn.tv_usec - t0.tv_usec);
     // if (micros > timeout) return 0;
   }
   gettimeofday(&t1, NULL);
   while (digitalRead(pin) == level)
   {
      gettimeofday(&tn, NULL);
      if (tn.tv_sec > t0.tv_sec)
       micros = 10000L; 
       else micros = 0;
      micros = micros + (tn.tv_usec - t0.tv_usec);
      //if (micros > timeout) return 0;
   }
   if (tn.tv_sec > t1.tv_sec)
    micros = 1000000L;
    else micros = 0;
   micros = micros + (tn.tv_usec - t1.tv_usec);

   return micros;
}

int min(int distancia[]){
	int i, min = 50;
	for(i=0; i<5; i++){
		if(distancia[i] <= min)
		min = distancia[i];
	}
return min;
}

int main(){
	int Trigger1 = 4, Trigger2 = 5; //Trigger3 = 17, Trigger4 = 22;
	int Echo1 = 14, Echo2 = 25; //Echo3 = 18, Echo4 = 23;
	int t1,t2,t3,t4, distancia1, distancia2, dismenor; //distancia3, distancia4, dismenor;
	int distancia[5];
	int MotorDer1=12;//se conecta con el pin In1 del L298N
	int MotorDer2=20;//se conecta con el pin In2 del L298N
	int MotorIzq1=21;//se conecta con el pin In3 del L298N
	int MotorIzq2=26;//se conecta con el pin In4 del L298N
	int PWM_Derecho=19;//se conecta con el pin EnA del L298N
	int PWM_Izquierdo=13;//se conecta con el pin Enb del L298N

	wiringPiSetupGpio();
	pinMode(Trigger1, OUTPUT);
  	pinMode(Echo1, INPUT);
	pinMode(Trigger2, OUTPUT);
	pinMode(Echo2,INPUT);
	//pinMode(Trigger3, OUTPUT);
        //pinMode(Echo3, INPUT);
        //pinMode(Trigger4, OUTPUT);
        //pinMode(Echo4,INPUT);

	pinMode(MotorDer1, OUTPUT); 
  	pinMode(MotorDer2, OUTPUT);
  	pinMode(MotorIzq1, OUTPUT); 
  	pinMode(MotorIzq2, OUTPUT); 
  	pinMode(PWM_Derecho, OUTPUT);
  	pinMode(PWM_Izquierdo, OUTPUT);

  	digitalWrite(Trigger1, LOW);
	digitalWrite(Trigger2, LOW);
	//digitalWrite(Trigger3, LOW);
	//digitalWrite(Trigger4, LOW);
	
while(TRUE){

	digitalWrite(Trigger1,HIGH);
    	delayMicroseconds(10);
    	digitalWrite(Trigger1,LOW);
    	t1 = pulseIn(Echo1, HIGH);
	distancia1=((t1*340*0.000001*100)/2);


	digitalWrite(Trigger2,HIGH);
        delayMicroseconds(10);
        digitalWrite(Trigger2,LOW);
        t2 = pulseIn(Echo2, HIGH);
        distancia2=((t2*340*0.000001*100)/2);

	distancia[0] = distancia1;
	distancia[1] = distancia2;
	dismenor = min(distancia);

	if(distancia1>=25){
	digitalWrite (MotorIzq1, HIGH);
        digitalWrite (MotorIzq2, LOW);
        digitalWrite (MotorDer1,LOW);
        digitalWrite (MotorDer2, HIGH);
	digitalWrite(PWM_Derecho,HIGH);
	digitalWrite(PWM_Izquierdo,HIGH);
	}

	if(distancia1<25){
		while(distancia1<25){
			digitalWrite(Trigger1,HIGH);
		       	 delayMicroseconds(10);
       			 digitalWrite(Trigger1,LOW);
       			 t1 = pulseIn(Echo1, HIGH);
       			 distancia1=((t1*340*0.000001*100)/2);
			
			if(distancia1>25)
				break;
			else{
			printf("Distancia1 :%d cm\n",distancia1);

			digitalWrite(MotorIzq1,HIGH);
                        digitalWrite(MotorIzq2,LOW);
                        digitalWrite(MotorDer1,LOW);
                        digitalWrite(MotorDer2,HIGH);
                        digitalWrite(PWM_Derecho,LOW);
                        digitalWrite(PWM_Izquierdo,HIGH);
			delay(10);
		}}
	}

	if(distancia2<25){
		while(distancia2<25){
			digitalWrite(Trigger2,HIGH);
			delayMicroseconds(10);
			digitalWrite(Trigger2,LOW);
			t2 = pulseIn(Echo2,HIGH);
			distancia2 = ((t2*340*0.000001*100)/2);
		
			if(distancia2>25){
				break;
			}

			if(distancia2<25){
			printf("distancia2 :%d cm\n",distancia2); 
 			digitalWrite(MotorIzq1,HIGH);
        		digitalWrite(MotorIzq2,LOW);
        		digitalWrite(MotorDer1,LOW);
        		digitalWrite(MotorDer2,HIGH);
        		digitalWrite(PWM_Derecho,HIGH);
        		digitalWrite(PWM_Izquierdo,LOW);
			delay(10);
                        }}}

		if(distancia1==distancia2){
			if(distancia1<25){
			while(distancia1==distancia2){
				 digitalWrite(Trigger2,HIGH);
               			 delayMicroseconds(10);
               			 digitalWrite(Trigger2,LOW);
               			 t2 = pulseIn(Echo2,HIGH);
               			 distancia2 = ((t2*340*0.000001*100)/2);
					
				 digitalWrite(Trigger1,HIGH);
                		 delayMicroseconds(10);
               			 digitalWrite(Trigger1,LOW);
                		 t1 = pulseIn(Echo1,HIGH);
                		 distancia1 = ((t1*340*0.000001*100)/2);
			}	
				if(distancia1=!distancia2)
					break;	

				else{
					 printf("Obstaculo en frente, mover el vehiculo\n");
                        	       	 digitalWrite(MotorIzq1,HIGH);
                       			 digitalWrite(MotorIzq2,LOW);
                       			 digitalWrite(MotorDer1,LOW);
                       			 digitalWrite(MotorDer2,HIGH);
                       			 digitalWrite(PWM_Derecho,LOW);
                       			 digitalWrite(PWM_Izquierdo,LOW);
                       			 delay(10);
                        }}
	}
	printf("Distancia :%d cm\n",distancia1);

	
	delay(10);
}
return 0;
}
