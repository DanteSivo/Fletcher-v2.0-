/** 
 * Filename: LIS331DLHTR.h 
 * Author:   Dante Sivo
 * Description: Header file for communications with LIS331DLHTR Accelerometer
 * Special Notes: Does not include SPI settings
 * 
**/
#ifdef LIS331DLHTR
#endif 

#include <Wire.h>
#include "LIS331DLHTR-Registers.h"

#define accelerometerAddress 0b0011000;

class LIS331DLHTR {
    public:
        bool isReadSigned = false;
        uint8_t newRead;
        double altitude;
        uint8_t address = 0b00011000;

        void setup();
        void write_byte(uint8_t reg);
        uint8_t read_byte(uint8_t reg);
};

void LIS331DLHTR::setup() {
    Wire.begin();
}

/* read_byte() - Get byte from a designated register
    Inputs: 
        reg (uint8_t) - byte address of register
    Outputs:
        newRead (uint8_t) - value from the register
        isReadSigned (bool) - denotes if the read was signed. 
            ** only for OUT registers 
*/
uint8_t LIS331DLHTR::read_byte(uint8_t reg) {
    // Return Signed value if OUT_X through OUT_Z
    if (reg >= OUT_X_L && reg <= OUT_Z_H) {
            isReadSigned = true;
    } else {
        isReadSigned = false;
    }

    reg = reg<<1; // Shift to left to add in last bit
    reg |= 0x01; // Last bit is '1' for read commands

    Wire.write(reg); // 
    while (Wire.available()) {
        newRead = Wire.read(); // Get the byte
    }
    return newRead;
}