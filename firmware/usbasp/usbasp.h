/*
 * usbasp.c - part of USBasp
 *
 * Autor..........: Thomas Fischl <tfischl@gmx.de>
 * Description....: Definitions and macros for usbasp
 * Licence........: GNU GPL v2 (see Readme.txt)
 * Creation Date..: 2009-02-28
 * Last change....: 2009-02-28
 */

#ifndef USBASP_H_
#define USBASP_H_

/* USB function call identifiers */
#define USBASP_FUNC_CONNECT     1
#define USBASP_FUNC_DISCONNECT  2
#define USBASP_FUNC_TRANSMIT    3
#define USBASP_FUNC_READFLASH   4
#define USBASP_FUNC_ENABLEPROG  5
#define USBASP_FUNC_WRITEFLASH  6
#define USBASP_FUNC_READEEPROM  7
#define USBASP_FUNC_WRITEEEPROM 8
#define USBASP_FUNC_SETLONGADDRESS 9
#define USBASP_FUNC_SETISPSCK 10
#define USBASP_FUNC_TPI_CONNECT      11
#define USBASP_FUNC_TPI_DISCONNECT   12
#define USBASP_FUNC_TPI_RAWREAD      13
#define USBASP_FUNC_TPI_RAWWRITE     14
#define USBASP_FUNC_TPI_READBLOCK    15
#define USBASP_FUNC_TPI_WRITEBLOCK   16
#define USBASP_FUNC_GETCAPABILITIES 127

#define	USBASP_FUNC_SET_EXT_CLK				
#define	USBASP_FUNC_UPDI_CONNECT			
#define	USBASP_FUNC_UPDI_DISCONNECT			
#define	USBASP_FUNC_UPDI_ENABLEPROG			
#define	USBASP_FUNC_UPDI_READFLASH			
#define	USBASP_FUNC_UPDI_WRITEFLASH			
#define	USBASP_FUNC_UPDI_READEEPROM
#define	USBASP_FUNC_UPDI_WRITEEEPROM
#define	USBASP_FUNC_UPDI_READFUSE
#define	USBASP_FUNC_UPDI_WRITEFUSE

//	---------------------------------------------------------	//

/* USBASP capabilities */
#define USBASP_CAP_0_TPI    0x01

/* programming state */
#define PROG_STATE_IDLE         0
#define PROG_STATE_WRITEFLASH   1
#define PROG_STATE_READFLASH    2
#define PROG_STATE_READEEPROM   3
#define PROG_STATE_WRITEEEPROM  4
#define PROG_STATE_TPI_READ     5
#define PROG_STATE_TPI_WRITE    6

#define	PROG_STATE_SPI_READ		
#define	PROG_STATE_SPI_WRITE	
#define	PROG_STATE_TWI_READ		
#define	PROG_STATE_TWI_WRITE	
#define	PROG_STATE_UART_READ		
#define	PROG_STATE_UART_WRITE	
#define	PROG_STATE_JTAG_READ		
#define	PROG_STATE_JTAG_WRITE	
#define	PROG_STATE_PDI_READ		
#define	PROG_STATE_PDI_WRITE	
#define	PROG_STATE_UPDI_READ		
#define	PROG_STATE_UPDI_WRITE	


/* Block mode flags */
#define PROG_BLOCKFLAG_FIRST    1
#define PROG_BLOCKFLAG_LAST     2

/* ISP SCK speed identifiers */
#define USBASP_ISP_SCK_AUTO   0
#define USBASP_ISP_SCK_0_5    1   /* 500 Hz */
#define USBASP_ISP_SCK_1      2   /*   1 kHz */
#define USBASP_ISP_SCK_2      3   /*   2 kHz */
#define USBASP_ISP_SCK_4      4   /*   4 kHz */
#define USBASP_ISP_SCK_8      5   /*   8 kHz */
#define USBASP_ISP_SCK_16     6   /*  16 kHz */
#define USBASP_ISP_SCK_32     7   /*  32 kHz */
#define USBASP_ISP_SCK_93_75  8   /*  93.75 kHz */
#define USBASP_ISP_SCK_187_5  9   /* 187.5  kHz */
#define USBASP_ISP_SCK_375    10  /* 375 kHz   */
#define USBASP_ISP_SCK_750    11  /* 750 kHz   */
#define USBASP_ISP_SCK_1500   12  /* 1.5 MHz   */
#define USBASP_ISP_SCK_3000   13  /* 3.0 MHz   */
#define USBASP_ISP_SCK_6000   14  /* 6.0 MHz   */
#define USBASP_ISP_SCK_12000   15  /* 12.0 MHz   */

