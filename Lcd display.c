#include <reg51.h>

#define LCD_DATA P2

sbit rs = P0^0;
sbit rw = P0^1;
sbit en = P0^2;

void init_LCD(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char val);
void LCD_write_string(char *str);
void msdelay(unsigned int time);

void main(void)
{
    char var1[] = "WELCOME TO ";
    char var2[] = "TKIET WARANA";

    init_LCD();
    msdelay(50);

    LCD_command(0x80);
    msdelay(15);

    LCD_write_string(var1);
    msdelay(15);

    LCD_command(0xC0);
    msdelay(15);

    LCD_write_string(var2);
    msdelay(15);

    while(1);
}

void msdelay(unsigned int time)
{
    unsigned int i, j;

    for(i = 0; i < time; i++)
    {
        for(j = 0; j < 113; j++);
    }
}

void init_LCD(void)
{
    LCD_command(0x38);
    msdelay(15);

    LCD_command(0x01);
    msdelay(15);

    LCD_command(0x0C);
    msdelay(15);
}

void LCD_write_string(char *str)
{
    int i = 0;

    while(str[i] != 0)
    {
        LCD_data(str[i]);
        msdelay(15);
        i++;
    }
}

void LCD_command(unsigned char cmd)
{
    LCD_DATA = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    msdelay(15);
    en = 0;
}

void LCD_data(unsigned char val)
{
    LCD_DATA = val;
    rs = 1;
    rw = 0;
    en = 1;
    msdelay(15);
    en = 0;
}
