/* Programa final para mover los desvios de una maqueta mediante
servos de modelismo. Se utilizan 4 pulsadores conectados al pin
analogico A0. 
Los pines reservados para los servos son: pin 6,7,8,9
y van enlazados a los pines 10,11,12,13 respectivamente para encender
un LED o accionar un rele */

#include <Servo.h>

Servo servo1;       //Primer servo
Servo servo2;       //Segundo servo
Servo servo3;       //Tercer servo
Servo servo4;       //Cuarto servo 
int swcs = 0;

int estadoPos1=1;    //Estado posición servo1
int estadoPos2=1;    //Estado posición servo2
int estadoPos3=0;    //Estado posición servo3
int estadoPos4=0;    //Estado posición servo4

int servoVar1=70;    //Posicíon del servo1 al iniciar el programa
int servoVar2=65;    //Posicíon del servo2 al iniciar el programa
int servoVar3=65;    //Posicíon del servo3 al iniciar el programa
int servoVar4=100;    //Posicíon del servo4 al iniciar el programa
int servoVarMin1=70;  //Valor minimo del servo1
int servoVarMin2=65;  //Valor minimo del servo2
int servoVarMin3=65;  //Valor minimo del servo3  
int servoVarMin4=65;  //Valor minimo del servo4
int servoVarMax1=95;  //Valor máximo del servo1
int servoVarMax2=100;  //Valor máximo del servo2
int servoVarMax3=100;  //Valor máximo del servo3
int servoVarMax4=100;  //Valor máximo del servo4
int timeDelay=50; //90

int Led1=10;  //LED en pin 10 que correspode al servo1
int Led2=11;  //LED en pin 11 que correspode al servo2
int Led3=12;  //LED en pin 12 que correspode al servo3
int Led4=13;  //LED en pin 13 que correspode al servo4

void setup() {
  Serial.begin(9600);
servo1.attach(6);    //Adjuntamos el pin 6 a servo1
servo2.attach(7);    //Adjuntamos el pin 7 a servo2
servo3.attach(8);    //Adjuntamos el pin 8 a servo3
servo4.attach(9);    //Adjuntamos el pin 9 a servo4
delay (150);
servo1.write(servoVar1); 
servo2.write(servoVar2); 
delay (150);
servo3.write(servoVar3); 
servo4.write(servoVar4); 
servo1.detach();
servo2.detach();
servo3.detach();
servo4.detach();
pinMode(Led1,OUTPUT);
pinMode(Led2,OUTPUT);
pinMode(Led3,OUTPUT);
pinMode(Led4,OUTPUT); 
}

