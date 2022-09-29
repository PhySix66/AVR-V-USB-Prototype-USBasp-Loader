# AVR+V-USB Prototype USBasp+Loader
AVR Projects based on V-USB. USBasp, USBaspLDR(Bootloader)...

This is jet another version of the USBasp and the USBaspLDR (USBasp BootLoader).
My PCB designs are in the images folder. Rev.: 1.3 is in use, rev. 1.4 is still in the tweeking/upgrade phase.

The usbdrv directory is a copy of (someone from github) because:
vusb-20121206 version and avr-gcc 9.2.0 will compile without error, but the generated code won't connect to PC. (USB ERROR).
Testing avr-gcc 11.1.0 and 12.1.0 (2022.09).
