#
#   Makefile for usbasp
#   20061119   Thomas Fischl        original
#   20061120   Hanns-Konrad Unger   help: and TARGET=atmega48 added
#

# ISP=bsd      PORT=/dev/parport0
# ISP=ponyser  PORT=/dev/ttyS1
# ISP=stk500   PORT=/dev/ttyS1
# ISP=usbasp   PORT=/dev/usb/ttyUSB0
# ISP=stk500v2 PORT=/dev/ttyUSB0
ISP=usbaspldr
PORT=/dev/usb/ttyUSB0

# Init Vars for Single Compile
# TARGET=atmega8    HFUSE=0xc9  LFUSE=0xef
# TARGET=atmega48   HFUSE=0xdd  LFUSE=0xff
# TARGET=at90s2313
TARGET=atmega88p
HFUSE=0xc9
LFUSE=0xef
AVR_GCC_VER=-9.2.0

TRGT_MHZ=16
TRGT_INT=PCINTx
USB_CFG_IOPORTNAME=D
USB_CFG_DMINUS_BIT=3
USB_CFG_DPLUS_BIT=2
USB_CFG_PULLUP_IOPORTNAME=D
USB_CFG_PULLUP_BIT=7
SlowSCK_PORTNAME=D
SlowSCK_BIT=5

# Init variables for BATCH compiling
BATCH_TYPE = combo
# this section is for build all batch types
# WARNING!!! this also builds bad PORT and Interrupt combinations!!!
TARGETS = atmega88pa atmega88p atmega168p atmega328p
TRGT_MHZs = 12 16 18 20
TRGT_PORTS = B D
TRGT_DPLUS_PINS = 0 1 2 3
TRGT_DMINUS_PINS = 0 1 2 3
TRGT_INTS = PCINTx ICPx INTx
USB_CFG_PULLUP_IOPORTNAMES = D
USB_CFG_PULLUP_BITS = 7
SlowSCK_PORTNAMES = D
SlowSCK_BITS = 5

# Column Vars
# this is for specific combinations, 1 column == 1 combination
TRGT_COL_PORTS = B B B D D D D
TRGT_COL_DPLUS_PINS = 0 1 0 2 3 2 3
TRGT_COL_DMINUS_PINS = 1 0 1 3 2 3 2
TRGT_COL_INTS = PCINTx PCINTx ICPx INTx INTx PCINTx PCINTx
USB_COL_CFG_PULLUP_IOPORTNAME= D D D D D D D
USB_COL_CFG_PULLUP_BIT= 7 7 7 7 7 7 7
SlowSCK_COL_PORTNAME= D D D D D D D
SlowSCK_COL_BIT= 5 5 5 5 5 5 5

# Don't TOUCH these!!!
##		-----------------------------------------------		##
USB_INTR_SEL_PRETXT=USB_INTR_TYPE_
USB_INTR_SEL=$(USB_INTR_SEL_PRETXT)$(TRGT_INT)
TRGT_PORT=PORT$(USB_CFG_IOPORTNAME)
TRGT_FILE_NAME=$(TARGET)_$(TRGT_MHZ)Mhz_$(TRGT_PORT)_$(TRGT_INT)
WS = 1

F_CPU=$(TRGT_MHZ)000000
CDEFS = -DF_CPU=$(F_CPU)UL
CDEFS += -DUSB_CFG_IOPORTNAME=$(USB_CFG_IOPORTNAME)
CDEFS += -DUSB_CFG_DMINUS_BIT=$(USB_CFG_DMINUS_BIT)
CDEFS += -DUSB_CFG_DPLUS_BIT=$(USB_CFG_DPLUS_BIT)
CDEFS += -DUSB_INTR_SEL=$(USB_INTR_SEL)

#SUB_DIR_USPASP_PINS="("USB_PULL" "P$(USB_CFG_PULLUP_IOPORTNAME)$(USB_CFG_PULLUP_BIT)")("SLOW" "P$(SlowSCK_PORTNAME)$(SlowSCK_BIT)")"
SUB_DIR=USB"("D-" "P$(USB_CFG_IOPORTNAME)$(USB_CFG_DMINUS_BIT)")("D+" "P$(USB_CFG_IOPORTNAME)$(USB_CFG_DPLUS_BIT)")"
BATCH_DIR=Compiled" "Hex" "Files/$(TARGET)/$(TRGT_MHZ)Mhz/USB_PORT$(USB_CFG_IOPORTNAME)/USB_INT_"("$(TRGT_INT)")"/$(SUB_DIR)
##		-----------------------------------------------		##

begin:
	@echo
	@echo $(MSG_BEGIN)

end:
	@echo $(MSG_END)
	@echo


# Display size of file.
HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
ELFSIZE = $(SIZE) --mcu=$(MCU) --format=avr $(TARGET).elf

sizebefore:
	@if test -f $(TARGET).elf; then echo; echo $(MSG_SIZE_BEFORE); $(ELFSIZE); \
	2>/dev/null; echo; fi

sizeafter:
	@if test -f $(TARGET).elf; then echo; echo $(MSG_SIZE_AFTER); $(ELFSIZE); \
	2>/dev/null; echo; fi
	
