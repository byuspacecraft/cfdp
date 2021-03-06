API = ../library
INCL = ../include
UTILS = ../utils
DAEMON = ../daemon
BP = ../bp
TEST = ../test

# OPT = -O -DuClibc
# -DNO_PROXY -DNO_DIRLIST
OPT = -g -Wall -Werror -DuClibc
OPT += -mcpu=cortex-m3 -mthumb
CC = $(CROSS_COMPILE_APPS)gcc $(OPT)
CC += -I/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/include/
CC += -I$(API) -I$(INCL) -I$(ROOT)/include
LDFLAGS = -fPIC -shared
LD = $(TLD) ar rcs
PTHREADS = -L/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/lib -pthread

PUBINCLS = \
	$(INCL)/cfdp.h

CFDPINCLS = \
	$(API)/cfdpP.h \
	$(UTILS)/bpcp.h

LBP = -lbp -limcfw -lipnfw -ldtn2fw

RUNTIMES = cfdpadmin cfdpclock bputa cfdptest

ALL = check libcfdp.a $(RUNTIMES)

all:		$(ALL)

check:		$(CFDPINCLS) $(PUBINCLS)
		rm -f *.o
		touch check
		mkdir -p lib
		mkdir -p bin

clean:
		rm -f *.o
		rm -f $(ALL)
		rm -f ./lib/*
		rm -f ./bin/*

install:
		cp ../include/* $(ROOT)/include
		cp lib/* $(ROOT)/lib
		cp bin/* $(ROOT)/bin

#	-	-	Daemon executables	-	-	-	-

cfdpclock:	cfdpclock.o libcfdp.a
		$(CC) -o cfdpclock cfdpclock.o -L./lib -L$(ROOT)/lib -lcfdp $(LBP) -lici $(PTHREADS) -lm
		cp cfdpclock ./bin

#	-	-	Utility executables	-	-	-	-

cfdpadmin:	cfdpadmin.o libcfdp.a
		$(CC) -o cfdpadmin cfdpadmin.o -L./lib -L$(ROOT)/lib -lcfdp $(LBP) -lici $(PTHREADS) -lm
		cp cfdpadmin ./bin

#	-	-	Test executables	-	-	-	-

cfdptest:	cfdptest.o libcfdp.a
		$(CC) -o cfdptest cfdptest.o -L./lib -L$(ROOT)/lib -lcfdp -lcfdp $(LBP) -lici $(PTHREADS) -lm
		cp cfdptest ./bin

#	-	-	BP executables	-	-	-	-	-

bputa:		bputa.o libcfdp.a
		$(CC) -o bputa bputa.o -L./lib -L$(ROOT)/lib -lcfdp $(LBP) -lici $(PTHREADS) -lm
		cp bputa ./bin

#	-	-	BPCP executables	-	-	-	-	-
bpcp: 		bpcp.o
		$(CC) -o bpcp bpcp.o -L./lib -L$(ROOT)/lib -lici -lcfdp $(PTHREADS) -I$(UTILS) -lm
		cp bpcp ./bin

bpcpd: 		bpcpd.o
		$(CC) -o bpcpd bpcpd.o -L./lib -L$(ROOT)/lib -lici -lcfdp $(PTHREADS) -I$(UTILS) -lm
		cp bpcpd ./bin

#	-	-	Libraries	-	-	-	-	-

libcfdp.a:	libcfdp.o libcfdpP.o libcfdpops.o
		$(LD) libcfdp.a libcfdp.o libcfdpP.o libcfdpops.o
		cp libcfdp.a ./lib

#	-	-	Object modules	-	-	-	-	-

%.o:		$(API)/%.c
		$(CC) -c $<

%.o:		$(UTILS)/%.c
		$(CC) -c $<

%.o:		$(TEST)/%.c
		$(CC) -c $<

%.o:		$(DAEMON)/%.c
		$(CC) -c $<

%.o:		$(BP)/%.c
		$(CC) -c $<
