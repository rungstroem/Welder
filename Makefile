SHELL=/bin/bash
TARGET = main.elf

.PHONY: clean
.PHONY: flash

CC = avr-gcc
CFLAGS = -mmcu=atmega8 -Wall -pedantic -Os

PRG = usbasp
PRGFLAGS = -p m8 -e -U

BUILD_DIR = Build
SOURCE_DIR = src
INCLUDE_DIR = inc

SRC:=$(wildcard $(SOURCE_DIR)/*.c)

vpath %.h $(INCLUDE_DIR)


all: $(TARGET)

$(TARGET): $(BUILD_DIR) $(SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(BUILD_DIR)/$(TARGET) $(SRC)


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

flash: $(TARGET)
	avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/main.hex
	sudo avrdude -c $(PRG) $(PRGFLAGS) flash:w:$(BUILD_DIR)/main.hex

clean:
	rm -f $(BUILD_DIR)/*
