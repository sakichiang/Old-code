#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "./systick/bsp_SysTick.h"
#include "./led/bsp_led.h"  
#include "./usart/bsp_usart.h"
#include "menu.h"
#include "key.h"
#include "timer.h"

extern const unsigned char BMP1[];
uint8_t a=0;
int main(void)
{
	unsigned char i;
 
	LED_GPIO_Config();
	USART_Config();
	jishi_Init();
	SysTick_Init();   //初始化延迟函数
	I2C_Configuration();//配置CPU的硬件I2C
	OLED_Init();    //初始化OLED
  OLED_Fill(0x00);
  KEY_GPIO_Config();
	while(1){
	i=menu();
  menu_2(i);
  }
}
/*********************************************END OF FILE**********************/
