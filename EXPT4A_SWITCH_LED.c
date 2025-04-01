#include <AT89S52.h>
#define SW P3_2
#define LED P2_0

void main()
{
 SW=1;
 LED=1;
 while(1)
 {
  if(SW==0)
  {
   LED=0;
  }
  else
  {
   LED=1;
  }
 }
}