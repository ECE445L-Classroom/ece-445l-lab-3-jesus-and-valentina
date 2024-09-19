// SwitchDriver.c
// Runs on TM4C123
// Jesus Hernandez & Valentina Valles
// Last Modified: 09/18/2024  
// Used to initialize and control the Switches 

// PB1 is squarewave output to speaker
// PD0 is Button 1
// PD1 is Button 2
// PD2 is Button 3  

#include <stdint.h>
#include <stdbool.h>

#include "../inc/tm4c123gh6pm.h"

void Btn_Init(void){ //Initializes PORT D as inputs PD2-0
	SYSCTL_RCGCGPIO_R |= 0x08; 							//activate clock for port D
	while ((SYSCTL_PRGPIO_R&0x08) == 0){};	// ready?
	GPIO_PORTD_LOCK_R = 0x4C4F434B;					//Unlock GPIO Port D
	GPIO_PORTD_CR_R |= 0x7F; 								//Allow changes to PD	
	GPIO_PORTD_AMSEL_R &= ~(0x07);					//DIsable analog on PD2-0
	GPIO_PORTD_DIR_R &= ~(0x07); 						//PD2-0 Input		
	GPIO_PORTD_DEN_R |= 0x07;               //Enable digital I/O on PC5
	GPIO_PORTD_AFSEL_R &= ~(0x07);					//Disable alt function on PD2-0
	GPIO_PORTD_PDR_R |= 0x07;               //enable pulldown resistor
}

// bit band all three buttons
#define PD0 (*(volatile uint32_t *) 0x400070004)
#define PD1 (*((volatile uint32_t *) 0x40007008))
#define PD2 (*((volatile uint32_t *) 0x400070010))
uint32_t Btn_Pressed(void) {
    bool PD0_Pressed = (PD0 == 0x01);
    bool PD1_Pressed = (PD1 == 0x01);
    bool PD2_Pressed = (PD2 == 0x01);
    if ((PD0_Pressed && PD1_Pressed && PD2_Pressed) || (PD0_Pressed && PD1_Pressed)
            || (PD0_Pressed && PD2_Pressed) || (PD1_Pressed && PD2_Pressed)) { // if more than one button pressed
        return 0x000;
    } else if (PD0_Pressed) { //left button
        return 0x100;
    } else if (PD1_Pressed) { //middle button
        return 0x010;
    } else if (PD2_Pressed) { //right button
        return 0x001;
    } else { //nothing pressed
        return 0x000;
    }

}
