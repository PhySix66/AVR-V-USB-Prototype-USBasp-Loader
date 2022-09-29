#ifndef		_EEPROM_INTERNAL_DATA_H_
#define		_EEPROM_INTERNAL_DATA_H_	1

//	Some Strings in Flash
const unsigned char Compile_Date[]	PROGMEM = "2022.09.26\0";
const unsigned char DevName[]	PROGMEM 	=	"USBaspClone\0";
const unsigned char DevVersion[]	PROGMEM 	=	"RC3\0";
const unsigned char MCU[]	PROGMEM 	=	TARGET"\0";
const unsigned char USB_Vendor_Name[] 	PROGMEM 	=	"PhySix66\0";
const unsigned int USB_VID	PROGMEM 	=  0x160C;
const unsigned int USB_PID	PROGMEM 	=	0x05DC;

EEMEM union ROM_USBasp_Settings_Array
{
	struct
	{
		unsigned char avr_gcc = AVR_GCC_VER;
		unsigned char target = ;
		unsigned char target_mhz = TARGET_MHZ;
		unsigned int fcpu= F_CPU;
		unsigned char usb_cfg_ioportname = PORT_NUMx(USB_CFG_IOPORTNAME);
		unsigned char usb_cfg_dplus_bit = USB_CFG_DPLUS_BIT;
		unsigned char usb_cfg_dminus_bit = USB_CFG_DMINUS_BIT;
		unsigned char usb_int = TRGT_INT;
		unsigned char usb_cfg_pullup_ioportname = PORT_NUMx(USB_CFG_PULLUP_IOPORTNAME);
		unsigned char usb_cfg_pullup_bit = USB_CFG_PULLUP_BIT;
		unsigned char slowsck_portname = PORT_NUMx(SlowSCK_PORTNAME;
		unsigned char slowsck_bit = SlowSCK_BIT;
	};
	unsigned char	eeprom_b[16];
}ROM_USBasp_Settings_Array =
{
	
};

#endif