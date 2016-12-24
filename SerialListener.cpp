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
        ////Serial.println(F("data is available"));
        
        byte piece = Serial.read();
        
        if (piece == this->delimiter && (0 != this->len))
        {
          // завершаю приём
          //Serial.println(F("RECIEVE COMPLETE"));
          this->inputData[this->len] = char(0);
          this->len += 1;
          this->dataRecieved = true;
          //Serial.println(this->inputData);
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

    boolean SerialListener::isRecieved() {
      ////Serial.println(F("SerialListener.isRecieved()"));
      return this->dataRecieved;
    }

    int SerialListener::dataLength() {
      ////Serial.println(F("SerialListener.dataLength()"));
      return this->len;
    }

	char* SerialListener::data() {
		
		delete this->outputData;
		
		this->outputData = new char[this->len];


		for (int i=0; i < this->len; i++) {
			this->outputData[i] = this->inputData[i]; //хм, тоже работает. Всё дело было в print(ln)-ах?
			//Serial.print(this->outputData[i]);
		}

		this->clear();

		return this->outputData;
	}

    // private
    void SerialListener::clear() {
      //Serial.println(F("SerialListener.clear()"));
      this->len = 0;
      this->dataRecieved = false;
    }

