#
# Makefile template for CSE 30 -- PA2
#

#
# You need to change these next lines for each assignment
#

HEADERS		= mycrypt.h strings.h

C_SRCS		= main.c getPassPhrase.c getKeys.c getRotateValue.c

ASM_SRCS	= strToULong.s rotate.s checkRange.s maskPassPhrase.s \
		  mycrypt.s

C_OBJS		= main.o getPassPhrase.o getKeys.o getRotateValue.o

ASM_OBJS	= strToULong.o rotate.o checkRange.o maskPassPhrase.o \
		  mycrypt.o

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= mycrypt

#
# You should not need to change anything below this line
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -W -Wall -D__EXTENSIONS__
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -W -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}


clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o $(EXE) *.ln core a.out testrotate
	@echo ""
	@echo "Clean."

testgetPassPhrase: test.h ${HEADERS} getPassPhrase.c testgetPassPhrase.c
	@echo "Compiling testgetPassPhrase.c"
	gcc -g -o testgetPassPhrase testgetPassPhrase.c getPassPhrase.c
	@echo "Done."

runtestgetPassPhrase: testgetPassPhrase
	@echo "Running testgetPassPhrase"
	@./testgetPassPhrase

testgetKeys: test.h ${HEADERS} getKeys.c testgetKeys.c strToULong.s
	@echo "Compiling testgetKeys.c"
	gcc -g -o testgetKeys testgetKeys.c getKeys.c strToULong.s
	@echo "Done."

runtestgetKeys: testgetKeys
	@echo "Running testgetKeys"
	@./testgetKeys

testgetRotateValue: test.h ${HEADERS} getRotateValue.c testgetRotateValue.c strToULong.s checkRange.s
	@echo "Compiling testgetRotateValue.c"
	gcc -g -o testgetRotateValue testgetRotateValue.c getRotateValue.c strToULong.s checkRange.s
	@echo "Done."

runtestgetRotateValue: testgetRotateValue
	@echo "Running testgetRotateValue"
	@./testgetRotateValue

testmaskPassPhrase: test.h ${HEADERS} maskPassPhrase.s testmaskPassPhrase.c
	@echo "Compiling testmaskPassPhrase.c"
	gcc -g -o testmaskPassPhrase testmaskPassPhrase.c maskPassPhrase.s
	@echo "Done."

runtestmaskPassPhrase: testmaskPassPhrase
	@echo "Running testmaskPassPhrase"
	@./testmaskPassPhrase

teststrToULong: test.h ${HEADERS} strToULong.s teststrToULong.c
	@echo "Compiling teststrToULong.c"
	gcc -g -o teststrToULong teststrToULong.c strToULong.s
	@echo "Done."

runteststrToULong: teststrToULong
	@echo "Running teststrToULong"
	@./teststrToULong

testcheckRange: test.h ${HEADERS} checkRange.s testcheckRange.c
	@echo "Compiling testcheckRange.c"
	gcc -g -o testcheckRange testcheckRange.c checkRange.s
	@echo "Done."

runtestcheckRange: testcheckRange
	@echo "Running testcheckRange"
	@./testcheckRange

testmycrypt: test.h ${HEADERS} mycrypt.s testmycrypt.c rotate.s
	@echo "Compiling testmycrypt.c"
	gcc -g -o testmycrypt testmycrypt.c mycrypt.s rotate.s
	@echo "Done."

runtestmycrypt: testmycrypt
	@echo "Running testmycrypt"
	@./testmycrypt

testrotate: test.h ${HEADERS} rotate.s testrotate.c
	@echo "Compiling testrotate.c"
	gcc -g -o testrotate testrotate.c rotate.s
	@echo "Done."

runtestrotate: testrotate
	@echo "Running testrotate"
	@./testrotate

new:
	make clean
	make

public:
	strip $(EXE)
	chmod 755 $(EXE) 
	cp $(EXE) $(HOME)/../public/pa2test
	cat Makefile | head -161 > $(HOME)/../public/Makefile-PA2
	chmod 644 $(HOME)/../public/Makefile-PA2
	cp testrotate.c $(HOME)/../public/
	chmod 644 $(HOME)/../public/testrotate.c
