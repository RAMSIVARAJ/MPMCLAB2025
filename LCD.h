#ifndef LCD_H
#define LCD_H

void lcd_busy(void);
void lcd_cmd(char);
void lcd_data(char);
void lcd_init(void);
void lcd_print(char*);

void lcd_cmd(char c)
{
 DATA_BUS=c;
 RS=0;
 RW=0;
 EN=1;
 EN=0;
 lcd_busy();
}

void lcd_data(char d)
{
 DATA_BUS=d;
 RS=1;
 RW=0;
 EN=1;
 EN=0;
 lcd_busy();
}

void lcd_busy(void)
{
 char st=0x80;
 DATA_BUS=0xFF;
 RS=0;
 RW=1;
 while(st==0x80)
 {
  EN=1;
  st=DATA_BUS&0x80;
  EN=0;
 }
}

void lcd_init(void)
{
 EN=0;
 lcd_busy();
 lcd_cmd(0x38);
 lcd_cmd(0x01);
 lcd_cmd(0x0C);
 lcd_cmd(0x06);
 lcd_cmd(0x80);
}

void lcd_print(char *p)
{
 while(*p!=0x00)
 {
  lcd_data(*p);
  *p++;
 }
}

#endif