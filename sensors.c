#include <msp430g2553.h>

/*
 * sensors.c
 *
 *  Created on: Dec 5, 2013
 *  Author: C15Travis.Schriner
 *
 *  Description: this .c file gives all the methods required to initialize
 *  			 and utilize the IR sensors available on the robots utilized
 *  			 by the USAFA DFEC in ECE 382. It is designed to use the
 *  			 sensors in conjunction with an MSP430 microcontroller
 *  			 with LEDs available on P1.0 and P1.6.
 *
 */


//======================================================================
//======================================================================

/*
 * Function: initialize()
 * Description: This function sets up my ADC and P1.0 and P1.6
 * 				to output so I can utilize the LEDs. It also stops
 * 				the WDT
 */
void initializeSensors(){

	 WDTCTL = WDTPW + WDTHOLD;                   // Stop WDT
	 ADC10CTL0 &= ~ENC;                          // Sampling and conversion stop
	 ADC10CTL1 = INCH_3;                         // input channel A3
	 ADC10AE0 |= BIT3;                           // PA.1 ADC option select
	 ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	 ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;         // Select SMCLK
	 P1DIR |= (BIT0|BIT6);                       // Set P1.0 and P1.6 to output direction
}

/*
 * Function: leftSensor()
 * Description: This function sets the necessary bits in
 * 				my ADC10CTL register so my sensor on BIT3
 * 				senses
 * 	Inputs: P1.3
 */
void leftSensor() {
        ADC10CTL0 &= ~ENC;                // Sampling and conversion stop
        ADC10CTL1 = INCH_3;               // input channel A3
        ADC10AE0 |= BIT3;                 // PA.1 ADC option select
        ADC10CTL0 |= ENC + ADC10SC;       // Sampling and conversion start
        __bis_SR_register(CPUOFF + GIE);  // LPM0, ADC10_ISR will force exit



}

/*
 * Function: rightSensor()
 * Description: This function sets the necessary bits in
 * 				my ADC10CTL register so my sensor on BIT5
 * 				senses
 * 	Inputs: P1.5
 */
void rightSensor() {
        ADC10CTL0 &= ~ENC;                 // Sampling and conversion stop
        ADC10CTL1 = INCH_5;                // input channel A5
        ADC10AE0 |= BIT5;                  // PA.3 ADC option select
        ADC10CTL0 |= ENC + ADC10SC;        // Sampling and conversion start
        __bis_SR_register(CPUOFF + GIE);   // LPM0, ADC10_ISR will force exit
}

/*
 * Function: centerSensor()
 * Description: This function sets the necessary bits in
 * 				my ADC10CTL register so my sensor on BIT4
 * 				senses
 * 	Inputs: P1.4
 */
void centerSensor(){
        ADC10CTL0 &= ~ENC;                 // Sampling and conversion stop
        ADC10CTL1 = INCH_4;                // input channel A4
        ADC10AE0 |= BIT4;                  // PA.2 ADC option select
        ADC10CTL0 |= ENC + ADC10SC;        // Sampling and conversion start
        __bis_SR_register(CPUOFF + GIE);   // LPM0, ADC10_ISR will force exit
}

/*
 * Function: leftWall(int threshhold)
 *
 * Description: This function will return a 1 if the
 * 				sensor on pin 3 senses a wall. It will
 * 				return a 0 if no wall is detected.
 * 				It will also turn on the LED on P1.0
 * 				as long as the sensor detects a wall.
 *
 * 	Inputs: threshhold~ this is a user defined threshhold
 * 						level that can be calibrated
 * 						depending on the sensor, lighting,
 * 						wall, and many other factors.
 */
int leftWall(int threshhold){
	 if (ADC10MEM < threshhold) {

		 P1OUT &= ~BIT0;             // Clear P1.0 LED off
	     return 0;

	 } else {

		 P1OUT |= BIT0;              // Set P1.0 LED on
	     return 1;
	 }

}

/*
 * Function: rightWall(int threshhold)
 *
 * Description: This function will return a 1 if the
 * 				sensor on pin 5 senses a wall. It will
 * 				return a 0 if no wall is detected.
 * 				It will also turn on the LED on P1.6
 * 				as long as the sensor detects a wall.
 *
 * 	Inputs: threshhold~ this is a user defined threshhold
 * 						level that can be calibrated
 * 						depending on the sensor, lighting,
 * 						wall, and many other factors.
 */
int rightWall(int threshhold){
	if (ADC10MEM < threshhold) {

		P1OUT &= ~BIT6;                 // Clear P1.6 LED off
		return 0;

     } else {

		P1OUT |= BIT6;                  // Set P1.6 LED on
		return 1;
	 }

}

/*
 * Function: frontWall(int threshhold)
 *
 * Description: This function will return a 1 if the
 * 				sensor on pin 4 senses a wall. It will
 * 				return a 0 if no wall is detected.
 *
 * 	Inputs: threshhold~ this is a user defined threshhold
 * 						level that can be calibrated
 * 						depending on the sensor, lighting,
 * 						wall, and many other factors.
 */
int frontWall(int threshhold){
	if (ADC10MEM < threshhold) {

		return 0;

	} else {

		return 1;

	}

}