void loop() {

  int valorPulsador = analogRead(0); // Lee el valor de la entrada analógica A0
       
		if (valorPulsador > 600 && valorPulsador < 1000){
                        swcs=1;
	                Serial.println("b1");
                        Serial.println(valorPulsador);
                        }
		if (valorPulsador > 400 && valorPulsador < 600){
			swcs=2;
                        Serial.println("b2");
                        Serial.println(valorPulsador);
                        }
		 if (valorPulsador > 300 && valorPulsador < 400){
                        swcs=3;
        		Serial.println("b3");
                        Serial.println(valorPulsador);
                        }
		if (valorPulsador > 200 && valorPulsador < 300){
			swcs=4;
                        Serial.println("b4");
                        Serial.println(valorPulsador);
                        }   
                        		
	

 switch (swcs){
//Movimiento Servo 1---------------------------------------------
case 1:
 servo1.attach(6);    //Adjuntamos el pin 6 a servo1 
 if (estadoPos1==1) {
   for(servoVar1 = servoVarMin1; servoVar1 <= servoVarMax1; servoVar1 += 1){                                  
    servo1.write(servoVar1);              
    delay(timeDelay);
 //  Serial.print (servoVar2);
 //  Serial.print (", "); 
    }    
    estadoPos1=0;
    swcs = 0;
    digitalWrite (Led1, HIGH);    
    delay (50);
    }    
else {                   
 if (estadoPos1==0){   
    for(servoVar1 = servoVarMax1; servoVar1 >= servoVarMin1; servoVar1 -= 1){                                   
    servo1.write(servoVar1);              
    delay(timeDelay); 
   // Serial.print (servoVar2);
   // Serial.print (", ");
    }
    estadoPos1=1;
    swcs = 0;
    digitalWrite (Led1,LOW);    
    delay (50);             
      }
    }
servo1.detach();    
  break;
   
  //Movimiento Servo 2------------------------------------------
 case 2:
 servo2.attach(7);    //Adjuntamos el pin 6 a servo1 
 if (estadoPos2==1) {
   for(servoVar2 = servoVarMin2; servoVar2 <= servoVarMax2; servoVar2 += 1){                                  
    servo2.write(servoVar2);              
    delay(timeDelay);
 //  Serial.print (servoVar2);
 //  Serial.print (", "); 
    }    
    estadoPos2=0;
    swcs = 0;
    digitalWrite (Led2, HIGH);    
    delay (50);
    }    
else {                   
 if (estadoPos2==0){   
    for(servoVar2 = servoVarMax2; servoVar2 >= servoVarMin2; servoVar2 -= 1){                                   
    servo2.write(servoVar2);              
    delay(timeDelay); 
   // Serial.print (servoVar2);
   // Serial.print (", ");
    }
    estadoPos2=1;
    swcs = 0;
    digitalWrite (Led2,LOW);    
    delay (50);             
      }
    }
servo2.detach();    
  break;
  //Movimiento Servo 3---------------------------------------------
case 3: 
 servo3.attach(8);    //Adjuntamos el pin 8 a servo3   
 if (estadoPos3==1) {
   
   for(servoVar3 = servoVarMin3; servoVar3 <= servoVarMax3; servoVar3 += 1){                                  
    servo3.write(servoVar3);              
    delay(timeDelay); 
    //Serial.print (servoVar3);
    //Serial.print (", ");
    }    
    estadoPos3 = 0;
    swcs = 0;
    digitalWrite (Led3, HIGH);    
    delay (50);
    }    
else {                   
 if (estadoPos3==0){
    servo3.attach(8);    //Adjuntamos el pin 8 a servo3   
    for(servoVar3 = servoVarMax3; servoVar3 >= servoVarMin3; servoVar3 -= 1){                                   
    servo3.write(servoVar3);              
    delay(timeDelay); 
   // Serial.print (servoVar3);
   // Serial.print (", ");
    }
    estadoPos3=1;
    swcs = 0;    
    digitalWrite (Led3, LOW);    
    delay (50);             
      }
    }
 servo3.detach();
  break;
  //Movimiento Servo 4 ---------------------------------------
  case 4: 
 servo4.attach(9);    //Adjuntamos el pin 9 a servo4
 if (estadoPos4==1) {
   for(servoVar4 = servoVarMin4; servoVar4 <= servoVarMax4; servoVar4 += 1){ 
    servo4.write(servoVar4);              
    delay(timeDelay); 
    //Serial.print (servoVar4);
    //Serial.print (", ");
    }    
    estadoPos4 = 0;
    swcs = 0; 
    digitalWrite (Led4, HIGH);    
    delay (50);
    }    
else {                   
 if (estadoPos4==0){   
    for(servoVar4 = servoVarMax4; servoVar4 >= servoVarMin4; servoVar4 -= 1){                                   
    servo4.write(servoVar4);              
    delay(timeDelay); 
    //Serial.print (servoVar4);
   // Serial.print (", ");
    }
    estadoPos4=1;
    swcs = 0;
    digitalWrite (Led4, LOW);    
    delay (50);             
      }
    }
 servo4.detach();   
  break;
}

  delay(500);
Serial.println("");
Serial.print (estadoPos1);
Serial.print (", ");
Serial.print (estadoPos2);
Serial.print (", ");
Serial.print (estadoPos3);
Serial.print (", ");
Serial.print (estadoPos4);
}

