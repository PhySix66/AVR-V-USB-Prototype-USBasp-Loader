/* Name: main_config.h
 * Author: PhySix66
 * Creation Date..: 2005-02-20
 * Last change....: 2022-09-17
 * License: GNU GPL v2 (see License.txt) or proprietary (CommercialLicense.txt) or (see Readme.txt)
 */

#ifndef __main_config_h_included__
#define __main_config_h_included__

#include <avr/io.h>
#include "general_purpose_macros.h"

#ifndef	F_CPU
	#define F_CPU           12000000UL   /* 12MHz */
#endif

//	Enable for some debug features
// #define	SHOW_PRAGMA

/* --------------------------- main.c File ------------------------------- */
/* --------------------- USBasp Port, Pin Config ------------------------- */
#define	SlowSCK_PORTNAME	D
#define	SlowSCK_BIT			5
#define	SlowSCK_PORT		PORTx(SlowSCK_PORTNAME)
#define	SlowSCK_DDR			DDRx(SlowSCK_PORTNAME)
#define	SlowSCK_PIN			PINx(SlowSCK_PORTNAME)

#define LED_PORT_NAME		C
#define	LED_RED_BIT			1
#define	LED_GREEN_BIT		0
#define	LED_POL				HIGH		//LED_POL	LOW -> output active low; HIGH -> output active high

#define	RST_PORT			PORTB
#define	RST_DDR				DDRB
#define	RST_PIN				PB2
//#define	HV_PIN			PB1

/* --------------------------- isp.h File ---------------------------- */
/* --------------------- ISP Port, Pin Config ------------------------- */
#define	ISP_OUT   			PORTB
#define ISP_IN    			PINB
#define ISP_DDR   			DDRB
//#define ISP_BUF   		PB1
#define ISP_RST   			PB2
#define ISP_MOSI  			PB3
#define ISP_MISO  			PB4
#define ISP_SCK   			PB5

/* --------------------------- tpi.S File ---------------------------- */
/* --------------------- TPI Port, Pin Config ------------------------- */
#define	TPI_INTERFACE_DEF	1		// ifndef definitions are loaded from tpi.S

#ifdef	TPI_INTERFACE_DEF
	#define TPI_CLK_PORT PORTC
	#define TPI_CLK_DDR DDRC
	#define TPI_CLK_BIT 3
	#define TPI_DATAOUT_PORT PORTC
	#define TPI_DATAOUT_DDR DDRC
	#define TPI_DATAOUT_BIT 2
	#ifdef TPI_WITH_OPTO
	#	define TPI_DATAIN_PIN PINC
	#	define TPI_DATAIN_DDR DDRC
	#	define TPI_DATAIN_BIT 1
	#else
	#	define TPI_DATAIN_PIN PINC
	#	define TPI_DATAIN_BIT 2
	#endif
#endif

/* ------------------------------ usbconfig.h ------------------------------ */
/* ---------------------------- Hardware Config ---------------------------- */
#ifndef	USB_CFG_IOPORTNAME
	//#define USB_CFG_IOPORTNAME		B
#endif
#ifndef	USB_CFG_DMINUS_BIT
	//#define USB_CFG_DMINUS_BIT		1
#endif
#ifndef	USB_CFG_DPLUS_BIT
	//#define USB_CFG_DPLUS_BIT		0
#endif

/* ----------------------- Optional Hardware Config ------------------------ */
#ifndef	USB_CFG_PULLUP_IOPORTNAME
	#define USB_CFG_PULLUP_IOPORTNAME   D	
#endif
#ifndef	USB_CFG_PULLUP_BIT
	#define USB_CFG_PULLUP_BIT          7	
#endif

/* ---------------------- USB Interrupt Vector Select ---------------------- */
#define	USB_INTR_TYPE_INTx			1		//	INT0..2
#define	USB_INTR_TYPE_PCINTx		2		//	PIN Change Interrupt(0..3)
#define	USB_INTR_TYPE_ICPx			3		//	ICP (Input Capture Pin)

//#define	USB_INTR_SEL		USB_INTR_TYPE_PCINTx

/* -------------------------- Device Description --------------------------- */
#define  USB_CFG_VENDOR_ID  0xc0, 0x16  /* 5824 in dec, stands for VOTI */
#define USB_CFG_DEVICE_ID   0xdc, 0x05  /* 1500 in dec, obdev's free PID */

#define USB_CFG_MAX_BUS_POWER           400

#define	USB_CFG_VENDOR_NAME     'P', 'h', 'y', 'S', 'i', 'x', '6', '6'
#define USB_CFG_VENDOR_NAME_LEN 8

#define	USB_CFG_DEVICE_NAME		'U', 'S', 'B', 'a', 's', 'p', 'C', 'l', 'o', 'n', 'e'
#define	USB_CFG_DEVICE_NAME_LEN	11

#endif