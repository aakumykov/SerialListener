#include "SerialListener.h"

    // public
    SerialListener::SerialListener(int maxLen, char dlmtr) {
      this->maxInputLength = maxLen;
      this->delimiter = dlmtr;
      this->inputData = new char[this->maxInputLength];
    }

    void SerialListener::wait() {
      
      if (!this->dataRecieved && (Serial.available()>0))
      {
        byte piece = Serial.read();
	
	  //~ Serial.print(F("data available: "));
	  //~ Serial.print(char(piece));
	  //~ Serial.print(F("("));
	  //~ Serial.print(piece);
	  //~ Serial.println(F(")"));
        
        if (piece == this->delimiter && (0 != this->len))
        {
          // завершаю приём
	  //this->inputData[this->len++] = char(0);
          this->dataRecieved = true;
          
	  //~ Serial.println(F("SerialListener::wait(), RECIEVE COMPLETE"));
	  //~ Serial.print(F("inputData: -->@"));
	  //~ Serial.print(this->inputData);
	  //~ Serial.println(F("@<--"));
        }
        else 
        {
          // продолжаю приём
          //Serial.println("continue recieving...");
          this->inputData[this->len] = char(piece);
          this->len += 1;
        }
      }
    }

    boolean SerialListener::recieved() {
      ////Serial.println(F("SerialListener.recieved()"));
      return this->dataRecieved;
    }

    int SerialListener::length() {
      ////Serial.println(F("SerialListener.dataLength()"));
      return this->len;
    }

    char* SerialListener::data(bool with_null_character=true) {
      //Serial.println(F("SerialListener::data()"));
	    
      delete this->outputData;

      this->outputData = new char[this->len];

	//~ Serial.print(F("this->outputData: -->@"));
      
      for (int i=0; i < this->len; i++) {
		this->outputData[i] = this->inputData[i]; //хм, тоже работает. Всё дело было в print(ln)-ах?
      }
      
      if (with_null_character) {
		  this->outputData[this->len] = char(0);
	  }
	
	//~ Serial.println(F("@<--"));

      this->clear();

      return this->outputData;
    }

    void SerialListener::clear() {
      //Serial.println(F("SerialListener.clear()"));
      this->len = 0;
      this->dataRecieved = false;
    }

    // private
