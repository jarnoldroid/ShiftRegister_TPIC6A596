/*
 ShiftRegister_TPIC6A596 - a small library for Arduino to wrap up a ShiftRegister (specifically for TPIC6A596)
 MIT licensed.
 */

#include "ShiftRegister_TPIC6A596.h"
#include <Arduino.h>

ShiftRegister::ShiftRegister(uint8_t clockPin, uint8_t latchPin, uint8_t enablePin, uint8_t clearPin, uint8_t dataPin)
:  _clockPin(clockPin)
,  _latchPin(latchPin)
,  _enablePin(enablePin)
,  _clearPin(clearPin)
,  _dataPin(dataPin)
{
}

void ShiftRegister::begin()
{
    pinMode(_clockPin, OUTPUT);
    pinMode(_latchPin, OUTPUT);
    pinMode(_enablePin, OUTPUT);
    pinMode(_clearPin, OUTPUT);
    pinMode(_dataPin, OUTPUT);
    
    digitalWrite(_enablePin, LOW);
    digitalWrite(_clearPin, HIGH);
}

void ShiftRegister::updateShiftRegister(byte b)
{
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, MSBFIRST, b);
    digitalWrite(_latchPin, HIGH);
}
