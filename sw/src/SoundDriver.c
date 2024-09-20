#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "SoundDriver.h"
#include "../inc/Timer0A.h"
//#include "DAC.h"
//#include "Timer0.h



void SquareWave(){
	GPIO_PORTB_DATA_R ^= 0x02;
}

void Sound_Init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x02; 							//activate clock for port B
	while ((SYSCTL_PRGPIO_R&0x02) == 0){};	// ready?
	GPIO_PORTB_CR_R |= 0xFF; 								//Allow changes to PB	
	GPIO_PORTB_AMSEL_R &= ~(0x02);					//Disable analog on PB1
	GPIO_PORTB_DIR_R |= 0x02; 							//PB1 Output	
	GPIO_PORTB_DEN_R |= 0x02;               //Enable digital I/O on PB1
	GPIO_PORTB_AFSEL_R &= ~(0x02);					//Disable alt function on PB1
	Timer0A_Init(SquareWave,80000000/1000,2);
}
