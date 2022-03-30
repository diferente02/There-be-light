#include <IRremote.h>
#include <IRremoteInt.h>

#define sensor 2
#define rele 8

bool estado_rele = false; //variavel  pra desligar e ligar o  rele

IRrecv sensorIR(sensor);
decode_results comando;

void setup(){
 Serial.begin(9600);
sensorIR.enableIRIn(); 
pinMode(rele, OUTPUT);
pinMode(7,OUTPUT);
}

void loop(){
  digitalWrite(7, HIGH);
 if(sensorIR.decode(&comando)){
  Serial.println(comando.value, HEX);
  
    switch(comando.value){
      case(0xFF38C7):{  // se botão OK for pressionado
       estado_rele = !estado_rele; // inverte o valor da variavel estado rele
       Serial.println("ok pressionado");
       break;
       }
    }
    sensorIR.resume(); // encerra os códigos recebidos

 }                
     digitalWrite(rele, estado_rele); 
}
