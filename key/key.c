#include "key.h"


void KEY_GPIO_Config(){
    
RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);
GPIO_InitTypeDef GPIO_Initstruct;
GPIO_Initstruct.GPIO_Pin=KEY1_GPIO_PIN;
GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
GPIO_Init(KEY1_GPIO_PORT,&GPIO_Initstruct);

GPIO_Initstruct.GPIO_Pin=KEY2_GPIO_PIN;
GPIO_Initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
GPIO_Init(KEY2_GPIO_PORT,&GPIO_Initstruct);




}
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin){
   if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
{
   //À… ÷ºÏ≤‚
   while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);
   return KEY_ON; 
 

} 
   else return KEY_OFF;

}
