#ifndef ADC0809_H
#define ADC0809_H

void adc_init(void);
char read_adc(char);

void adc_init()
{
 ADC_BUS=0xFF;
 ALE=0;
 SOC=0;
 OE=0;
 EOC=1;
}

char read_adc(char ch)
{
 char value;
 if(ch&0x01!=0)
 {
  ADDRA=1;
 }
 else
 {
  ADDRA=0;
 }
 if(ch&0x02!=0)
 {
  ADDRB=1;
 }
 else
 {
  ADDRB=0;
 }
 if(ch&0x04!=0)
 {
  ADDRC=1;
 }
 else
 {
  ADDRC=0;
 }
 ALE=1;
 SOC=1;
 ALE=0;
 SOC=0;
 while(EOC==1);
 while(EOC==0);
 OE=1;
 value=ADC_BUS;
 OE=0;
 return val;
}

#endif