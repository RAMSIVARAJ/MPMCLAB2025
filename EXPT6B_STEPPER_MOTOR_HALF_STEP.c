#include <AT89S52.h>
#define STEPPER_MOTOR P0

void delay(int c)
{
 int i,j;
 for(i=0;i<c;i++)
 {
  for(j=0;j<250;j++)
  {}
 }
}

void main()
{
 char pattern[9]={0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09};
 STEPPER_MOTOR=0x00;
 while(1)
 {
  char k;
  for(k=0;k<8;k++)
  {
   STEPPER_MOTOR=pattern[k];
   delay(1);
  }
 }
}