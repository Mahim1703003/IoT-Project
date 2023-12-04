#include<Servo.h>
Servo myservo;
int bluePin = 13;
int redPin = 12;
int led1 = 3;
int led2 = 4;
int buzzerPin = 2;
int motorPin = 10;
int motorPin2 = 8;
int trigPin2 = 7;
int echoPin2 = 6;
int i;  
char data;
float duration2;
float distance2;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(motorPin,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop(){

  /*digitalWrite(trigPin1,LOW);
  delay(2);
  
  
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin1,LOW);
  
  
  duration1 = pulseIn(echoPin1,HIGH);
  
  
  distance1 = (duration1 * 0.0343) / 2.0;
  

  Serial.print("distance1 = ");
  Serial.print(distance1);
  Serial.println(" cm");
  delay(100);
 

  if(distance1<=5){
    myservo.write(90);
  }
  else{
    myservo.write(0);
  }*/




  digitalWrite(trigPin2,LOW);
  delay(2);

  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin2,LOW);

  duration2 = pulseIn(echoPin2,HIGH);

  distance2 = (duration2 * 0.0343) / 2.0;


  /*Serial.print("distance2 = ");
  Serial.print(distance2);
  Serial.println(" cm");
  delay(100);*/

  if(distance2<=10){
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }
  else{
    digitalWrite(buzzerPin,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }



  
  if(Serial.available()>0){
    data = Serial.read();
    if(data=='b'){
      digitalWrite(bluePin,HIGH);
    }
    else if(data=='l'){
      digitalWrite(bluePin,LOW);
    }
    else if(data=='r'){
      digitalWrite(redPin,HIGH);
    }
    else if(data=='e'){
      digitalWrite(redPin,LOW);
    }
    else if(data=='m'){
      digitalWrite(motorPin,HIGH);
    }
    else if(data=='t'){
      digitalWrite(motorPin,LOW);
    }
    else if(data=='a'){
      digitalWrite(motorPin2,HIGH);
    }
    else if(data=='c'){
      digitalWrite(motorPin2,LOW);
    }
    else if(data=='s'){
      for(i=0;i<=90;i=i+5){
         myservo.write(i);
         delayMicroseconds(40);
      }
    }
    else if(data=='v'){
      myservo.write(0);
    }
    else if(data=='o'){
      digitalWrite(bluePin,HIGH);
      digitalWrite(redPin,HIGH);
      digitalWrite(motorPin,HIGH);
      digitalWrite(motorPin2,HIGH);
    }
    else if(data=='f'){
      digitalWrite(bluePin,LOW);
      digitalWrite(redPin,LOW);
      digitalWrite(motorPin,LOW);
      digitalWrite(motorPin2,LOW);
    }
  }
}
