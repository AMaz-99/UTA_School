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
#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <stdint.h>
#include <stdbool.h>

//Constants

#define MAX_CHARS 80
#define MAX_FIELDS 6


//-----------------------------------------------------------------------------
// Structures
//-----------------------------------------------------------------------------

typedef struct s_INPUT_LINE
{
    char buffer[MAX_CHARS+1];
    int8_t argc;
    int8_t argv[MAX_FIELDS];

} INPUT_LINE;


//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------

//Parsing and UART commands

void initTerminal();
void getsUart0(INPUT_LINE *data);
void parseLine(INPUT_LINE* data);



//Terminal functions
bool strCmp(const char* s1, const char* s2);
void skip();
void resetSys();
void printMenu();
void printHelp();


#endif

