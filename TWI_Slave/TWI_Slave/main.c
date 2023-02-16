/*
 * TWI_Slave.c
 *
 * Created: 16.02.2023 08:26:21
 * Author : avm
 */ 
#define F_CPU 3686400UL
#include <avr/io.h>


uint8_t TWI_SR()
{
	TWCR=0b11000100; // TWINT=1, TWEA=1, TWEN=1
	while((TWCR&(1<<TWINT)) == 0); // warte auf TWINT=1
	return TWDR; // Daten zurückgeben
}
int main(void)
{
	DDRB|=0x01; // PB0 zur Ausgabe
	TWAR=0b00000010; // Slave-Adresse 0x02, TWGCE=0
	while(1)
	{
		if(TWI_SR()==0x01) PORTB^=0x01;
	}
}

