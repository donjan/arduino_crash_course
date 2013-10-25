#---------------------------name----------------------------------------
TARGET := $(shell ls | grep *.cpp | sed 's/.\{4\}$$//')

ARDLIBS = 

MODEL = ATMega16MHz

PORT ?= /dev/ttyACM*

OPT = 3

include /home/bryonak/c/arduino_crash_course/makefile/Master_Makefile.mk
