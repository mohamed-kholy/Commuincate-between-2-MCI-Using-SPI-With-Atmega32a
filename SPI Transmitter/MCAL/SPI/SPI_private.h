#ifndef		SPI_PRIVATE_H_
#define		SPI_PRIVATE_H_



#define  SPDR			(*(volatile u8*) (0x2F) )
#define  SPSR			(*(volatile u8*) (0x2E) )
#define  SPCR			(*(volatile u8*) (0x2D) )


/* Macros Definiation to Make The Code More Readable  */
#define 			ENABLE					1
#define             DISABLE					0
#define 			LSB						0
#define             MSB						1
#define 			MASTER					1	
#define 			SLAVE					0
#define 			RISING					1
#define             FALLING					0
#define 			SAMPLE					1
#define             SETUP					0
#define				CLOCK_DIV_2_SPI2X		0b00
#define	            CLOCK_DIV_4				0b00
#define             CLOCK_DIV_8_SPI2X		0b01	
#define             CLOCK_DIV_16			0b01
#define             CLOCK_DIV_32_SPI2X		0b10
#define             CLOCK_DIV_64_SPI2X		0b10
#define             CLOCK_DIV_128			0b11

/* MACROS DEFINARION Of Register Pins */

/*			SPCR Register			*/
#define				SPIE			7	
#define				SPE				6
#define				DORD			5
#define				MSTR			4
#define				CPOL			3
#define				CPHA			2
#define				SPR1			1
#define				SPR0			0

/*			SPSR Register			*/
#define				SPIF			7	
#define				WCOL			6
#define				SPI2X			0

#define				SS				4
#define				MOSI			5
#define				MISO			6	
#define				SCK				7


#endif