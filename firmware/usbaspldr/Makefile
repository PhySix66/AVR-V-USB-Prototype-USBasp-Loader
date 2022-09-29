# Name: Makefile
# Project: USBaspLoader
# Author: Christian Starkjohann
# Creation Date: 2007-12-10
# Tabsize: 4
# Copyright: (c) 2007 by OBJECTIVE DEVELOPMENT Software GmbH
# License: GNU GPL v2 (see License.txt)
# This Revision: $Id$

###############################################################################
# Configure the following variables according to your AVR.
# Program the device with
#     make fuse    # to set the clock generator, boot section size etc.
#     make flash   # to load the boot loader into flash
#     make lock    # to protect the boot loader from overwriting

TARGET = atmega88pa
# BOOTLOADER_ADDRESS is 1800 for 8k devices, 3800 for 16k and 7800 for 32k.
BOOTLOADER_ADDRESS = 7800
FUSEOPT = $(FUSEOPT_328)
#LOCKOPT = -U lock:w:0x2f:m

#PROGRAMMER = -c stk500v2 -P avrdoper
PROGRAMMER = -c usbasp-clone
# PROGRAMMER contains AVRDUDE options to address your programmer

FUSEOPT_8 = -U hfuse:w:0xd0:m -U lfuse:w:0xbf:m							//	Ext. High Freq Crystal, BODLVL@2v7, Save EEPROM, SPI Prog EN, BootRST EN, Boot Flash Size 1024word (2kb)
FUSEOPT_88 = -U hfuse:w:0xf7:m -U lfuse:w:0xd5:m -U efuse:w:0xf8:m		//	Full-Swing Crystal, BODLVL@2v7, Save EEPROM, SPI Prog EN, BootRST EN, Boot Flash Size 1024word (2kb)
FUSEOPT_168 = -U lfuse:w:0xf7:m -U hfuse:w:0xd5:m -U efuse:w:0xf8:m		//	Full-Swing Crystal, BODLVL@2v7, Save EEPROM, SPI Prog EN, BootRST EN, Boot Flash Size 1024word (2kb)
FUSEOPT_328 = -U lfuse:w:0xf7:m -U hfuse:w:0xd2:m -U efuse:w:0xf7:m		//	Full-Swing Crystal, BODLVL@2v7, Save EEPROM, SPI Prog EN, BootRST EN, Boot Flash Size 1024word (2kb)

AVR_GCC_VER=-9.2.0

TRGT_NUM=1
TRGT_MHZ=20
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
TARGETS = atmega88p atmega328p
BOOTLDR_ADDRS = 1800 7800
BOOTLDR_ADDR=$(word $(TRGT_NUM), $(BOOTLDR_ADDRS))
TRGT_MHZs = 16 20
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
TRGT_COL_PORTS = B B D D D D
TRGT_COL_DPLUS_PINS = 0 1 2 3 2 3
TRGT_COL_DMINUS_PINS = 1 0 3 2 3 2
TRGT_COL_INTS = PCINTx PCINTx INTx INTx PCINTx PCINTx
USB_COL_CFG_PULLUP_IOPORTNAME= D D D D D D
USB_COL_CFG_PULLUP_BIT= 7 7 7 7 7 7
SlowSCK_COL_PORTNAME= D D D D D D
SlowSCK_COL_BIT= 5 5 5 5 5 5

# Don't TOUCH these!!!
##		-----------------------------------------------		##
USB_INTR_SEL_PRETXT=USB_INTR_TYPE_
USB_INTR_SEL=$(USB_INTR_SEL_PRETXT)$(TRGT_INT)
TRGT_PORT=PORT$(USB_CFG_IOPORTNAME)
TRGT_FILE_NAME=$(TARGET)_$(TRGT_MHZ)Mhz_$(TRGT_PORT)_$(TRGT_INT)
WS = 1
INDEXED_USB_CFG_IOPORTNAME=$(word $(WS), $(TRGT_COL_PORTS)) 
INDEXED_USB_CFG_DPLUS_BIT=$(word $(WS), $(TRGT_COL_DPLUS_PINS)) 
INDEXED_USB_CFG_DMINUS_BIT=$(word $(WS), $(TRGT_COL_DMINUS_PINS)) 
INDEXED_TRGT_INT=$(word $(WS), $(TRGT_COL_INTS)) 

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

# You may have to change the order of these -U commands.

