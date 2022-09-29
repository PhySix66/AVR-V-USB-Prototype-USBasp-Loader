/*
 * clock.h - part of USBasp
 *
 * Autor..........: Thomas Fischl <tfischl@gmx.de>
 * Description....: Provides functions for timing/waiting
 * Licence........: GNU GPL v2 (see Readme.txt)
 * Creation Date..: 2005-02-23
 * Last change....: 2006-11-16
 */

#ifndef __clock_h_included__
#define	__clock_h_included__

#ifndef F_CPU
#define F_CPU           12000000L   /* 12MHz */
#endif
#define	TIMERVALUE      TCNT2
#define clockInit()		TCCR2B |= (1 << CS22);

#define CLOCK_T_320us	60
/*
#if F_CPU == 12000000L
#define CLOCK_T_320us	60
//#pragma "F_CPU == 12000000L"

#elif	F_CPU == 16000000L
#define CLOCK_T_320us	80
//#pragma "F_CPU == 16000000L"

#else
#error	"F_CPU not defined or not valid value! - clock.h"
#endif
*/

/* wait time * 320 us */
void clockWait(uint8_t time);

#endif /* __clock_h_included__ */
