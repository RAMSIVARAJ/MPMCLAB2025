#include <AT89S52.h>
#define LED P0


void main()
{
 LED=0xFF;
 SCON=0x50;
 TR1=0;
 TMOD=0x20;
 TH1=0xFD;
 TL1=0xFD;
 TR1=1;
 IE=0x90;
 while(1);
}

void serial_isr(void) __interrupt(4)
{
 RI=0;
 LED=~SBUF;
}
