/*
	ShiftRegister_TPIC6A596 - a small library for Arduino to wrap up a ShiftRegister (specifically for TPIC6A596)
	MIT licensed.
*/

#ifndef ShiftRegister_TPIC6A596_h
#define ShiftRegister_TPIC6A596_h
#include "Arduino.h"

class ShiftRegister
{
	public:
		ShiftRegister(uint8_t clockPin, uint8_t latchPin, uint8_t enablePin, uint8_t clearPin, uint8_t dataPin);
        void begin();
        void updateShiftRegister(byte b);
	
	private:
		uint8_t  _clockPin;
        uint8_t  _latchPin;
        uint8_t  _enablePin;
        uint8_t  _clearPin;
        uint8_t  _dataPin;
};

#endif