#---------------------------------------------------------------------
# ATMega8
#---------------------------------------------------------------------
# Fuse high byte:
# 0xc0 = 1 1 0 0   0 0 0 0 <-- BOOTRST (boot reset vector at 0x1800)
#        ^ ^ ^ ^   ^ ^ ^------ BOOTSZ0
#        | | | |   | +-------- BOOTSZ1
#        | | | |   + --------- EESAVE (preserve EEPROM over chip erase)
#        | | | +-------------- CKOPT (full output swing)
#        | | +---------------- SPIEN (allow serial programming)
#        | +------------------ WDTON (WDT not always on)
#        +-------------------- RSTDISBL (reset pin is enabled)
# Fuse low byte:
# 0x9f = 1 0 0 1   1 1 1 1
#        ^ ^ \ /   \--+--/
#        | |  |       +------- CKSEL 3..0 (external >8M crystal)
#        | |  +--------------- SUT 1..0 (crystal osc, BOD enabled)
#        | +------------------ BODEN (BrownOut Detector enabled)
#        +-------------------- BODLEVEL (2.7V)
#---------------------------------------------------------------------
# ATMega88, ATMega168
#---------------------------------------------------------------------
# Fuse extended byte:
# 0x00 = 0 0 0 0   0 0 0 0 <-- BOOTRST (boot reset vector at 0x1800)
#                    \+/
#                     +------- BOOTSZ (00 = 2k bytes)
# Fuse high byte:
# 0xd6 = 1 1 0 1   0 1 1 0
#        ^ ^ ^ ^   ^ \-+-/
#        | | | |   |   +------ BODLEVEL 0..2 (110 = 1.8 V)
#        | | | |   + --------- EESAVE (preserve EEPROM over chip erase)
#        | | | +-------------- WDTON (if 0: watchdog always on)
#        | | +---------------- SPIEN (allow serial programming)
#        | +------------------ DWEN (debug wire enable)
#        +-------------------- RSTDISBL (reset pin is enabled)
# Fuse low byte:
# 0xdf = 1 1 0 1   1 1 1 1
#        ^ ^ \ /   \--+--/
#        | |  |       +------- CKSEL 3..0 (external >8M crystal)
#        | |  +--------------- SUT 1..0 (crystal osc, BOD enabled)
#        | +------------------ CKOUT (if 0: Clock output enabled)
#        +-------------------- CKDIV8 (if 0: divide by 8)
#---------------------------------------------------------------------
# ATMega328P
#---------------------------------------------------------------------
# Fuse extended byte:
# 0x03 = - - - -   - 0 1 1
#                    \-+-/
#                      +------ BODLEVEL 0..2 (011 = 4.3V)
# Fuse high byte:
# 0xda = 1 1 0 1   1 0 1 0 <-- BOOTRST (0 = jump to bootloader at start)
#        ^ ^ ^ ^   ^ \+/
#        | | | |   |  +------- BOOTSZ 0..1 (01 = 2KB starting at 0x7800)
#        | | | |   + --------- EESAVE (don't preserve EEPROM over chip erase)
#        | | | +-------------- WDTON (1 = watchdog disabled at start)
#        | | +---------------- SPIEN (0 = allow serial programming)
#        | +------------------ DWEN (1 = debug wire disable)
#        +-------------------- RSTDISBL (1 = reset pin is enabled)
# Fuse low byte:
# 0xf7 = 1 1 1 1   0 1 1 1
#        ^ ^ \ /   \--+--/
#        | |  |       +------- CKSEL 3..0 (0111 = external full-swing crystal)
#        | |  +--------------- SUT 1..0 (11 = startup time 16K CK/14K + 65ms)
#        | +------------------ CKOUT (1 = clock output disabled)
#        +-------------------- CKDIV8 (1 = do not divide clock by 8)


###############################################################################

# Tools:
AVRDUDE = avrdude $(PROGRAMMER) -p $(TARGET)
CC = avr-gcc$(AVR_GCC_VER)

# Options:
DEFINES = #-DDEBUG_LEVEL=2
# Remove the -fno-* options when you use gcc 3, it does not understand them
CFLAGS = -Wall -Os -fno-move-loop-invariants -fno-tree-scev-cprop -fno-inline-small-functions -I. -mmcu=$(TARGET) $(CDEFS) $(DEFINES)
LDFLAGS = -Wl,--relax,--gc-sections -Wl,--section-start=.text=$(BOOTLOADER_ADDRESS)

OBJECTS =  usbdrv/usbdrvasm.o usbdrv/oddebug.o main.o

# symbolic targets:

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

all: main.hex

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.S.o:
	$(CC) $(CFLAGS) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(CC) $(CFLAGS) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i

program:
	$(AVRDUDE) -U flash:w:main.hex:i

readflash:
	$(AVRDUDE) -U flash:r:read.hex:i

fuse:
	$(AVRDUDE) $(FUSEOPT)

lock:
	$(AVRDUDE) $(LOCKOPT)

read_fuses:
	$(UISP) --rd_fuses

