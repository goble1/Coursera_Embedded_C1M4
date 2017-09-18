#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for two target platforms and their own
# specific compilers. These two platforms are the HOST and
# the MSP432.
# The host embedded system will use the native compiler, gcc.
# The target embedded system will use the cross compiler,
# arm-none-eabi-gcc.
#
#* @author Krystian Jagoda
#* @date 15 September 2017
#
# Use: make [TARGET] [PLATFORM-OVERRIDES] [FUNCTION] [DEBUG - Optional]
# Example: $ make build PLATFORM=HOST FUNCTION=COURSE1 DEBUG=VERBOSE
#
# Build Targets:
#      <FILE>.i - Generate <FILE>.i preprocessed output
#      <FILE>.asm - Generate <FILE>.asm assembly output
#      <FILE>.o - Builds <FILE>.o object file
#      compile-all - Compile all object files, but DO NOT link
#      build - Builds and links all source files
#      clean - Removes all generated files
#
# PLATFORM-OVERRIDES:
#       PLATFORM=HOST - Compile for HOST using gcc
#       PLATFORM=MSP432 - Compile for MSP432 using arm-none-eabi-gcc
#
# FUNCTION:
# 			FUNCTION=COURSE1
# 			FUNCTION=TEST_DATA1
# 			FUNCTION=TEST_DATA2
# 			FUNCTION=TEST_MEMMOVE1
# 			FUNCTION=TEST_MEMMOVE2
# 			FUNCTION=TEST_MEMMOVE3
# 			FUNCTION=TEST_MEMCOPY
# 			FUNCTION=TEST_MEMSET
# 			FUNCTION=TEST_REVERSE
#
# DEBUG:
#       DEBUG=VERBOSE - Print extra information on the memory data
#
#------------------------------------------------------------------------------

include sources.mk

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
CFLAGS = -Wall -Werror -g -O0 -std=c99

# Compiler Flags and Defines
TARGET = c1m4

ifeq ($(DEBUG), VERBOSE)
		CPPFLAGS = -D$(PLATFORM) -D$(FUNCTION) -D$(DEBUG) -MMD -MP
else
	CPPFLAGS = -D$(PLATFORM) -D$(FUNCTION) -MMD -MP
endif

ifeq ($(PLATFORM), HOST)
    CC = gcc
    LD = ld
    OBJDMP = objdump
    SIZE = size
    LDFLAGS = -Wl,-Map=$(TARGET).map
else
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    OBJDMP = arm-none-eabi-objdump
    SIZE = arm-none-eabi-size
    CFLAGS += -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) \
        -march=armv7e-m							\
        -mfloat-abi=hard						\
        -mfpu=fpv4-sp-d16
    LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.o=.d)

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: compile-all
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) -Atd $(OBJS) $(TARGET).out

$(TARGET).asm: build
	$(OBJDMP) --disassemble $(TARGET).out > $(TARGET).asm

.PHONY: clean
clean:
	rm -f *.o *.out *.map *.asm *.i *.d
	rm -f src/*.o src/*.out src/*.map src/*.asm src/*.i src/*.d
