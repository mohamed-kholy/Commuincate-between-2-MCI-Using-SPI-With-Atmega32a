/*
 * SPI Transmitter.c
 *
 * Created: 9/26/2021 12:09:32 AM
 * Author : Mohamed El-Kholy
 */ 

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO/MDIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"

int main(void)
{
	/* Initialize SPI as Master Device */
    MSPI_voidSPIinit();
	/* Send A Char */
	MSPI_voidSPISendChar(7);

    while (1);
}

