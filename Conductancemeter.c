// LCD module connetcions
sbit LCD_RS at LATE0_bit;
sbit LCD_EN at LATE1_bit;
sbit LCD_D4 at LATC1_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATC0_bit;
sbit LCD_D7 at LATB0_bit;
sbit LCD_RS_Direction at TRISE0_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISC1_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISC0_bit;
sbit LCD_D7_Direction at TRISB0_bit;
// LCD module connections

unsigned int ADC_Value, i ,conductivity ;
unsigned long int ADC_Value_t = 0, conductivitylong, ADC_long_Value ;
char txt[6];

void main()
{
   ANCON0=0b11111011;
   ANCON1=0b00011111;

   ADCON0=0;
   ADCON1=0;
   
   Lcd_Init(); // performs Lcd initialization
   Lcd_Cmd(_LCD_CLEAR); // clear Lcd
   Lcd_Cmd(_LCD_CURSOR_OFF); // set cursor off
   Lcd_Out(1,1,"sigma");

   while(1)
  { 
     ADC_Value_t = 0;
     for ( i = 0; i<10 ; i++)
     {
        ADC_Value = ADC_Read(2); // Read AN2
        ADC_Value_t = ADC_Value_t + ADC_Value;
        //delay_ms(10);
     }
  

    //ADC_Value = ADC_Value_t/10;
    
    conductivitylong = (1244380/ADC_Value_t);
 
    conductivity = conductivitylong;
    
    WordToStr(conductivity,txt);
    Lcd_Out(2,1,txt);
    //Lcd_Out_Cp("us/m");
    delay_ms(100); // Pause 10ms
   }
}

print lmdlkjmf
