#include<xc.h>

#define _XTAL_FREQ 20000000

void main(void) 
{  
  SPI_Master_Init(); // Initialize The SPI in Master Mode @ Fosc/64 SCK
  unsigned char s1='A';

  while(1)
  {
    if (Send) // Send The Current Data Value Via SPI
    {
      SPI_Write(Data);
      __delay_ms(250);
    }
    PORTD = Data; // Display The Current Data Value @ PORTD
  }
  return;
}