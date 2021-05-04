// Measurements Library
// Aamir Mazumdar 1001523593

//-----------------------------------------------------------------------------
// Hardware Target
//-----------------------------------------------------------------------------

// Target Platform: EK-TM4C123GXL with LCD/Keyboard Interface
// Target uC:       TM4C123GH6PM
// System Clock:    40 MHz

// Hardware configuration:
// GPIO APB ports A-F


//-----------------------------------------------------------------------------
// Device includes, defines, and assembler directives
//-----------------------------------------------------------------------------
#include "tm4c123gh6pm.h"
#include <stdint.h>

#ifndef MEASURMENTS_H_
#define MEASURMENTS_H_



void initMeasurements();
void groundPins();
double measVoltage();
double measESR();
uint32_t measRes();
uint32_t measCap();
uint32_t measInd();

void measAuto();


#endif
