// SysTickDriver.c
// Runs on TM4C123
// Jesus Hernandez & Valentina Valles
// Last Modified: 09/18/2024  
// Used to initialize and control SysTick

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

void SysTickInit(void){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_RELOAD_R = 80000000/30; // 30Hz gameplay
    NVIC_ST_CTRL_R = 0x7;
}
