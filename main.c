#include <msp430.h> 
#include "MovingRobot.h"
#include "sensors.h"

/*
 * main.c
 */
int main(void) {
   initializeSensors();
   initializeMovement();



   while(1){

	   leftSensor();
	   if(leftWall(0x311)){
		   turnRight45();
		   __delay_cycles(50000);
	   }

	   rightSensor();
	   if(rightWall(0x211)==0){
		   turnRight45();
		   __delay_cycles(50000);
	   }else if(rightWall(0x2EF)){
		   turnLeft45();
		   __delay_cycles(50000);
	   }

	   centerSensor();
	   if(frontWall(0x266)){
	   	  turnLeft90();
	   	  __delay_cycles(50000);
	   	  turnLeft90();
	   }
   }
	
	return 0;
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR()
{
    TACTL &= ~CCIFG;            // clear interrupt flag
}
