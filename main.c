#include <msp430.h> 
#include "MovingRobot.h"
#include "sensors.h"

/*
 * main.c
 */
int main(void) {
   initializeSensors();
   initializeMovement();

   int count = 0;

   while(1){

	   leftSensor();
	   if(leftWall(0x1CF)){
		   turnRight45();
	   }

	   rightSensor();
	   if(leftWall(0x1CF)){
	   	   turnLeft45();
	   }

	   centerSensor();
	   if(frontWall(0x1CF)){
	   	   count++;
	   	   if(count == 2){
	   		   turnRight90();
	   		   __delay_cycles(5000);
	   		   turnRight45();
	   	   }else{
	   		   turnLeft90();
	   	   }
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
