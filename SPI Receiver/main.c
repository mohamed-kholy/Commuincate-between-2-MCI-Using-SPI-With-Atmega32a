/*
 * SPI Receiver.c
 *
 * Created: 9/26/2021 12:13:46 AM
 * Author : Mohamed El-Kholy
 */ 
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/DIO/MDIO_interface.h"

int main(void)
{
	/*initialize PortA as Output */
	MDIO_voidSetPortDirection(GPIOA,HIGH);
	/* local variable holds The Received Data */
	u8 local_u8Received ;
	/* Initialize SPI as Slave */
    MSPI_voidSPIinit();
	/* Read The Received Data from Spi */
	local_u8Received = MSPI_u8SPIReceiveChar();
	/* Display The Received Data on PortA */
	MDIO_voidSetPortValue(GPIOA , local_u8Received );
	
    while (1) ;
}

