int brightness;
int photocellPin = 1;
int ledPin = 13;

void setup(){
  Serial.begin(9600);
}

void loop(){
  brightness = analogRead(photocellPin);
  
  brightness = brightness * 10;
  
  if(brightness > 255){
    brightness = 255;
  }
  
  brightness = 255 - brightness;
  
  brightness -= 50;
  
  if(brightness < 0){
    brightness = 0;
  }
  
  analogWrite(ledPin, brightness);
  Serial.println(brightness);
  delay(100);
}
