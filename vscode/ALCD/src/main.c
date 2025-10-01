#include "aKaReZa.h" // Include the header file for the aKaReZa module

const uint8_t coustmChar0[8] = {0x00,0x00,0x0A,0x00,0x11,0x0E,0x00,0x00}; // Define a custom character (a smiley face)
const uint8_t coustmChar1[8] = {0x00,0x1F,0x10,0x04,0x04,0x04,0x04,0x04}; // Define another custom character (Alef)
const uint8_t coustmChar2[8] = {0x00,0x15,0x15,0x1F,0x10,0x10,0x10,0x10}; // Define another custom character (3)
const uint8_t coustmChar3[8]=  {0x00,0x01,0x03,0x16,0x1c,0x08,0x00}; // Define another custom character (tik)
char alcd[17]; // Create a character array to hold the LCD display content

int main () 
{

  alcd_init(); // Initialize the LCD display
  alcd_customChar(1, coustmChar1); // Load the custom character into the LCD
  alcd_customChar(0, coustmChar0); // Load the custom character into the LCD
  alcd_customChar(2, coustmChar2); // Load the custom character into the LCD
  alcd_customChar(3, coustmChar3); // Load the custom character into the LCD
  alcd_gotoxy(0,0); // Move the cursor to the second line of the LCD
  alcd_putc(0); // Display the custom character on the LCD
  alcd_putc(1); // Display the custom character on the LCD
  alcd_putc(2); // Display the custom character on the LCD
  alcd_putc(3); // Display the custom character on the LCD
  alcd_gotoxy(0,1); // Move the cursor to the first line
  sprintf (alcd, "PI=%.5f", Math_Const_PI); // Format a string with a floating-point number
  alcd_gotoxy(0,0); // Move the cursor to the first line

  while(1) 
  {
  alcd_display(true); // Turn on the display
  delay_ms(1000); // Wait for 2 seconds
  alcd_display(false); // Turn off the display
  delay_ms(1000); // Wait for 2 seconds

  }


}