/*
 * clock_pulse.h - part of USBasp
 *
 * Autor..........: PhySix66
 * Description....: Provides functions for External Clock Source to Target
 * Licence........: GNU GPL v2 (see Readme.txt)
 * Creation Date..: 2022-07-28
 * Last change....: 2022 (RC)
 */

#ifndef __clock_pulse_h_included__
#define	__clock_pulse_h_included__

#define CLK_PULSE_PORT	PORTD
#define CLK_PULSE_DDR	DDRD
#define CLK_PULSE_PIN	PD6

unsigned int Calc_OCR(unsigned int target_khz)
{
	unsigned int clk_speed_khz = F_CPU/1000;
	
	unsigned int ret_ocr = (clk_speed_khz/(target_khz*2))-1;
	
	return(ret_ocr);
}

void clockpulseInit(void)
{
	/* set prescaler to 1 */
	TCCR0A |= ((1 << COM0A0)|(1 << WGM01));		//	Toggle OC0A on Compare Match, CTC Mode
	TCCR0B |= (1 << CS00);						//	CLK Set to F_CPU, no prescaling
	OCR0A = 0;
	CLK_PULSE_DDR |= (1 << CLK_PULSE_PIN);
}

#endif /* __clock_pulse_h_included__ */