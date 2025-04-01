#include <AT89S52.h>
#define SW P3_2

char data[]={0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0XFF,'$'};
char *ptr;
char count=0;

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
 ptr=&data[0];
 SW=1;
 SCON=0x40;
 TR1=0;
 TMOD=0x20;
 TH1=0xFD;
 TL1=0xFD;
 TR1=1;
 IE=0x90;
 SBUF=0x00;
 while(1);
}

void serial_isr(void) __interrupt(4)
{
 TI=0;
 while(SW==1);
 delay(1);
 while(SW==0);
 if(*ptr!='$')
 {
  SBUF=*ptr;
  *ptr++;
 }
 else
 {
  ptr=&data[0];
  SBUF=0x00;
 }
}