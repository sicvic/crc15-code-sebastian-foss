#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t daten=0xC08000;

//uint32_t daten=0xC0A3AC;
uint32_t poly=0xC599; // CAN Polynom

uint8_t datenbits = 24;
uint32_t crc15 = 0; 

 
int main(void)
{
 int i, j=0;
 
 printf("%c",201);
 for(i=0;i<14;i++) printf("%c",205);
 printf("%c\n",187);
 printf("%cCRC-Berechnung%c\n",186,186);
 printf("%c",200);
 for(i=0;i<14;i++) printf("%c",205);
 printf("%c\n",188);
 
 printf("Daten: 0x%04X\nPolynom: 0x%04X \n", daten,poly);

while(!((daten&(poly<<j))>>datenbits-1))j++;
  
  poly<<=j;
         
  crc15=daten;
         
  for(i=0;i<=j;i++){    	
  	if((crc15&poly)>>(datenbits-1)) crc15=crc15^poly; else {   poly>>=1;datenbits--;}    	 
  }
         
             
    printf("Ergebnis: 0x%04X\n", crc15);
    
    return EXIT_SUCCESS;
}
