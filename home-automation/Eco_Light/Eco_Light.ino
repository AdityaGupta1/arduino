//Integer variables
int photocellPin = 1;     
int photocellReading;    
int ledPin = 13;          
int ledBrightness;

void setup(void) {
  Serial.begin(9600);//Begin a serial connectin
  pinMode(ledPin, OUTPUT);//Set the LED to output
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);//Read the value from the photocell
 
  photocellReading = 1023 - photocellReading;//Invert the value of photocellReading
  ledBrightness = map(photocellReading, 0, 1023, 0, 255);//Make ledBrightness into a value from 0 to 255

  ledBrightness = ledBrightness - 200;//Subtract 200 from ledBrightness
  if(ledBrightness < 0){//Make sure that ledBrightness is always above 0
    ledBrightness = 0;
  }
  
  if(ledBrightness > 50){//Make sure that ledBrightness does not exceed 255
    ledBrightness = 50;
  }
  
  Serial.print("ledBrightness = ");
  Serial.println(ledBrightness);//Print the value of ledBrightness
  
  analogWrite(ledPin, ledBrightness);//Light up the LED with the value of ledBrightness
 
  delay(100);
}
