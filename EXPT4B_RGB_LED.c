#include <AT89S52.h>
#define RLED P0_0
#define GLED P0_1
#define BLED P0_2

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
 RLED=0;GLED=0;BLED=0;
 while(1)
 {
  RLED=1;GLED=0;BLED=0;
  delay(100);
  RLED=0;GLED=1;BLED=0;
  delay(100);
  RLED=0;GLED=0;BLED=1;
  delay(100);
 }
}