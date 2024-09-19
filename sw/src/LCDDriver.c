// LCDDriver.c
// Runs on TM4C123 for HiLetGo_ST7735R
// Jesus Hernandez & Valentina Valles
// Last Modified: 09/18/2024  
// Used to initialize and control LCD Screen

#include <stdint.h>

#include "../inc/tm4c123gh6pm.h"
#include "../inc/ST7735.h"


typedef uint16_t Color;
void Draw_Clock(void){
	Color blue = ST7735_Color565(144,213,255);
	ST7735_DrawCircle(64,128,blue);
}

void LCD_Init(void){
	Output_Init();
	Draw_Clock();
}