/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stdio.h"
#define RCC_BASE 0X40021000
#define PortA_BASE 0x40010800
#define BASE_APB2ENR *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH *(volatile uint32_t *) (PortA_BASE + 0x04)
#define g *(volatile uint32_t *) (RCC_BASE + 0x0C)
int main(void)
{
	BASE_APB2ENR |=1<<12;
	GPIOA_CRH &=0XFF0FFFFF;
	GPIOA_CRH |=0x00200000;


	for(;;)
		{
		g |=1<<13;
		for(int i=0; i<5000;i++);
		g &=~(1<<13);
		for(int i=0; i<5000;i++);
		}
	return 0 ;
}
