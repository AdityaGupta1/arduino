#include <Servo.h>
Servo servo;

int servoPin = 8;
int temperaturePin = 0;
int minTemp = 45;

void setup() { 
  servo.attach(servoPin);
  servo.writeMicroseconds(1500);
  Serial.begin(9600);
} 

void loop() { 
 int reading = analogRead(temperaturePin);
 
 float voltage = reading * 5.0;
 voltage /= 1024.0;   
 
  if(fahrenheit(voltage) > minTemp){
    servo.writeMicroseconds(1300);
  }else{
    servo.writeMicroseconds(1500);
  }
  
  Serial.print(fahrenheit(voltage));
  Serial.println();
  
  delay(100);
}

float celsius(float voltage){
  return (voltage - 0.5) * 100;
}

float fahrenheit(float voltage){
  return (celsius(voltage) * 9.0 / 5.0) + 32.0;
}
