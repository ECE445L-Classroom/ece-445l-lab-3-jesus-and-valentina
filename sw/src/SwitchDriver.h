#ifndef SWITCHDRIVER_H
#define SWITCHDRIVER_H

#include <stdint.h>

//initializes buttons 
// PB1 is squarewave output to speaker
// PD0 is Button 1
// PD1 is Button 2
// PD2 is Button 3  
void Btn_Init(void);

uint32_t Btn_Pressed(void);

#endif
