/*
 * isp.h - part of USBasp
 *
 * Autor..........: Thomas Fischl <tfischl@gmx.de>
 * Description....: Provides functions for communication/programming
 *                  over ISP interface
 * Licence........: GNU GPL v2 (see Readme.txt)
 * Creation Date..: 2005-02-23
 * Last change....: 2009-02-28
 */

#ifndef __isp_h_included__
#define	__isp_h_included__

#include "main_config.h"

#ifndef uchar
#define	uchar	unsigned char
#endif

#ifdef	ISP_OUT
#define	ISP_OUT   PORTB
#endif

#ifdef	ISP_IN 
#define ISP_IN    PINB
#endif

#ifdef	ISP_DDR
#define ISP_DDR   DDRB 
#endif

#ifdef	ISP_BUF
#define ISP_BUF   PB1
#endif

#ifdef	ISP_RST 
#define ISP_RST   PB2
#endif

#ifdef	ISP_MOSI
#define ISP_MOSI  PB3
#endif

#ifdef	ISP_MISO
#define ISP_MISO  PB4
#endif

#ifdef	ISP_SCK
#define ISP_SCK   PB5
#endif


/* Prepare connection to target device */
void ispConnect();

/* Close connection to target device */
void ispDisconnect();

/* read an write a byte from isp using software (slow) */
uchar ispTransmit_sw(uchar send_byte);

/* read an write a byte from isp using hardware (fast) */
uchar ispTransmit_hw(uchar send_byte);

/* enter programming mode */
uchar ispEnterProgrammingMode();

/* read byte from eeprom at given address */
uchar ispReadEEPROM(unsigned int address);

/* write byte to flash at given address */
uchar ispWriteFlash(unsigned long address, uchar data, uchar pollmode);

uchar ispFlushPage(unsigned long address, uchar pollvalue);

/* read byte from flash at given address */
uchar ispReadFlash(unsigned long address);

/* write byte to eeprom at given address */
uchar ispWriteEEPROM(unsigned int address, uchar data);

/* pointer to sw or hw transmit function */
uchar (*ispTransmit)(uchar);

/* set SCK speed. call before ispConnect! */
void ispSetSCKOption(uchar sckoption);

/* load extended address byte */
void ispLoadExtendedAddressByte(unsigned long address);

#endif /* __isp_h_included__ */
