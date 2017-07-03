API = ../library
INCL = ../include
UTILS = ../utils
DAEMON = ../daemon
UDP = ../udp
DCCP = ../dccp
SDA = ../sda
TEST = ../test

# OPT = -O -DuClibc
OPT = -g -Wall -Werror -DuClibc
OPT += -mcpu=cortex-m3 -mthumb
CC = $(CROSS_COMPILE_APPS)gcc $(OPT)
CC += -I/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/include/
CC += -I$(API) -I$(API)/ext -I$(API)/ext/auth -I$(INCL) -I$(ROOT)/include
LDFLAGS = -fPIC -shared
LD = $(TLD) ar rcs
PTHREADS = -L/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/lib -pthread

PUBINCLS = \
	$(INCL)/ltp.h \
	$(INCL)/sda.h

LTPINCLS = \
	$(API)/ltpP.h \
	$(UDP)/udplsa.h \
	$(DCCP)/dccplsa.h

RUNTIMES = ltpadmin ltpclock ltpmeter udplsi udplso ltpdriver ltpcounter sdatest
#dccplsi dccplso

ALL = check libltp.a $(RUNTIMES)

all:		$(ALL)

check:		$(LTPINCLS) $(PUBINCLS)
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

ltpclock:	ltpclock.o libltp.a
		$(CC) -o ltpclock ltpclock.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp ltpclock ./bin

ltpmeter:	ltpmeter.o libltp.a
		$(CC) -o ltpmeter ltpmeter.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp ltpmeter ./bin

#	-	-	Utility executables	-	-	-	-

ltpadmin:	ltpadmin.o libltp.a
		$(CC) -o ltpadmin ltpadmin.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp ltpadmin ./bin

#	-	-	Test executables	-	-	-	-

ltpdriver:	ltpdriver.o libltp.a
		$(CC) -o ltpdriver ltpdriver.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp ltpdriver ./bin

ltpcounter:	ltpcounter.o libltp.a
		$(CC) -o ltpcounter ltpcounter.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp ltpcounter ./bin

sdatest:	sdatest.o libltp.a
		$(CC) -o sdatest sdatest.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp sdatest ./bin

#	-	-	UDP executables	-	-	-	-	-

udplsi:		udplsi.o libltp.a
		$(CC) -o udplsi udplsi.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp udplsi ./bin

udplso:		udplso.o libltp.a
		$(CC) -o udplso udplso.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp udplso ./bin

#	-	-	DCCP executables-	-	-	-	-
dccplsi:	dccplsi.o libltp.a
		$(CC) -o dccplsi dccplsi.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp dccplsi ./bin

dccpplso:	dccplso.o libltp.a
		$(CC) -o dccplso dccplso.o -L./lib -L$(ROOT)/lib -lltp -lici $(PTHREADS) -lm
		cp dccplso ./bin

#	-	-	Libraries	-	-	-	-	-

libltp.a:	libltpP.o libltp.o ltpei.o auth.o libltpnm.o libsda.o
		$(LD) libltp.a libltp.o libltpP.o ltpei.o auth.o libltpnm.o libsda.o
		cp libltp.a ./lib

#	-	-	Object modules	-	-	-	-	-

%.o:		$(API)/%.c
		$(CC) -c $<

%.o:		$(API)/ext/auth/%.c
		$(CC) -c $<

%.o:		$(UTILS)/%.c
		$(CC) -c $<

%.o:		$(TEST)/%.c
		$(CC) -c $<

%.o:		$(DAEMON)/%.c
		$(CC) -c $<

%.o:		$(UDP)/%.c
		$(CC) -c $<

%.o:		$(SDA)/%.c
		$(CC) -c $<

#%.o:		$(DCCP)/%.c
#		$(CC) -c $<
