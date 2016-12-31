#include <SerialListener.h>

SerialListener sListener(256, ';');

void setup() {
	Serial.begin(9600);
	Serial.println("= SerialListener example =");
	Serial.println("send some data with trailing ';' (semicolon).");
}

void loop() {
	sListener.wait();

	if (sListener.recieved())
	{
		int len = sListener.length();
		char* data = sListener.data();
		
    Serial.print("Recieved data: ");
		Serial.print(data);
    Serial.print(", length: ");
    Serial.println(len);
	}
}