# Display compiler version information.
gccversion : 
	@$(CC) --version
	
VERSION_FILE = version.h

version: $(VERSION_FILE)
	@echo '#ifndef		_VERSION_H_' > $(VERSION_FILE) 
	@echo '#define		_VERSION_H_' >> $(VERSION_FILE)
	@echo '#include	<avr/pgmspace.h>' >> $(VERSION_FILE) 
	@echo '//data from date_precompiled.exe' >> $(VERSION_FILE)
	@DateTime_PreCompiled >> $(VERSION_FILE)
	@echo '#endif' >> $(VERSION_FILE)

CONFIG_FILE = export_config.txt

config: $(CONFIG_FILE)
	@echo '// Compile Settings for $(TARGET)' > $(CONFIG_FILE)
	@echo '// Compiler Version	avr-gcc$(AVR_GCC_VER)' >> $(CONFIG_FILE)
	@echo '// These values are loaded from makefile.' >> $(CONFIG_FILE)
	@echo '#define	TARGET						$(TARGET)' >> $(CONFIG_FILE)
	@echo '#define	TRGT_MHZ					$(TRGT_MHZ)' >> $(CONFIG_FILE)
	@echo '#define	F_CPU:						$(F_CPU)' >> $(CONFIG_FILE)
	@echo '// USB Settings:	' >> $(CONFIG_FILE)
	@echo '#define	USB_CFG_IOPORTNAME:			$(USB_CFG_IOPORTNAME)' >> $(CONFIG_FILE)
	@echo '#define	USB_CFG_DPLUS_BIT:			$(USB_CFG_DPLUS_BIT)' >> $(CONFIG_FILE)
	@echo '#define	USB_CFG_DMINUS_BIT:			$(USB_CFG_DMINUS_BIT)' >> $(CONFIG_FILE)
	@echo '#define	USB Interrupt:				$(TRGT_INT)' >> $(CONFIG_FILE)
	@echo '#define	USB_CFG_PULLUP_IOPORTNAME	$(USB_CFG_PULLUP_IOPORTNAME)'>> $(CONFIG_FILE)
	@echo '#define	USB_CFG_PULLUP_BIT			$(USB_CFG_PULLUP_BIT)'>> $(CONFIG_FILE)
	@echo '#define	SlowSCK_PORTNAME			$(SlowSCK_PORTNAME)'>> $(CONFIG_FILE)
	@echo '#define	SlowSCK_BIT					$(SlowSCK_BIT)'>> $(CONFIG_FILE)
	@echo '#endif' >> $(CONFIG_FILE)

help:
	@echo "Usage: make                same as make help"
	@echo "       make help           same as make"
	@echo "       make main.hex       create main.hex"
	@echo "       make clean          remove redundant data"
	@echo "       make disasm         disasm main"
	@echo "       make flash          upload main.hex into flash"
	@echo "       make fuses          program fuses"
	@echo "       make avrdude        test avrdude"
	@echo "Current values:"
	@echo "       TARGET=${TARGET}"
	@echo "       LFUSE=${LFUSE}"
	@echo "       HFUSE=${HFUSE}"
	@echo "       CLOCK=12000000"
	@echo "       ISP=${ISP}"
	@echo "       PORT=${PORT}"
	

COMPILE = avr-gcc$(AVR_GCC_VER) -Wall -O2 -Iusbdrv -I. $(CDEFS) -mmcu=$(TARGET) # -DDEBUG_LEVEL=2

OBJECTS = usbdrv/usbdrv.o usbdrv/usbdrvasm.o usbdrv/oddebug.o isp.o clock.o tpi.o main.o

.c.o:
	$(COMPILE) -c $< -o $@
#-Wa,-ahlms=$<.lst

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(COMPILE) -S $< -o $@

