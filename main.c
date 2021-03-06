/*
 * untitled.c
 * 
 * Copyright 2015  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h> 
#include <bcm2835.h>						// C libraries for Raspberry Pi version 1 & 2

#include "test.h"

#define LED_TEST RPI_V2_GPIO_P1_12		    // Assigning LED output to pin 12?


//extern int PI2;

int HardwareInit(void);

int main(int argc, char **argv)
{
	
	const unsigned int delay_time_ms = 100;
	
	if (!HardwareInit()){}  // Did not fail
	else 
		return 1;			// fail	

	
	while (1)
	{
		bcm2835_gpio_set(LED_TEST); 						//Sets the specified pin output to HIGH 
		printing();
		//printf("Rand Value: %4.2f\r", rand() * PI2);
		//printf("\nRand Value: %f\r", rand() * 3.14);
		bcm2835_delay (delay_time_ms);						// Delay function
		bcm2835_gpio_clr(LED_TEST);					     	//Sets the specified pin output to LOW
		bcm2835_delay (delay_time_ms);	
	}
	
	return 0;
}

int HardwareInit(void)
{
	//if ( !bcm2835_close() )
	if ( !bcm2835_init() ){return 1;}						// return value if initialisation of bcm2835 C functions fails
	
	bcm2835_gpio_fsel(LED_TEST, BCM2835_GPIO_FSEL_OUTP);	// Set the registers as either input or output of the pin  
	
	return 0; 												// All good
}
