//Aamir Mazumdar 1001523593


//-----------------------------------------------------------------------------
// Hardware Target
//-----------------------------------------------------------------------------

// Target Platform: EK-TM4C123GXL Evaluation Board
// Target uC:       TM4C123GH6PM
// System Clock:    40 MHz

// Hardware configuration:
// Red LED:
//   PF1 drives an NPN transistor that powers the red LED
// Green LED:
//   PF3 drives an NPN transistor that powers the green LED
// Pushbutton:
//   SW1 pulls pin PF4 low (internal pull-up is used)

//-----------------------------------------------------------------------------
// Device includes, defines, and assembler directives
//-----------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

#define RED_LED      (*((volatile uint32_t *)(0x42000000 + (0x400043FC-0x40000000)*32 + 2*4))) //PA2
#define YELLOW_LED   (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 4*4))) //PF4
#define BLUE_LED     (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 1*4))) //PF1
#define GREEN_LED    (*((volatile uint32_t *)(0x42000000 + (0x400043FC-0x40000000)*32 + 7*4))) //PA7
#define PUSH_BUTTON1 (*((volatile uint32_t *)(0x42000000 + (0x400053FC-0x40000000)*32 + 1*4))) //PB1 <<< PUSH BUTTON 1 ASSIGNED TO PB1
#define PUSH_BUTTON2 (*((volatile uint32_t *)(0x42000000 + (0x400053FC-0x40000000)*32 + 2*4))) //PB2 <<< PUSH BUTTON 2 ASSIGNED TO PB2

#define YELLOW_LED_MASK 16
#define RED_LED_MASK 4 // Changed because 2^2 is 4
#define BLUE_LED_MASK 2
#define GREEN_LED_MASK 128
#define PUSH_BUTTON1_MASK 2
#define PUSH_BUTTON2_MASK 4

//-----------------------------------------------------------------------------
// Subroutines
//-----------------------------------------------------------------------------

// Blocking function that returns only when SW1 is pressed
void waitPb1Press()
{
    while(PUSH_BUTTON1);
}

void waitPb2Press()
{
    while(!(PUSH_BUTTON2));
}

// Initialize Hardware
void initHw()
{
    // Configure HW to work with 16 MHz XTAL, PLL enabled, sysdivider of 5, creating system clock of 40 MHz
    SYSCTL_RCC_R = SYSCTL_RCC_XTAL_16MHZ | SYSCTL_RCC_OSCSRC_MAIN | SYSCTL_RCC_USESYSDIV | (4 << SYSCTL_RCC_SYSDIV_S);

    // Set GPIO ports to use APB (not needed since default configuration -- for clarity)
    SYSCTL_GPIOHBCTL_R = 0;

    // Enable GPIO port peripherals
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;

    // Configure LED and pushbutton pins
    // PORT A
    GPIO_PORTA_DIR_R  = GREEN_LED_MASK  | RED_LED_MASK;  // bits 1 and 3 are outputs, other pins are inputs
    GPIO_PORTA_DR2R_R = GREEN_LED_MASK  | RED_LED_MASK; // set drive strength to 2mA (not needed since default configuration -- for clarity)
    GPIO_PORTA_DEN_R  = GREEN_LED_MASK  | RED_LED_MASK;

    // PORT F
    GPIO_PORTF_DIR_R  = YELLOW_LED_MASK  | BLUE_LED_MASK;  // bits 1 and 3 are outputs, other pins are inputs
    GPIO_PORTF_DR2R_R = YELLOW_LED_MASK  | BLUE_LED_MASK; // set drive strength to 2mA (not needed since default configuration -- for clarity)
    GPIO_PORTF_DEN_R  = YELLOW_LED_MASK  | BLUE_LED_MASK;  // enable LEDs and pushbuttons

    // PORT B
    GPIO_PORTB_DEN_R  = PUSH_BUTTON1_MASK | PUSH_BUTTON2_MASK;
    GPIO_PORTB_PUR_R  = PUSH_BUTTON1_MASK; // enable internal pull-up for push button
    GPIO_PORTB_PDR_R  = PUSH_BUTTON2_MASK; // enable internal pull-down for push button
}

// Approximate busy waiting (in units of microseconds), given a 40 MHz system clock
void waitMicrosecond(uint32_t us)
{
    __asm("WMS_LOOP0:   MOV  R1, #6");          // 1
    __asm("WMS_LOOP1:   SUB  R1, #1");          // 6
    __asm("             CBZ  R1, WMS_DONE1");   // 5+1*3
    __asm("             NOP");                  // 5
    __asm("             NOP");                  // 5
    __asm("             B    WMS_LOOP1");       // 5*2 (speculative, so P=1)
    __asm("WMS_DONE1:   SUB  R0, #1");          // 1
    __asm("             CBZ  R0, WMS_DONE0");   // 1
    __asm("             NOP");                  // 1
    __asm("             B    WMS_LOOP0");       // 1*2 (speculative, so P=1)
    __asm("WMS_DONE0:");                        // ---
                                                // 40 clocks/us + error
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(void)
{
    // Initialize hardware
    initHw();

    BLUE_LED   = 0;
    YELLOW_LED = 1;
    GREEN_LED  = 1;
    RED_LED    = 0;


    // Turn off green LED, turn on red LED
    RED_LED = 1;
 // Wait for PB press
    waitPb2Press();

    // Turn off red LED, turn on green LED
    RED_LED = 0;
    GREEN_LED = 0;

    waitMicrosecond(1000000);

    BLUE_LED = 1; // Enable blue LED

    waitPb1Press();

    while (1){

        YELLOW_LED ^= 1;
        waitMicrosecond(500000);

    }

    return 0;
}
