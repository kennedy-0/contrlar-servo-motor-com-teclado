#include <Servo.h>
#include <Stepper.h>

//definir os pinos de cada servo

Servo servo1;

//definir a posição de cada servo

int pos1 = 90;

//definir os pinos do cada servo

const int pinServo = 9;

void setup(){
  //chamar cada pino do servo com seu nome
  servo1.attach(pinServo);

  //comunicação  serial
  Serial.begin(9600);

  //chamar a posiçaõ de cada servo
  servo1.write(pos1);


}

void loop(){
  if (Serial.available() > 0){
    char comando = Serial.read(); //ler os comando do monitor serial

    //controle de cada servo 
    //controalar servo com A e D

    if (comando == 'D' || comando == 'd') {
        pos1 += 5;
        if(pos1 > 180){
        pos1 = 180;
      }
      servo1.write(pos1);
      Serial.println(pos1);

    } else if (comando == 'A' || comando == 'a') {
      pos1 -= 5;
      if (pos1 < 0 ) {
        pos1 = 0;
      }
      servo1.write(pos1);
      Serial.println(pos1);
    }
  }

}
