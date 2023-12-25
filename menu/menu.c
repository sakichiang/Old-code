#include "menu.h"
#include "OLED_I2C.h"
#include "OLED_I2C.h"
#include "./systick/bsp_SysTick.h"
#include "key.h"
#include "stdio.h"
#include "./led/bsp_led.h" 
extern uint8_t a;
extern unsigned int time;
int menu(){
  unsigned char menu[6][9]={{"modify_"},{"time__"},{"ledctrl"},{"test4__"},{"test5__"},{"test6__"}};
  uint8_t i=0,line=0,flag=1,page=0;
  //显示第一页菜单
while(1){ 
  for(i=0+page;i<4+page;i++)
{ 
  OLED_ShowStr(8,line,menu[i],2);
  line=line+2;
  if(line>6) line=0;
  }

if(flag==1) {

  OLED_Showflag(0,0,2);
  OLED_Showspace(0,2,2);
  OLED_Showspace(0,4,2);
  OLED_Showspace(0,6,2);
}
else if(flag==2){
  OLED_Showspace(0,0,2);
  OLED_Showflag(0,2,2);
  OLED_Showspace(0,4,2);
  OLED_Showspace(0,6,2);
}

else if(flag==3){
  OLED_Showspace(0,0,2);
  OLED_Showspace(0,2,2);
  OLED_Showflag(0,4,2);
  OLED_Showspace(0,6,2);
}  

else if (flag==4){
  OLED_Showspace(0,0,2);
  OLED_Showspace(0,2,2);
  OLED_Showspace(0,4,2);
  OLED_Showflag(0,6,2);
 }
else if(flag==5){ 
  page=1;
  OLED_Showspace(0,0,2);
  OLED_Showspace(0,2,2);
  OLED_Showspace(0,4,2);
  OLED_Showflag(0,6,2);}

else if(flag==6){ 
  page=2;
  OLED_Showspace(0,0,2);
  OLED_Showspace(0,2,2);
  OLED_Showspace(0,4,2);
  OLED_Showflag(0,6,2);}
else if(flag>6) flag=1,page=3;

if(page>2) page=0; 

if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==KEY_ON) flag++;
if(Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON) return flag;
}
return 0;
}

//二级菜单
void menu_2(uint8_t flag){
//选项1
if(flag==1){
  uint8_t i=0,line=0,flag_2=2,fun=0;
  unsigned char menu_2[4][9]={{"value:"},{"+"},{"-"},{"back"}};
  char num[4]={""};
  OLED_CLS();
  while(1){
    for(i=0;i<4;i++)
{ 
      OLED_ShowStr(8,line,menu_2[i],2);
      line=line+2;
      if(line>6) line=0;
  }


  sprintf(num,"%d",a);
  OLED_ShowStr(56,0,num,2);
    if(flag_2==2){
      OLED_Showspace(0,0,2);
      OLED_Showflag(0,2,2);
      OLED_Showspace(0,4,2);
      OLED_Showspace(0,6,2);
}

    else if(flag_2==3){
      OLED_Showspace(0,0,2);
      OLED_Showspace(0,2,2);
      OLED_Showflag(0,4,2);
      OLED_Showspace(0,6,2);
}  

    else if (flag_2==4){
      OLED_Showspace(0,0,2);
      OLED_Showspace(0,2,2);
      OLED_Showspace(0,4,2);
      OLED_Showflag(0,6,2);
 }
    else if (flag_2>4) flag_2=2;
    if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==KEY_ON) flag_2++;
    if(Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON) {
      fun=flag_2;
      if (fun==2) a++;
      else if(fun==3) a--;
      else if(fun==4) return;
       
    }
  }
}
//选项2
if(flag==2){
uint8_t i=0,line=0,flag_2=2,fun=0;
  unsigned char menu_2[4][9]={{"time:"},{"back"},{"__"},{"__"}};
  char num[6]={""};
  OLED_CLS();
  while(1){
    for(i=0;i<4;i++)
{ 
      OLED_ShowStr(8,line,menu_2[i],2);
      line=line+2;
      if(line>6) line=0;
  }


  sprintf(num,"%d",time);
  OLED_ShowStr(48,0,num,2);
    if(flag_2==2){
      OLED_Showspace(0,0,2);
      OLED_Showflag(0,2,2);
      OLED_Showspace(0,4,2);
      OLED_Showspace(0,6,2);
}

   
 
    else if (flag_2>2) flag_2=2;
    if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==KEY_ON) flag_2++;
    if(Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON) {
      fun=flag_2;
      if (fun==2) return;
     
       
    }
  }
  }
//选项3
  if(flag==3)
{
uint8_t i=0,line=0,flag_2=1,fun=0;
  unsigned char menu_2[4][9]={{"ON"},{"OFF"},{"BACK"},{"___"}};
  char num[4]={""};
  OLED_CLS();
  while(1){
    for(i=0;i<4;i++)
{ 
      OLED_ShowStr(8,line,menu_2[i],2);
      line=line+2;
      if(line>6) line=0;
  }


    if(flag_2==1){
      OLED_Showflag(0,0,2);
      OLED_Showspace(0,2,2);
      OLED_Showspace(0,4,2);
      OLED_Showspace(0,6,2);
}    
    else if(flag_2==2){
      OLED_Showspace(0,0,2);
      OLED_Showflag(0,2,2);
      OLED_Showspace(0,4,2);
      OLED_Showspace(0,6,2);
}
  else if(flag_2==3){
      OLED_Showspace(0,0,2);
      OLED_Showspace(0,2,2);
      OLED_Showflag(0,4,2);
      OLED_Showspace(0,6,2);
}
    
    if (flag_2>3) flag_2=1;
    if(Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==KEY_ON) flag_2++;
    if(Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON) {
      fun=flag_2;
      if(fun==1) LED_RED;
      if(fun==2) LED_RGBOFF;
      if(fun==3) return;
       
    }
     
       
    }
  }
}