/* macros for gpio functions */
/* ------------------------------------------------------------------------- */
/* ------------------------ General Purpose Macros ------------------------- */
/* ------------------------------------------------------------------------- */
/*
#define LED_CONCAT(a, b)            a ## b
#define LED_CONCAT_EXPANDED(a, b)   LED_CONCAT(a, b)

#define LED_OUTPORT(name)           LED_CONCAT(PORT, name)
#define LED_INPORT(name)            LED_CONCAT(PIN, name)
#define LED_DDRPORT(name)           LED_CONCAT(DDR, name)
*/

#define LED_PORT			PORTx(LED_PORT_NAME)
#define	LED_DDR				DDRx(LED_PORT_NAME)
#define	LED_RED				BITx(LED_PORT_NAME, LED_RED_BIT)
#define	LED_GREEN			BITx(LED_PORT_NAME, LED_GREEN_BIT)

#define ledRedOff()    		LED_PORT &= ~(1 << LED_RED)
#define ledRedOn()   		LED_PORT |= (1 << LED_RED)
#define ledRedToogle()   	LED_PORT ^= (1 << LED_RED)
#define ledGreenOff() 		LED_PORT &= ~(1 << LED_GREEN)
#define ledGreenOn() 		LED_PORT |= (1 << LED_GREEN)
#define ledGreenToogle() 	LED_PORT ^= (1 << LED_GREEN)

/*
#ifdef LED_POL
#if	LED_POL==LOW
#define ledRedOn()    	LED_PORT &= ~(1 << LED_RED_BIT)
#define ledRedOff()   	LED_PORT |= (1 << LED_RED_BIT)
#define ledGreenOn()  	LED_PORT &= ~(1 << LED_GREEN_BIT)
#define ledGreenOff() 	LED_PORT |= (1 << LED_GREEN_BIT)
#elif	LED_POL==HIGH
#define ledRedOff()   	LED_PORT &= ~(1 << LED_RED_BIT)
#define ledRedOn()		LED_PORT |= (1 << LED_RED_BIT)
#define ledGreenOff()  	LED_PORT &= ~(1 << LED_GREEN_BIT)
#define ledGreenOn() 	LED_PORT |= (1 << LED_GREEN_BIT)
#else
#define ledRedOn()    	LED_PORT &= ~(1 << LED_RED_BIT)
#define ledRedOff()   	LED_PORT |= (1 << LED_RED_BIT)
#define ledGreenOn()  	LED_PORT &= ~(1 << LED_GREEN_BIT)
#define ledGreenOff() 	LED_PORT |= (1 << LED_GREEN_BIT)
#endif
#endif

#ifndef LED_POL || (if LED_POL==LOW)
#define ledRedOn()    	LED_PORT &= ~(1 << LED_RED_BIT)
#define ledRedOff()   	LED_PORT |= (1 << LED_RED_BIT)
#define ledGreenOn()  	LED_PORT &= ~(1 << LED_GREEN_BIT)
#define ledGreenOff() 	LED_PORT |= (1 << LED_GREEN_BIT)
#endif

#define ledRedOn()    	PORTC &= ~(1 << PC1)
#define ledRedOff()   	PORTC |= (1 << PC1)
#define ledGreenOn()  	PORTC &= ~(1 << PC0)
#define ledGreenOff() 	PORTC |= (1 << PC0)

#define ledRedOff()    	PORTC &= ~(1 << PC1)
#define ledRedOn()   	PORTC |= (1 << PC1)
#define ledGreenOff() 	PORTC &= ~(1 << PC0)
#define ledGreenOn() 	PORTC |= (1 << PC0)
*/
#endif /* USBASP_H_ */
