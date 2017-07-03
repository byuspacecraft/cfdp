INCL = ../include
API = ../library
TEST = ../test

# OPT = -O -DuClibc
# OPT = -g -Wall -DuClibc -DINITIAL_RETARD=2
OPT = -g -Wall -Werror -DuClibc
OPT += -mcpu=cortex-m3 -mthumb
CC = $(CROSS_COMPILE_APPS)gcc $(OPT)
CC += -I/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/include/
CC += -I$(API) -I$(TEST) -I$(INCL) -I$(ROOT)/include
LDFLAGS = -fPIC -shared
LD = $(TLD) ar rcs
PTHREADS = -L/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/lib -pthread

LIBDGROBJS = \
	libdgr.o

PUBINCLS = \
	$(INCL)/dgr.h

RUNTIMES = file2dgr dgr2file file2tcp tcp2file file2udp udp2file

ALL = check libdgr.a $(RUNTIMES)

all:		$(ALL)

check:		$(PUBINCLS)
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

#	-	-	Test executables	-	-	-	-

file2dgr:	file2dgr.o libdgr.a $(TEST)/file2dgr.h
		$(CC) -o file2dgr file2dgr.o -L./lib -L$(ROOT)/lib -ldgr -lici $(PTHREADS) -lm
		cp file2dgr ./bin

dgr2file:	dgr2file.o libdgr.a $(TEST)/file2dgr.h
		$(CC) -o dgr2file dgr2file.o -L./lib -L$(ROOT)/lib -ldgr -lici $(PTHREADS) -lm
		cp dgr2file ./bin

tcp2file:	tcp2file.o $(TEST)/file2tcp.h
		$(CC) -o tcp2file tcp2file.o -L$(ROOT)/lib -L./lib -lici $(PTHREADS) -lm
		cp tcp2file ./bin

file2tcp:	file2tcp.o $(TEST)/file2tcp.h
		$(CC) -o file2tcp file2tcp.o -L$(ROOT)/lib -L./lib -lici $(PTHREADS) -lm
		cp file2tcp ./bin

udp2file:	udp2file.o $(TEST)/file2udp.h
		$(CC) -o udp2file udp2file.o -L$(ROOT)/lib -L./lib -lici $(PTHREADS) -lm
		cp udp2file ./bin

file2udp:	file2udp.o $(TEST)/file2udp.h
		$(CC) -o file2udp file2udp.o -L$(ROOT)/lib -L./lib -lici $(PTHREADS) -lm
		cp file2udp ./bin

#	-	-	Libraries	-	-	-	-	-

libdgr.a:	$(LIBDGROBJS)
		$(LD) libdgr.a $(LIBDGROBJS)
		cp libdgr.a ./lib

#	-	-	Object modules	-	-	-	-	-

%.o:		$(API)/%.c
		$(CC) -c $<

%.o:		$(TEST)/%.c
		$(CC) -c $<
