API = ../library
INCL = ../include
UTILS = ../utils
KAUTH = ../kauth
KNODE = ../knode
ZFEC = ../zfec
BP = ../bp

# OPT = -O -Dlinux
OPT = -g -Wall -Werror -Dlinux
CC = gcc $(OPT) -I$(KAUTH) -I$(KNODE) -I$(INCL) -I$(ZFEC) -I$(BP)/library -I$(ROOT)/include
LDFLAGS = -fPIC -shared -rdynamic
LD = gcc $(LDFLAGS)

DTKAINCLS = \
	$(KAUTH)/kauth.h \
	$(KNODE)/knode.h \
	$(INCL)/dtka.h

LBP = -lbp -limcfw -lipnfw -ldtn2fw

RUNTIMES = karecv kacompile kaadmin kaboot knadmin kapublish knmgr knclock

ALL = check libkauth.so libknode.so libdtka.so $(RUNTIMES)

all:		$(ALL)

check:		$(DTKAINCLS)
		rm -f *.o
		touch check

clean:
		rm -f *.o
		rm -f $(ALL)
		rm -f ./lib/*
		rm -f ./bin/*

install:
		cp ../include/* $(ROOT)/include
		cp lib/* $(ROOT)/lib
		cp bin/* $(ROOT)/bin

#	-	-	Authority executables	-	-	-	-

karecv:		karecv.o libdtka.so
		$(CC) -o karecv karecv.o -L./lib -L$(ROOT)/lib -lkauth -ldtka $(LBP) -lici -lpthread
		cp karecv ./bin

kacompile:	kacompile.o libdtka.so
		$(CC) -o kacompile kacompile.o -L./lib -L$(ROOT)/lib -lkauth -ldtka $(LBP) -lici -lpthread
		cp kacompile ./bin

kapublish:	kapublish.o libdtka.so
		$(CC) -o kapublish kapublish.o -L./lib -L$(ROOT)/lib -lkauth -ldtka $(LBP) -lici -lpthread
		cp kapublish ./bin

#	-	-	Node executables	-	-	-	-

knclock:	knclock.o libdtka.so
		$(CC) -o knclock knclock.o -L./lib -L$(ROOT)/lib -lknode -ldtka $(LBP) -lici -lpthread
		cp knclock ./bin

knmgr:		knmgr.o libdtka.so
		$(CC) -o knmgr knmgr.o -L./lib -L$(ROOT)/lib -lknode -ldtka $(LBP) -lici -lpthread
		cp knmgr ./bin

#	-	-	Utility executables	-	-	-	-

kaadmin:	kaadmin.o libdtka.so
		$(CC) -o kaadmin kaadmin.o -L./lib -L$(ROOT)/lib -lkauth -ldtka $(LBP) -lici -lpthread
		cp kaadmin ./bin

kaboot:		kaboot.o libdtka.so
		$(CC) -o kaboot kaboot.o -L./lib -L$(ROOT)/lib -lkauth -ldtka $(LBP) -lici -lpthread
		cp kaboot ./bin

knadmin:	knadmin.o libdtka.so
		$(CC) -o knadmin knadmin.o -L./lib -L$(ROOT)/lib -lknode -ldtka $(LBP) -lici -lpthread
		cp knadmin ./bin

#	-	-	Libraries	-	-	-	-	-

libdtka.so:	libdtka.o fec.o
		$(LD) -o libdtka.so libdtka.o fec.o
		cp libdtka.so ./lib

libkauth.so:	libkauth.o
		$(LD) -o libkauth.so libkauth.o
		cp libkauth.so ./lib

libknode.so:	libknode.o
		$(LD) -o libknode.so libknode.o
		cp libknode.so ./lib

#	-	-	Object modules	-	-	-	-	-

%.o:		$(API)/%.c
		$(CC) -c $<

%.o:		$(KAUTH)/%.c
		$(CC) -c $<

%.o:		$(KNODE)/%.c
		$(CC) -c $<

%.o:		$(UTILS)/%.c
		$(CC) -c $<

fec.o:		$(ZFEC)/fec.c
		$(CC) -c $(ZFEC)/fec.c
