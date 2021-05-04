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
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "adc0.h"
#include "measurements.h"
#include "gpio.h"
#include "wait.h"
#include "uart0.h"

//LED for testing purposes

#define GREEN_LED PORTF,3
#define RED_LED PORTF,1

//Pins

#define MEASURE_LR PORTA,3
#define MEASURE_C PORTE,2
#define INTEGRATE PORTE,5
#define HIGHSIDE PORTA,2
#define LOWSIDE PORTA,7


//Analog Pins

#define ADC PORTE,4
#define AC PORTC,7


//Constants

#define VREF 2.469
#define CAPS_CONST .000000186
#define RES_CONST 57
#define BUFF_LENGTH 100


void initMeasurements(){
    //Enable Ports
    enablePort(PORTA);
    enablePort(PORTC);
    enablePort(PORTE);
    enablePort(PORTF);

    _delay_cycles(3);

    //Enable LED
    selectPinPushPullOutput(GREEN_LED);
    selectPinPushPullOutput(RED_LED);

    //Enable Pins
    selectPinPushPullOutput(MEASURE_LR);
    selectPinPushPullOutput(MEASURE_C);
    selectPinPushPullOutput(INTEGRATE);
    selectPinPushPullOutput(HIGHSIDE);
    selectPinPushPullOutput(LOWSIDE);

    //Enable Analog Pins

    //initialize ADC
    selectPinAnalogInput(ADC);
    initAdc0();
    setAdc0Ss3Mux(9);

    //initialize analog comparator
    selectPinAnalogInput(AC);

    //Configure WideTimer1 (Had issues with Timer0)

    SYSCTL_RCGCWTIMER_R |= SYSCTL_RCGCWTIMER_R1;                // turn-on timer
    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;   // turn off counter before reconfiguring
    WTIMER1_CFG_R = 4;                   // configure as 32-bit counter (A only)
    WTIMER1_TAMR_R = TIMER_TAMR_TACMR | TIMER_TAMR_TAMR_CAP | TIMER_TAMR_TACDIR; // configure for edge time mode, count up
    WTIMER1_CTL_R = TIMER_CTL_TAEVENT_POS; // measure time from positive edge to positive edge

    WTIMER1_TAV_R = 0;          // zero counter for first period

    SYSCTL_RCGCACMP_R |= 1;     // enable clocks

    //Comparator Init
    COMP_ACREFCTL_R |= 0x20F;    //Creates Ref voltage of 2.469 V from datasheet
    COMP_ACCTL0_R |= 0x402;
    waitMicrosecond(10);

}


void groundPins(){
    //Grounds all pins as a precautionary measure
    setPinValue(GREEN_LED, 0);
    setPinValue(RED_LED, 0);
    setPinValue(LOWSIDE, 0);
    setPinValue(MEASURE_LR, 0);
    setPinValue(MEASURE_C, 0);
    setPinValue(INTEGRATE, 0);
    setPinValue(HIGHSIDE, 0);
}


//returns the voltage across the DUT2 pin
float measVoltage(){
    uint32_t raw = readAdc0Ss3();
    return ((raw/4096)*3.3);
}

float measESR(){

    //discharge pins
    groundPins();
    setPinValue(MEASURE_LR, 1);
    setPinValue(LOWSIDE, 1);
    waitMicrosecond(10e5);

    float voltage = 0;
    voltage = measVoltage(); //measure voltage

    //calculate the resistance from voltage divider equation
    float res = 0;
    res = ((3.3*33 - voltage *33)/voltage);
    groundPins();
    setPinValue(GREEN_LED, 1);
    return res;
}

