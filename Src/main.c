/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32 VS Code Extension
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stm32l432xx.h>


void delay() {
    for(volatile int i=0; i<100000; ++i)
        ; // do nothing, waste some CPU cycles
}


void init_LED() {
    // enable clock for peripheral component GPIOB
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    (void)RCC->AHB2ENR; // read-back, make sure the clock is enabled 

    // set pin PB3 to output mode (1).
    GPIOB->MODER &=~ GPIO_MODER_MODE3;  // clear PB3 mode bits
    GPIOB->MODER |= GPIO_MODER_MODE3_0; // set PB3 to output mode
    // otherwise, GPIO default settings are okay
}


int main(void) {

    init_LED();

    /* Loop forever */
	for(;;) {
        GPIOB->BSRR = GPIO_BSRR_BS3;
        delay();
        GPIOB->BRR = GPIO_BRR_BR3;
        delay();
    }
}
