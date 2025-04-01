#include <AT89S52.h>
#define BUZZER P0_0

void delay(int c)
{
 int i,j;
 for(i=0;i<c;i++)
 {
  for(j=0;j<1275;j++)
  {}
 }
}

void main()
{
 BUZZER=0;
 while(1)
 {
  BUZZER=1;
  delay(100);
  BUZZER=0;
  delay(100);
 }
}