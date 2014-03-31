#include "Arduino.h"
class Ultrasonic
{
	public:
		Ultrasonic(int pin);
                void DistanceMeasure(void);
		long microsecondsToCentimeters(void);
		long microsecondsToInches(void);
	private:
  		int _pin;
                long duration;
};

Ultrasonic::Ultrasonic(int pin)
{
	_pin = pin;
}

void Ultrasonic::DistanceMeasure(void)
{
    pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pin,LOW);
	pinMode(_pin,INPUT);
	duration = pulseIn(_pin,HIGH);
}
/*The measured distance from the range 0 to 400 Centimeters*/
long Ultrasonic::microsecondsToCentimeters(void)
{
	return duration/29/2;	
}
/*The measured distance from the range 0 to 157 Inches*/
long Ultrasonic::microsecondsToInches(void)
{
	return duration/74/2;	
}

Ultrasonic ultrasonic(7);
void setup()
{
	Serial.begin(9600);
        Serial.println("Initializing serial connection...");     
        pinMode(13, OUTPUT);
        Serial.println("Pin 13 has been set to OUTPUT.");
        digitalWrite(13, LOW);
        delay(1000);
}
void loop()
{
	long RangeInInches;
	ultrasonic.DistanceMeasure();
        RangeInInches = ultrasonic.microsecondsToInches();

        if(RangeInInches < 24){
          digitalWrite(13, HIGH);
        }else{
          digitalWrite(13, LOW);
        }
}