clean:
	rm -f main.hex main.bin *.o usbdrv/*.o main.s usbdrv/oddebug.s usbdrv/usbdrv.s

# file targets:
main.bin:	$(OBJECTS)
	$(CC) $(CFLAGS) -o main.bin $(OBJECTS) $(LDFLAGS)

main.hex:	clean main.bin config
	rm -f main.hex main.eep.hex
	avr-objcopy -j .text -j .data -O ihex main.bin main.hex
	avr-size main.hex
	@if [ -a main.hex ] ; then \
	mkdir -p $(BATCH_DIR)/ ;\
	cp -f main.hex $(BATCH_DIR)/main.hex ;\
	cp -f main.hex $(BATCH_DIR)/$(TRGT_FILE_NAME).hex ;\
	cp -f export_config.txt $(BATCH_DIR)/config.txt ;\
	fi;

build_ws:
	make main.hex USB_CFG_IOPORTNAME=$(word $(WS), $(TRGT_COL_PORTS)) USB_CFG_DPLUS_BIT=$(word $(WS), $(TRGT_COL_DPLUS_PINS)) USB_CFG_DMINUS_BIT=$(word $(WS), $(TRGT_COL_DMINUS_PINS)) TRGT_INT=$(word $(WS), $(TRGT_COL_INTS)) BOOTLOADER_ADDRESS=$(BOOTLDR_ADDR)

build_batch:
	@n=1; \
	trgt_num=0; \
	for target in $(TARGETS); do \
		((trgt_num = trgt_num + 1)) ;\
		for clk in $(TRGT_MHZs); do \
			if [ $(BATCH_TYPE) = "all" ]; then \
				for port in $(TRGT_PORTS); do \
					for dp in $(TRGT_DPLUS_PINS); do \
						for dm in $(TRGT_DMINUS_PINS); do \
							for int in $(TRGT_INTS); do \
								#echo $$n $(BATCH_TYPE) "$$target" "$$clk" ;\
								make main.hex TARGET="$$target" TRGT_NUM="$$trgt_num" TRGT_MHZ="$$clk" F_CPU="$$clk"000000 USB_CFG_IOPORTNAME="$$port" USB_CFG_DPLUS_BIT="$$dp" USB_CFG_DMINUS_BIT="$$dm" TRGT_INT="$$int";\
								n=`expr $$n + 1`; \
							done \
						done \
					done \
				done \
			elif [ $(BATCH_TYPE) = "combo" ]; then \
				((n=1)) ; \
				for p in $(TRGT_COL_PORTS); do \
					make build_ws TARGET="$$target" TRGT_MHZ="$$clk" F_CPU="$$clk"000000 WS="$$n" TRGT_NUM="$$trgt_num" BOOTLOADER_ADDRESS=$(BOOTLDR_ADDR) ;\
					((n=$$n + 1)); \
				done ; \
			fi; \
		done \
	done

disasm:	main.bin
	avr-objdump -d main.bin

cpp:
	$(CC) $(CFLAGS) -E main.c

# Special rules for generating hex files for various devices and clock speeds
ALLHEXFILES = hexfiles/mega8_12mhz.hex hexfiles/mega8_15mhz.hex hexfiles/mega8_16mhz.hex \
	hexfiles/mega88_12mhz.hex hexfiles/mega88_15mhz.hex hexfiles/mega88_16mhz.hex hexfiles/mega88_20mhz.hex\
	hexfiles/mega168_12mhz.hex hexfiles/mega168_15mhz.hex hexfiles/mega168_16mhz.hex hexfiles/mega168_20mhz.hex\
	hexfiles/mega328p_12mhz.hex hexfiles/mega328p_15mhz.hex hexfiles/mega328p_16mhz.hex hexfiles/mega328p_20mhz.hex

allhexfiles: $(ALLHEXFILES)
	$(MAKE) clean
	avr-size hexfiles/*.hex

$(ALLHEXFILES):
	@[ -d hexfiles ] || mkdir hexfiles
	@device=`echo $@ | sed -e 's|.*/mega||g' -e 's|_.*||g'`; \
	clock=`echo $@ | sed -e 's|.*_||g' -e 's|mhz.*||g'`; \
	addr=`echo $$device | sed -e 's/\([0-9]\)8/\1/g' | awk '{printf("%x", ($$1 - 2) * 1024)}'`; \
	echo "### Make with F_CPU=$${clock}000000 TARGET=atmega$$device BOOTLOADER_ADDRESS=$$addr"; \
	$(MAKE) clean; \
	$(MAKE) main.hex F_CPU=$${clock}000000 TARGET=atmega$$device BOOTLOADER_ADDRESS=$$addr DEFINES=-DUSE_AUTOCONFIG=1
	mv main.hex $@
