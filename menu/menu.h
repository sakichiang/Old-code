#ifndef __MENU_H
#define __MENU_H

#include "stm32f10x.h"

int menu(void);
void OLED_Showflag(unsigned char x, unsigned char y, unsigned char TextSize);
void OLED_Showspace(unsigned char x, unsigned char y, unsigned char TextSize);
void menu_2(uint8_t flag);
#define space 95

#endif

