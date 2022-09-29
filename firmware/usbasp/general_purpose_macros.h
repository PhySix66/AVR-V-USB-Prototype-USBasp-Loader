#ifndef	_general_purpose_macros_h
#define	_general_purpose_macros_h		1

/* ------------------------------------------------------------------------- */
/* ------------------------ General Purpose Macros ------------------------- */
/* ------------------------------------------------------------------------- */

#define CONCAT(a, b)            				a ## b
#define CONCAT_EXPANDED(a, b)   				CONCAT(a, b)

/* ------------------------------------------------------------------------- */
/* ---------------------------- PORT Macros -------------------------------- */
/* ------------------------------------------------------------------------- */
#define	PORTx(name)								CONCAT(PORT,name)
#define	DDRx(name)								CONCAT(DDR,name)
#define	PINx(name)								CONCAT(PIN,name)
#define	BITx(port,bit)							CONCAT_EXPANDED(P, CONCAT_EXPANDED(port,bit))

#define	PORT_NUMx(num)							CONCAT(PORT_NUM_,num)

#define	PORT_NUM_0								0
#define	PORT_NUM_1								1
#define	PORT_NUM_2								2
#define	PORT_NUM_3								3
#define	PORT_NUM_4								4
#define	PORT_NUM_5								5

#define	PORT_NUM_A								PORT_NUM_0
#define	PORT_NUM_B								PORT_NUM_1
#define	PORT_NUM_C								PORT_NUM_2
#define	PORT_NUM_D								PORT_NUM_3
#define	PORT_NUM_E								PORT_NUM_4
#define	PORT_NUM_F								PORT_NUM_5

#define	SET_PIN_OUTPUT(DDR,PIN)					DDR |= (1<<PIN);
#define	SET_PIN_INPUT(DDR,PIN)					DDR &= ~(1<<PIN);

/* ------------------------------------------------------------------------- */
/* ------------------------- USB Precompile Fix ---------------------------- */
/* ------------------------------------------------------------------------- */


#endif