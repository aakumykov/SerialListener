#include <SerialListener.h>

#include <MemoryFree.h>
void showMem() {
	Serial.print(F("freeMemory()="));
	Serial.println(freeMemory());
}


SerialListener sListener(256, ';');

void setup() {
	Serial.begin(9600);
	Serial.println("= SerialListener example =");
}

void loop() {
	sListener.wait();

	if (sListener.isRecieved())
	{
		char* data = sListener.data();
		int len = sListener.length();
		
		data[len] = char(0);
		
		Serial.print(F("Recieved data: "));
		Serial.print(data);
		
		showMem();
	}
}
