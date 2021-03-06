#include <SerialListener.h>
#include <MemoryFree.h>

void showMem(char* comment=NULL){
  //Serial.println(F(""));
  Serial.print(F("Free memory"));
  if (NULL != comment)  {
    Serial.print(F(" "));
    Serial.print(comment);
  }
  Serial.print(F(": "));
  Serial.println(freeMemory());
  //Serial.println(F(""));
}

SerialListener sl(256,';');

void setup() {
  Serial.begin(9600);
  Serial.println(F("=seriallistener-test="));
  showMem("on setup");
}

void loop() {
  sl.wait();

  if (sl.recieved()) {
    showMem("on recieve");
    
    char* data = new char[sl.length()];
          data = sl.data();
    showMem("on data");
    delete data;

    showMem("on finish");
    Serial.println(F("----------------------------------"));
  }
}
