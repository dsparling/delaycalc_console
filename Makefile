CPP = g++
OFLAG = -o
.SUFFIXES : .o .cpp .c
.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<
.c.o :
	$(CPP) $(CPPFLAGS) -c $<

all: delaycalc

test: all 
	delaycalc

clean:
	rm -f *.o delaycalc
	rm -f calc.out

bugs: 
	@echo No compiler bugs in this directory!

delaycalc: delaycalc.o DelayCalculator.o 
	$(CPP) $(OFLAG) delaycalc delaycalc.o DelayCalculator.o 

DelayCalculator.o: DelayCalculator.cpp DelayCalculator.h 
delaycalc.o: delaycalc.cpp DelayCalculator.h 
