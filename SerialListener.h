#include <Arduino.h>

#ifndef SerialListener_h
#define SerialListener_h

class SerialListener
{
    public:
	SerialListener(int maxLen, char dlmtr);
	void wait();
	boolean recieved();
	int length();
	char* data(bool with_null_character = true);
	void clear();
    
    private:
	    // настраиваемые пользователем
	    int maxInputLength;
	    char delimiter;
	    
	    // служебные
	    char* inputData;
	    char* outputData;
	    int len = 0;
	    boolean dataRecieved = false;
};

#endif
