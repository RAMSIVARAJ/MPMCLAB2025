#include <AT89S52.h>
#define LCD_BUS P2 
#define RS P0_5
#define RW P0_6
#define EN P0_7
#include <LCD.h>
#define ADC_BUS P3
#define ALE P1_1
#define SOC P1_2
#define EOC P1_3
#define OE P1_4
#define ADDRA P1_5
#define ADDRB P1_6
#define ADDRC P1_7
#include <ADC0809.h>
#define MM P0_1
#define MP P0_0

void delay(char c)
{
 char i,j;
 for(i=0;i<c;i++)
 {
  for(j=0;j<250;j++)
  {}
 }
}

void motor_speed(char s)
{
 MP=1;
 delay(s);
 MP=0;
 delay(100-s);
}

void main()
{
 char h,t,o;
 char val,temp,pwm;
 lcd_init();
 lcd_print("TEMPERATURE:  ");
 lcd_data(0xDF);
 lcd_data('C');
 MM=0;
 MP=0;
 while(1)
 {
  val=read_adc(0);
  temp=(val*196)/100;
  h=(temp/100)|0x30;
  t=((temp%100)/10)|0x30;
  o=(temp%10)|0x30;
  lcd_cmd(0x8C);
  lcd_data(h);
  lcd_data(t);
  lcd_data(o);
  pwm=20+(temp-25)*3;
  if(temp<=25)
  {
   MM=0;
   MP=0;
  }
  else if(pwm>=100)
  {
   MM=0;
   MP=1;
  }
  else
  {
   motor_speed(pwm);
  }
 }
}