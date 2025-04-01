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
 char pattern=0x88;
 STEPPER_MOTOR=0x00;
 while(1)
 {
  STEPPER_MOTOR=pattern;
  delay(5);
  pattern=(pattern>>1)|(pattern<<7);
 }
}