/*
 * sensors.h
 *
 *  Created on: Dec 4, 2013
 *  Author: C15Travis.Schriner
 */

#ifndef SENSORS_H_
#define SENSORS_H_


/*
 * Function: initialize()
 * Description: This function sets up my ADC and P1.0 and P1.6
 * 				to output so I can utilize the LEDs. It also stops
 * 				the WDT
 */
void initializeSensors();


/*
 * Function: leftSensor()
 * Description: This function sets the necessary bits in
 * 				my ADC10CTL register so my sensor on BIT3
 * 				senses
 * 	Inputs: P1.3
 */
void leftSensor();


/*
 * Function: rightSensor()
 * Description: This function sets the necessary bits in
 * 				my ADC10CTL register so my sensor on BIT5
 * 				senses
 * 	Inputs: P1.5
 */
void rightSensor();


/*
 * Function: centerSensor()
 * Description: This function sets the necessary bits in
 * 				my ADC10CTL register so my sensor on BIT4
 * 				senses
 * 	Inputs: P1.4
 */
void centerSensor();

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
int leftWall(int threshhold);

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
int rightWall(int threshhold);

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
int frontWall(int threshhold);


#endif /* SENSORS_H_ */