uint32_t measRes(){
    groundPins();

    //discharge pins
    setPinValue(INTEGRATE, 1);
    setPinValue(LOWSIDE, 1);
    waitMicrosecond(10e5);

    //disable timer and reset TAV
    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
    WTIMER1_TAV_R = 0;
    WTIMER1_CTL_R |= TIMER_CTL_TAEN; //Enable timer

    //Enable pins to measure resistance
    setPinValue(LOWSIDE, 0);
    setPinValue(MEASURE_LR, 1);



    //blocks until the voltage = vref
    while (COMP_ACSTAT0_R == 0X00);

    //Turn off counter and return value
    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
    groundPins();
    uint32_t temp = (WTIMER1_TAV_R/RES_CONST) + 1;
    setPinValue(GREEN_LED, 1);
    return(temp);
}

uint32_t measCap(){
    groundPins();

    //discharge pins
    setPinValue(MEASURE_C, 1);
    setPinValue(LOWSIDE, 1);
    waitMicrosecond(10e5);

    //disable timer and reset TAV
    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
    WTIMER1_TAV_R = 0;
    WTIMER1_CTL_R |= TIMER_CTL_TAEN; //Enable timer

    //Enable pins to measure resistance
    setPinValue(LOWSIDE, 0);
    setPinValue(HIGHSIDE, 1);


    while (COMP_ACSTAT0_R == 0X00){
        //if timer goes on too long, breaks out at a TAV register value equivalent to
        //150 micro
        if(WTIMER1_TAV_R > 0x31ABA855){
            WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
            groundPins();
            setPinValue(RED_LED, 1);
            return(0); //indicates failure
        }
    }

    //Turn off counter and return value
    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
    groundPins();
    uint32_t temp = WTIMER1_TAV_R * CAPS_CONST;
    setPinValue(GREEN_LED, 1);
    return(temp);
}

uint32_t measInd(){
    groundPins();
    float ESR = measESR(); //ESR value
    float t, ind, i = 0;  //initialize time constant,inductance, and current
    float res_int = ESR + 33; //internal resistance

    //discharge pins
    setPinValue(MEASURE_C, 1);
    setPinValue(LOWSIDE, 1);
    waitMicrosecond(10e5);



    //disable timer and reset TAV
    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
    WTIMER1_TAV_R = 0;
    WTIMER1_CTL_R |= TIMER_CTL_TAEN; //Enable timer

    //Enable pins to measure resistance
    setPinValue(MEASURE_C, 0);
    setPinValue(MEASURE_LR, 1);

    while (COMP_ACSTAT0_R == 0X00){
        //if timer goes on too long, breaks out at a TAV register value equivalent to
        //150 micro
        if(WTIMER1_TAV_R > 0x31ABA855){
            WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;
            groundPins();
            setPinValue(RED_LED, 1);
            return(0); //indicates failure
        }
    }

    WTIMER1_CTL_R &= ~TIMER_CTL_TAEN;

    t = WTIMER1_TAV_R / 40000000; //time constant = value / system clock
    i = VREF/ res_int;

    ind = -(res_int * t)/(log(1-(res_int * i)/3.3));
    //need to test if this works





    groundPins();
    setPinValue(GREEN_LED,1);
    return(ind * 1e6);

}

//automatically determines what type of component it is and prints its value
void measAuto(){

    //Runs command for all the different components
    uint32_t res = measRes();
    uint32_t cap = measCap();
    uint32_t ind = measInd();
    char buff[BUFF_LENGTH];

    //check for resistance by seeing if both cap and ind "failed"
    if (cap == 0x00 && ind == 0x00){
        putsUart0("Resistor: ");
        sprintf(buff, "%d", res);
        putsUart0(buff);
        putsUart0(" ohms\r\n");
        return;
    }

    //check for capacitance by seeing if ind is greater than 200 and resistance less than 10
    if (ind > 200 && res < 10){
        putsUart0("Capacitor: ");
        sprintf(buff, "%d", cap);
        putsUart0(buff);
        putsUart0(" microfarads\r\n");
        return;
    }

    //check for inductance by seeing if capacitance failed
    //and resistance less than 100 (accounts for internal resistance of the inductor
    if (cap == 0 && res < 10){
        putsUart0("Inductor: ");
        sprintf(buff, "%d", ind);
        putsUart0(buff);
        putsUart0(" microHenries\r\n");
        return;
    }

}



