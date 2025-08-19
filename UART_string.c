#include<xc.h>

#define _XTAL_FREQ 20000000

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

void UART_init(void);
void UART_Transmit(char *);

void main()
{
    UART_init();
    int count1=1;
    char arr[]="hello world\n";
    for(int i=0;i<10;i++)
    {
       
          UART_Transmit (arr);  
        __delay_ms(1000);  
      
        
        
    }   
}
void UART_init()
{
    TRISC6 =0;
    TRISC7 =1;
    SPBRG=32;
    BRGH = 0;
    SYNC=0;
    
    CREN=1;
    SPEN=1; 
    TXEN=1;
    
}

void UART_Transmit(char *arr)
{
  
 
    for(int i=0;i<11;i++)
    {  
        while (!TXIF);
         if(i<=10)
    {
             TXEN=1;
    }
    else
    {
        TXEN=0;
    }
        TXREG = arr[i];
    }
   
    
}
/*#include <xc.h>
#include <string.h>  // Add this!

#define _XTAL_FREQ 20000000

// CONFIG
#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

void UART_init(void);
void UART_Transmit(char *);

void main()
{
    UART_init();
    char arr[] = "hello world\n";

    for(int i = 0; i < 5; i++)
    {
        UART_Transmit(arr);
        __delay_ms(1000);
    }
    while(1);
}

void UART_init()
{
    TRISC6 = 0;  // TX as output
    TRISC7 = 1;  // RX as input

    SPBRG = 32;  // For 9600 baud with 20MHz
    BRGH = 0;    // Low speed
    SYNC = 0;    // Async mode
    SPEN = 1;    // Serial port enable
    CREN = 1;    // Enable receiver
    TXEN = 1;    // Enable transmitter
}

void UART_Transmit(char *arr)
{
    for(int i = 0; i < 11; i++)
    {
        while (!TXIF);      // Wait until TXREG is empty
        TXREG = arr[i];     // Send character
   }
}*/
