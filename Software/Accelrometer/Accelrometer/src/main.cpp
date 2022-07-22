#include <Arduino.h>
#include "LIS331DLHTR-Registers.h"

uint8_t reg = 0;
uint8_t c = 0;

void setup()
{
    // Common lines:-
    Serial.begin(115200);
}

void printByte (uint8_t value, boolean newline = true) {
  for (uint8_t i = 0; i < 8; i++)
    {
        bool b = reg & 0x80;
        Serial.print(b);
        reg = reg << 1;
    }
  if (newline) {
    Serial.println();
  }
}

void loop () {
    reg = c;
    Serial.print(c);
    Serial.print(":\t");
    // 2124 program / 182 RAM:-
    reg = reg << 1;
    reg |= 0x01;
    printByte(reg);
    delay(1000);
    c+=1;
}