clean:
	rm -f main.hex main.lst main.obj main.cof main.list main.map main.eep.hex main.bin *.o main.s usbdrv/*.o

# file targets:
main.bin:	$(OBJECTS)
	$(COMPILE) -o main.bin $(OBJECTS) -Wl,-Map,main.map

main.hex:	clean main.bin config
	rm -f main.hex main.eep.hex
	avr-objcopy -j .text -j .data -O ihex main.bin main.hex
	@if [ -a main.hex ] ; then \
	mkdir -p $(BATCH_DIR)/ ;\
	cp -f main.hex $(BATCH_DIR)/main.hex ;\
	cp -f main.hex $(BATCH_DIR)/$(TRGT_FILE_NAME).hex ;\
	cp -f export_config.txt $(BATCH_DIR)/config.txt ;\
	fi;

#	./checksize main.bin
# do the checksize script as our last action to allow successful compilation
# on Windows with WinAVR where the Unix commands will fail.

build_ws:
	make main.hex USB_CFG_IOPORTNAME=$(word $(WS), $(TRGT_COL_PORTS)) USB_CFG_DPLUS_BIT=$(word $(WS), $(TRGT_COL_DPLUS_PINS)) USB_CFG_DMINUS_BIT=$(word $(WS), $(TRGT_COL_DMINUS_PINS)) TRGT_INT=$(word $(WS), $(TRGT_COL_INTS))

build_batch:
	@n=1; \
	for target in $(TARGETS); do \
		for clk in $(TRGT_MHZs); do \
			if [ $(BATCH_TYPE) = "all" ]; then \
				for port in $(TRGT_PORTS); do \
					for dp in $(TRGT_DPLUS_PINS); do \
						for dm in $(TRGT_DMINUS_PINS); do \
							for int in $(TRGT_INTS); do \
								#echo $$n $(BATCH_TYPE) "$$target" "$$clk" ;\
								make main.hex TARGET="$$target" TRGT_MHZ="$$clk" F_CPU="$$clk"000000 USB_CFG_IOPORTNAME="$$port" USB_CFG_DPLUS_BIT="$$dp" USB_CFG_DMINUS_BIT="$$dm" TRGT_INT="$$int";\
								n=`expr $$n + 1`; \
							done \
						done \
					done \
				done \
			elif [ $(BATCH_TYPE) = "combo" ]; then \
				((n=1)) ; \
				for p in $(TRGT_COL_PORTS); do \
					make build_ws TARGET="$$target" TRGT_MHZ="$$clk" F_CPU="$$clk"000000 WS="$$n";\
					((n=$$n + 1)); \
				done ; \
			fi; \
		done \
	done

disasm:	main.bin
	avr-objdump -d main.bin

cpp:
	$(COMPILE) -E main.c

flash:
	avrdude -c ${ISP} -p ${TARGET} -P ${PORT} -U flash:w:main.hex

# Program the device.  
program: 
	avrdude -c ${ISP} -p ${TARGET} -U flash:w:main.hex

fuses:
	avrdude -c ${ISP} -p ${TARGET} -P ${PORT} -u -U hfuse:w:$(HFUSE):m -U lfuse:w:$(LFUSE):m

avrdude:
	avrdude -c ${ISP} -p ${TARGET} -P ${PORT} -v
	
reboot:
	avrdude -c ${ISP} -p ${TARGET} -P ${PORT} -v
	
all: .c.o .S.o .c.s main.hex


# Fuse atmega8 high byte HFUSE:
# 0xc9 = 1 1 0 0   1 0 0 1 <-- BOOTRST (boot reset vector at 0x0000)
#        ^ ^ ^ ^   ^ ^ ^------ BOOTSZ0
#        | | | |   | +-------- BOOTSZ1
#        | | | |   + --------- EESAVE (don't preserve EEPROM over chip erase)
#        | | | +-------------- CKOPT (full output swing)
#        | | +---------------- SPIEN (allow serial programming)
#        | +------------------ WDTON (WDT not always on)
#        +-------------------- RSTDISBL (reset pin is enabled)
# Fuse atmega8 low byte LFUSE:
# 0x9f = 1 0 0 1   1 1 1 1
#        ^ ^ \ /   \--+--/
#        | |  |       +------- CKSEL 3..0 (external >8M crystal)
#        | |  +--------------- SUT 1..0 (crystal osc, BOD enabled)
#        | +------------------ BODEN (BrownOut Detector enabled)
#        +-------------------- BODLEVEL (2.7V)
#
# Fuse atmega48 high byte hfuse:
# 0xdf = 1 1 0 1   1 1 1 1     factory setting
#        ^ ^ ^ ^   ^ \-+-/
#        | | | |   |   +------ BODLEVEL (Brown out disabled)
#        | | | |   + --------- EESAVE (don't preserve EEPROM over chip erase)
#        | | | +-------------- WDTON (WDT not always on)
#        | | +---------------- SPIEN (allow serial programming)
#        | +------------------ DWEN (debug wire is disabled)
#        +-------------------- RSTDISBL (reset pin is enabled)
# 0xdd = ext.reset, no DW, SPI, no watchdog, no save eeprom, BOD 2.7V
# Fuse atmega48 low byte lfuse:
# 0x62 = 0 1 1 0   0 0 1 0     factory setting
#        ^ ^ \ /   \--+--/
#        | |  |       +------- CKSEL 3..0 (internal 8Mhz Oszillator)
#        | |  +--------------- SUT 1..0 (start-up time)
#        | +------------------ CKOUT (no clock output)
#        +-------------------- CKDIV8 (divide clock by 8)
# 0xdc = divide/1,no clock output,fast raising power,low Pw Oszil. 3..8 Mhz
# 0xe0 = divide/1,no clock output,fast raising power,external Oszil.
# 0xff = divide/1,no clock output,slow raising power,low Pw Oszil 8..  Mhz


SERIAL = `echo /dev/tty.USA19QI*`
UISP = uisp -dprog=$S -dserial=$(SERIAL) -dpart=auto
# The two lines above are for "uisp" and the AVR910 serial programmer connected
# to a Keyspan USB to serial converter to a Mac running Mac OS X.
# Choose your favorite programmer and interface.

uisp:	all
	$(UISP) --erase
	$(UISP) --upload --verify if=main.hex

.PHONY : main.hex build_ws config version