#ifndef		SPI_CONFIG_H_
#define		SPI_CONFIG_H_

/* OPTIONS
	* ENABLE
	* DISABLE
*/

#define 		SPI						ENABLE


/* OPTIONS
	* ENABLE
	* DISABLE
*/
#define 		SPI_INTERRUPT			DISABLE


/* OPTIONS
	*	LSB
	*	MSB
*/
#define 		DATA_ORDER				LSB

/* OPTIONS
	*	MASTER
	*	SLAVE
*/
#define 		MASTER_SLAVE_SELECT		SLAVE

/*	OPTIONS
	* RISING
	* FALLING
*/

#define 		CLOCK_POLARITY			RISING
/* OPTIONS
	*	SAMPLE
	* 	SETUP
*/
#define 		CLOCK_PHASE				SAMPLE

/* OPTIONS
	* ENABLE
	* DISABLE
*/

#define 		DOUBLE_SPI_SPEED		ENABLE

/* OPTIONS
	* 	CLOCK_DIV_2_SPI2X
	*	CLOCK_DIV_4
	*	CLOCK_DIV_8_SPI2X
	*	CLOCK_DIV_16
	*	CLOCK_DIV_32_SPI2X
	*	CLOCK_DIV_64_SPI2X
	*	CLOCK_DIV_128
*/
#define 		CLOCK_FREQENCY			CLOCK_DIV_8_SPI2X



#endif