// Terminal Library
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
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "tm4c123gh6pm.h"
#include "clock.h"
#include "gpio.h"
#include "uart0.h"
#include "terminal.h"


//LED for testing purposes
#define GREEN_LED PORTF,3
#define RED_LED PORTF,1

//-----------------------------------------------------------------------------
// External Functions (extern gets pretty colors for code composer studios)
//-----------------------------------------------------------------------------
extern void putcUart0(char c);
extern void putsUart0(char* str);
extern char getcUart0();

//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------

//Parsing and UART commands

void initTerminal(){

    // Configure HW to work with 16 MHz XTAL, PLL enabled, system clock of 40 MHz
    initSystemClockTo40Mhz();

    //enable LED port
    enablePort(PORTF);


    //Enable LED pins
    selectPinPushPullOutput(GREEN_LED);
    selectPinPushPullOutput(RED_LED);
}

//retrieves character from terminal interface and writes it into the buffer
void getsUart0(INPUT_LINE *data){
    uint8_t count = 0;
    while (count < MAX_CHARS){
        char c = getcUart0();
        switch (c){
            case 8:
            case 127: // checking for backspace
                count--;
                break;
            case 10:
            case 13: //checking for enter key
                putcUart0('\n');
                data->buffer[count] = '\0';
                return;
            case 32: //checking for space
                data->buffer[count] = c;
                count++;
                break;
            default:
                //convert to lowercase if uppercase
                putcUart0(c); //print character
                if ((c < 91) && (c > 64))c |= 32;
                data->buffer[count] = c;
                count++;
        }
    }
    data->buffer[count] = '\0';
    return;
}

void parseLine(INPUT_LINE* data){
    bool inArg = false; //not in an argument by default
    data->argc = 0; //reset argument from last run
    int i;
    for (i = 0; (i < MAX_CHARS) && (data->buffer[i] != '\0'); ++i){
        if (inArg == false && (data->buffer[i] != ' ')){
            //if not in an argument and not in whitespace, notes that
            //we have entered an argument
            inArg = true;
            data->argv[data->argc] = i;
            data->argc++;
        }

        //if previously in argument and just entered a whitespace, replaces the buffer with
        // a null character
        else if (inArg == true && (data->buffer[i] == ' ')){
            inArg = false;
            data->buffer[i] = '\0';

            // don't attempt to parse more arguments if we are already at our max
            if (data->argc == MAX_FIELDS) break;
        }
    }

    // ensures no trailing characters
    if (i < MAX_CHARS) data->buffer[i] = '\0';
    else data->buffer[MAX_CHARS-1] = '\0';

    return;
}


//Terminal functions

//returns true if the strings match, else returns false
bool strCmp(const char* s1, const char* s2){
    uint8_t count = 0;
    while (s1[count] != '\0' || s2[count] != '\0'){
        if (s1[count] != s2[count]) return false;
        count++;
    }
    return true;
}

//pretties up terminal by adding lines
void skip(){
    int i;
    for (i = 0; i < 15; i++){
        putsUart0("\r\n");
    }
}

//resets system
void resetSys()
{
    NVIC_APINT_R = NVIC_APINT_VECTKEY | NVIC_APINT_SYSRESETREQ;
}

//intro menu
void printMenu(){
    putsUart0("*******************************************************\t\r\n");
    putsUart0("Low Cost Impedance Meter for Embedded 2\t\r\n");
    putsUart0("*******************************************************\t\r\n");
    putsUart0("for more info, type 'help'\t\r\n");
}

//help menu
void printHelp(){
    putsUart0("Showing list of available terminal commands:\t\r\n");
    putsUart0("--------------------------------------------\t\r\n\n");
    putsUart0("Debug Commands:\t\r\n");
    putsUart0("---------------\t\r\n");
    putsUart0("(1)reset-------------Resets the hardware\t\r\n");
    putsUart0("\t\r\n");
    putsUart0("LCR Commands:\t\r\n");
    putsUart0("-------------\t\r\n");
    putsUart0("(1)resistor----------Returns the resistance of the DUT\t\r\n");
    putsUart0("(2)capacitance-------Returns the capacitance of the DUT\t\r\n");
    putsUart0("(3)inductance--------Returns the inductance of the DUT\t\r\n");
    putsUart0("(4)esr---------------Returns the ESR of the inductor under test\t\r\n");
    putsUart0("(5)voltage-----------Returns the voltage across DUT2 and DUT1.\t\r\n");
    putsUart0("(6)auto--------------Returns the value of the DUT that is most predominant\t\r\n");
    putsUart0("\t\r\n");
    putsUart0("Terminal Commands: \t\r\n");
    putsUart0("-------------\t\r\n");
    putsUart0("(1)clear-------------Clears terminal screen\t\r\n");
    putsUart0("(2)help--------------Shows list of available commands\t\r\n");
}
