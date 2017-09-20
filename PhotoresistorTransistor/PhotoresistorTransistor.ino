#include <avr\sleep.h>

#define LED_PIN 2 /*The led that acts as the base in a transistor*/
#define RESISTOR_PIN A5 /*The photoresistor used as emitter and collector*/

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED_PIN, OUTPUT); //Set pin to output
	//Begin serial and print the photoresistor voltage
	Serial.begin(9600);
	Serial.println(analogRead(RESISTOR_PIN));
	
	delay(100);
	
	digitalWrite(LED_PIN, HIGH); // Turn on the led
	
	delay(200);
	
	Serial.println(analogRead(RESISTOR_PIN)); // Read the voltage from the photoresistor
	
	delay(100);
	//Reset everything
	digitalWrite(LED_PIN, LOW);
	Serial.end();
	//Put the auduino to sleep
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_enable();
	sleep_cpu();
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
