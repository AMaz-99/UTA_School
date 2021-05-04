// Low Cost Impedence Meter Project
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
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "adc0.h"
#include "measurements.h"
#include "gpio.h"
#include "wait.h"
#include "uart0.h"
#include "clock.h"
#include "terminal.h"


#define BUFF_LENGTH 100

//-----------------------------------------------------------------------------
// External Functions (extern gets pretty colors for code composer studios)
//-----------------------------------------------------------------------------
extern char getcUart0();
extern void getsUart0(INPUT_LINE* data);
extern void parseFields(INPUT_LINE* data);



//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------


int main(void){

    //initialize system
    initTerminal();
    initUart0();
    setUart0BaudRate(115200, 40e6);
    initMeasurements();

    INPUT_LINE data;
    printMenu();

    while(true){
        putsUart0("\t\r\n\n>");
        getsUart0(&data);
        parseLine(&data);
        char *cmd = data.buffer[data.argv[0]];


        //measure commands
        if (strCmp(cmd, "resistor")){
            putsUart0("\t\r\nMeasuring Resistance:\r\n");
            uint32_t temp = measRes();
            char buff[BUFF_LENGTH];
            putsUart0("Resistor: ");
            sprintf(buff, "%d", temp);
            putsUart0(buff);
            putsUart0(" ohms\r\n");
        }

        else if(strCmp(cmd, "capacitance")){
            putsUart0("\t\r\nMeasuring Capacitance:\r\n");
            uint32_t temp = measCap();
            char buff[BUFF_LENGTH];
            putsUart0("Capacitor: ");
            sprintf(buff, "%d", temp);
            putsUart0(buff);
            putsUart0(" microfarads\r\n");
        }

        else if(strCmp(cmd, "inductance")){
            putsUart0("\t\r\nMeasuring Inductance:\r\n");
            uint32_t temp = measInd();
            char buff[BUFF_LENGTH];
            putsUart0("Inductor: ");
            sprintf(buff, "%d", temp);
            putsUart0(buff);
            putsUart0(" microhenries\r\n");
        }

        else if(strCmp(cmd, "esr")){
            putsUart0("\t\r\nMeasuring ESR:\r\n");
            float temp = measESR();
            char buff[BUFF_LENGTH];
            putsUart0("ESR: ");
            sprintf(buff, "%.2f", temp);
            putsUart0(buff);
            putsUart0(" ohms\r\n");
        }

        else if(strCmp(cmd, "voltage")){
            putsUart0("\t\r\nMeasuring Voltage:\r\n");
            float temp = measVoltage();
            char buff[BUFF_LENGTH];
            putsUart0("Voltage: ");
            sprintf(buff, "%.2f", temp);
            putsUart0(buff);
            putsUart0(" volts\r\n");
        }

        else if(strCmp(cmd, "auto")){
            putsUart0("\t\r\nMeasuring Component Automatically:\r\n");
            measAuto();
        }


        //terminal commands:

        else if(strCmp(cmd, "clear")){
            skip();
        }

        else if(strCmp(cmd, "help")){
            printHelp();
        }

        //debug commands
        else if(strCmp(cmd, "reset") || strCmp(cmd, "reboot")){
            putsUart0("\t\r\Rebooting System:\r\n");
            waitMicrosecond(10000);
            resetSys();
        }

        else{
            putsUart0("\t\r\Rebooting System:\r\n");
        }
    }


}
