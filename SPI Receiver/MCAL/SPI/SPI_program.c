#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "../DIO/MDIO_interface.h"

#define			ENTER_ASCII			13

void MSPI_voidSPIinit(void)
{

	/* Select if the SPI mode is Master Or Slave */
	#if   MASTER_SLAVE_SELECT == MASTER
		SET_BIT (SPCR , MSTR );
		/*	Configure Pins */
		MDIO_voidSetPinDirection(GPIOB,PIN4,HIGH);
		MDIO_voidSetPinDirection(GPIOB,PIN5,HIGH);
		MDIO_voidSetPinDirection(GPIOB,PIN7,HIGH);
		MDIO_voidSetPinDirection(GPIOB,PIN6,LOW);
		MDIO_voidSetPinValue(GPIOB,PIN4,HIGH);
	#elif MASTER_SLAVE_SELECT == SLAVE
		CLR_BIT (SPCR , MSTR );
		//MDIO_voidSetPinDirection(GPIOB,PIN4,LOW);
		//MDIO_voidSetPinDirection(GPIOB,PIN5,LOW);
		//MDIO_voidSetPinDirection(GPIOB,PIN7,LOW);
		MDIO_voidSetPinDirection(GPIOB,PIN6,HIGH);
	#endif
	/* Select if the Clock Polarity is Rising Or Falling */
	#if    CLOCK_POLARITY == RISING
		CLR_BIT (SPCR , CPOL );
	#elif CLOCK_POLARITY == FALLING
		SET_BIT (SPCR , CPOL );
	#endif
	/* Select if the Clock Phase is Sample Or Setup */
	#if CLOCK_PHASE == SAMPLE
		CLR_BIT (SPCR , CPHA );
	#elif CLOCK_PHASE == SETUP
		SET_BIT (SPCR , CPHA );
	#endif
	/* Select if Transmit LSB or MSB First */
	#if DATA_ORDER == LSB
		SET_BIT (SPCR , DORD );
	#elif DATA_ORDER == MSB
		CLR_BIT (SPCR , DORD );
	#endif
	/* Enable or disable Double Speed Transmit*/
	#if DOUBLE_SPI_SPEED == ENABLE
		SET_BIT (SPSR , SPI2X );
	#elif DOUBLE_SPI_SPEED == DISABLE
		CLR_BIT (SPSR , SPI2X );
	#endif
	/* Select Prescaler*/
		SPCR |= CLOCK_FREQENCY ;
	/* Enable Or Disable SPI Interrupt */
	#if SPI_INTERRUPT == ENABLE
		SET_BIT (SPCR  , SPIE );
	#elif SPI_INTERRUPT == DISABLE
		CLR_BIT (SPCR  , SPIE );
	#endif
	/* Enable SPI */
	#if SPI == ENABLE
		SET_BIT (SPCR , SPE);
	#elif SPI == DISABLE
		CLR_BIT (SPCR , SPE);
	#endif
	
	
}
void MSPI_voidSPISendChar (u8 copy_u8Data)
{
	MDIO_voidSetPinValue(GPIOB,PIN4,LOW);
	/* Send The Data */
	SPDR = copy_u8Data ;
	/* Wait Till The Data is Transmitted */
	while (!GET_BIT (SPSR , SPIF) );
	MDIO_voidSetPinValue(GPIOB,PIN4,HIGH);
}
u8 MSPI_u8SPIReceiveChar(void)
{
	u8 local_u8ReturnData ;
	/* Wait until the Data is Transmitted Completely */
	while (!GET_BIT (SPSR , SPIF));
	/* Return The Data */
	local_u8ReturnData = SPDR ;
	return   local_u8ReturnData ;
	
}


void MSPI_voidSPISendString (u8 *copy_u8PtrStr)
{
	/* local Variable */
	u8 local_u8Indx = 0 ;
	/* If the incoming Data not Empty */
	while(copy_u8PtrStr[local_u8Indx] != '\0')
	{
		/* Send Every Char */
		MSPI_voidSPISendChar(copy_u8PtrStr[local_u8Indx]);
		/* increment The Index */
		local_u8Indx++;
	}
}

void MSPI_voidReceiveString (u8 *copy_u8PtrStr)
{
	/* local Index */
	u8 local_u8Indx = 0 ;
	/* Receive the First char And Store it in the incoming Array */
	copy_u8PtrStr[local_u8Indx] = MSPI_u8SPIReceiveChar() ;
	/* Stop When the User press Enter */
	while(copy_u8PtrStr[local_u8Indx]  != ENTER_ASCII)
	{
		/* increment the index */
		local_u8Indx++;
		/* Receive every character and store it in the incoming Array */
		copy_u8PtrStr[local_u8Indx] = MSPI_u8SPIReceiveChar() ;
		
	}
	/* Clear the last Char */
	copy_u8PtrStr[local_u8Indx] ='\0';
}
