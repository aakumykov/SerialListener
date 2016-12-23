#include <Arduino.h>

#ifndef SerialListener_h
#define SerialListener_h

class SerialListener
{
    public:
	SerialListener(int maxLen, char dlmtr);
	void wait();
	boolean isRecieved();
	int dataLength();
	char* data();
    
    private:
	    // настраиваемые пользователем
	    int maxInputLength;
	    char delimiter;
	    
	    // служебные
	    char* inputData;
	    char* outputData;
	    int len = 0;
	    boolean dataRecieved = false;
	    
	    // методы
	    void clear();
};

#endif