API = ../library
INCL = ../include
UTILS = ../utils
TEST = ../test
DAEMON = ../daemon
CGR = ../cgr
IPN = ../ipn
IMC = ../imc
BSSP = ../bssp
DTN2 = ../dtn2
LTP = ../ltp
TCP = ../tcp
STCP = ../stcp
DGR = ../dgr
BRS = ../brs
UDP = ../udp
DCCP = ../dccp
BIBE = ../bibe
#IPND = ../ipnd

# OPT = -O -DuClibc
OPT = -g -Wall -Werror -DuClibc -DENABLE_BPACS -DENABLE_IMC -DBPSEC
OPT += -mcpu=cortex-m3 -mthumb
CC = $(CROSS_COMPILE_APPS)gcc $(OPT)
CC += -I/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/include/
CC += -I$(IPN) -I$(IMC) -I$(DTN2) -I$(API) -I$(API)/acs -I$(API)/ext -I$(API)/ext/phn -I$(API)/ext/ecos -I$(API)/ext/meb -I$(API)/ext/bae -I$(API)/ext/bpsec -I$(API)/ext/cteb -I$(STCP) -I$(UDP) -I$(INCL) -I$(ROOT)/include -DBP_EXTENDED
LDFLAGS = -fPIC -shared
LD = $(TLD) ar rcs
PTHREADS = -L/home/ecestudent/linux-cortexm-1.14.3/A2F/root/usr/lib -pthread

PUBINCLS = \
	$(INCL)/bp.h

BPINCLS = \
	$(API)/bpP.h \
	$(IPN)/ipnfw.h \
	$(IMC)/imcfw.h \
	$(IMC)/imcP.h \
	$(BSSP)/bsspcla.h \
	$(DTN2)/dtn2fw.h \
	$(BRS)/brscla.h \
	$(UDP)/udpcla.h \
	$(STCP)/stcpcla.h \
	$(LTP)/ltpcla.h \
	$(DCCP)/dccpcla.h \
	$(API)/acs/acs.h

BPLIBS = \
	libbp.a

BPPOBJS = libbpP.o eureka.o bei.o phn.o ecos.o meb.o bae.o acstx.o acsrx.o acsserialize.o acsappend.o acsid.o cteb.o bpsec_util.o bpsec_instr.o profiles.o bpsec_bib.o bpsec_bcb.o
# snid.o

#IPNDOBJS = ipnd.o beacon.o helper.o node.o
LBP = -lbp -limcfw -lipnfw -ldtn2fw

RUNTIMES = bpadmin bpsink bpsource bpdriver bpecho bpcounter bpsendfile bprecvfile bpclock bptransit bpclm ipnadmin ipnfw ipnadminep dtn2admin dtn2fw dtn2adminep tcpcli tcpclo stcpcli stcpclo brsscla brsccla udpcli udpclo dgrcli dgrclo ltpcli ltpclo lgsend lgagent bptrace bpstats bplist bpcancel hmackeys bping bpstats2 bpchat acsadmin acslist imcadmin imcfw bsspcli bsspclo bibeclo bpnmtest cgrfetch
# dccpcli dccpclo ipnd

ALL = check $(BPLIBS) libcgr.a libipnfw.a libimcfw.a libdtn2fw.a libstcpcla.a libudpcla.a $(RUNTIMES)

all:		$(ALL)

check:		$(BPINCLS) $(PUBINCLS)
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

bpclock:	bpclock.o $(BPLIBS)
		$(CC) -o bpclock bpclock.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpclock ./bin

bptransit:	bptransit.o $(BPLIBS)
		$(CC) -o bptransit bptransit.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bptransit ./bin

bpclm:		bpclm.o $(BPLIBS)
		$(CC) -o bpclm bpclm.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpclm ./bin

#	-	-	Utility executables	-	-	-	-

bpadmin:	bpadmin.o $(BPLIBS)
		$(CC) -o bpadmin bpadmin.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpadmin ./bin

ipnadmin:	ipnadmin.o $(BPLIBS) libipnfw.a
		$(CC) -o ipnadmin ipnadmin.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp ipnadmin ./bin

imcadmin:	imcadmin.o $(BPLIBS) libimcfw.a
		$(CC) -o imcadmin imcadmin.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp imcadmin ./bin

dtn2admin:	dtn2admin.o $(BPLIBS) libdtn2fw.a
		$(CC) -o dtn2admin dtn2admin.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp dtn2admin ./bin

lgsend:		lgsend.o $(BPLIBS)
		$(CC) -o lgsend lgsend.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp lgsend ./bin

lgagent:	lgagent.o $(BPLIBS)
		$(CC) -o lgagent lgagent.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp lgagent ./bin

bptrace:	bptrace.o $(BPLIBS)
		$(CC) -o bptrace bptrace.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bptrace ./bin

bpstats:	bpstats.o $(BPLIBS)
		$(CC) -o bpstats bpstats.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpstats ./bin

bpstats2:	bpstats2.o $(BPLIBS)
		$(CC) -o bpstats2 bpstats2.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpstats2 ./bin

bping:		bping.o $(BPLIBS)
		$(CC) -o bping bping.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bping ./bin

bpchat:		bpchat.o $(BPLIBS)
		$(CC) -o bpchat bpchat.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpchat ./bin

bplist:		bplist.o $(BPLIBS)
		$(CC) -o bplist bplist.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bplist ./bin

bpcancel:	bpcancel.o $(BPLIBS)
		$(CC) -o bpcancel bpcancel.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpcancel ./bin

hmackeys:	hmackeys.o $(BPLIBS)
		$(CC) -o hmackeys hmackeys.o -L$(ROOT)/lib -lici $(PTHREADS) -lm
		cp hmackeys ./bin

acsadmin:	acsadmin.o $(BPLIBS)
		$(CC) -o acsadmin acsadmin.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp acsadmin ./bin

acslist:	acslist.o $(BPLIBS)
		$(CC) -o acslist acslist.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp acslist ./bin

cgrfetch:	cgrfetch.o $(BPLIBS)
		$(CC) -o cgrfetch cgrfetch.o -L./lib -L$(ROOT)/lib -lcgr $(LBP) -lici $(PTHREADS) -lm
		cp acslist ./bin

#	-	-	IPN executables	-	-	-	-	-

ipnfw:		ipnfw.o $(BPLIBS) libipnfw.a libcgr.a
		$(CC) -o ipnfw ipnfw.o -L./lib -L$(ROOT)/lib -lcgr $(LBP) -lici $(PTHREADS) -lm
		cp ipnfw ./bin

ipnadminep:	ipnadminep.o $(BPLIBS) libipnfw.a
		$(CC) -o ipnadminep ipnadminep.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp ipnadminep ./bin

#	-	-	IMC executables	-	-	-	-	-

imcfw:		imcfw.o $(BPLIBS) libimcfw.a libipnfw.a
		$(CC) -o imcfw imcfw.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp imcfw ./bin

#	-	-	DTN2 executables	-	-	-	-

dtn2fw:		dtn2fw.o $(BPLIBS) libdtn2fw.a
		$(CC) -o dtn2fw dtn2fw.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp dtn2fw ./bin

dtn2adminep:	dtn2adminep.o $(BPLIBS) libdtn2fw.a
		$(CC) -o dtn2adminep dtn2adminep.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp dtn2adminep ./bin

#	-	-	LTP executables	-	-	-	-	-
# Dallon - "Not sure if we need lltpP. It wasn't being made for uCLibc originally"

ltpcli:		ltpcli.o $(BPLIBS)
		$(CC) -o ltpcli ltpcli.o -L./lib -L$(ROOT)/lib $(LBP) -lltp -lltpP -lici $(PTHREADS) -lm
		cp ltpcli ./bin

ltpclo:		ltpclo.o $(BPLIBS)
		$(CC) -o ltpclo ltpclo.o -L./lib -L$(ROOT)/lib $(LBP) -lltp -lltpP -lici $(PTHREADS) -lm
		cp ltpclo ./bin

#	-	-	TCP executables	-	-	-	-	-

tcpcli:		tcpcli.o $(BPLIBS)
		$(CC) -o tcpcli tcpcli.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp tcpcli ./bin

tcpclo:		tcpclo.o $(BPLIBS)
		$(CC) -o tcpclo tcpclo.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp tcpclo ./bin

#	-	-	STCP executables	-	-	-	-

stcpcli:	stcpcli.o $(BPLIBS) libstcpcla.a
		$(CC) -o stcpcli stcpcli.o -L./lib -L$(ROOT)/lib -lstcpcla $(LBP) -lici $(PTHREADS) -lm
		cp stcpcli ./bin

stcpclo:	stcpclo.o $(BPLIBS) libstcpcla.a
		$(CC) -o stcpclo stcpclo.o -L./lib -L$(ROOT)/lib -lstcpcla $(LBP) -lici $(PTHREADS) -lm
		cp stcpclo ./bin

#	-	-	UDP executables	-	-	-	-	-

udpcli:		udpcli.o $(BPLIBS) libudpcla.a
		$(CC) -o udpcli udpcli.o -L./lib -L$(ROOT)/lib -ludpcla $(LBP) -lici $(PTHREADS) -lm
		cp udpcli ./bin

udpclo:		udpclo.o $(BPLIBS) libudpcla.a
		$(CC) -o udpclo udpclo.o -L./lib -L$(ROOT)/lib -ludpcla $(LBP) -lici $(PTHREADS) -lm
		cp udpclo ./bin

#	-	-	BSSP executables	-	-	-	-

bsspcli:	bsspcli.o $(BPLIBS)
		$(CC) -o bsspcli bsspcli.o -L./lib -L$(ROOT)/lib $(LBP) -lbssp -lbsspP -lici $(PTHREADS) -lm
		cp bsspcli ./bin

bsspclo:	bsspclo.o $(BPLIBS)
		$(CC) -o bsspclo bsspclo.o -L./lib -L$(ROOT)/lib $(LBP) -lbssp -lbsspP -lici $(PTHREADS) -lm
		cp bsspclo ./bin

#	-	-	DCCP executables	-	-	-	-

dccpcli:	dccpcli.o $(BPLIBS)
		$(CC) -o dccpcli dccpcli.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp dccpcli ./bin

dccpclo:	dccpclo.o $(BPLIBS)
		$(CC) -o dccpclo dccpclo.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp dccpclo ./bin

#	-	-	DGR executables	-	-	-	-	-

dgrcli:		dgrcli.o $(BPLIBS)
		$(CC) -o dgrcli dgrcli.o -L./lib -L$(ROOT)/lib $(LBP) -ldgr -lici $(PTHREADS) -lm
		cp dgrcli ./bin

dgrclo:		dgrclo.o $(BPLIBS)
		$(CC) -o dgrclo dgrclo.o -L./lib -L$(ROOT)/lib $(LBP) -ldgr -lici $(PTHREADS) -lm
		cp dgrclo ./bin

#	-	-	BRS executables	-	-	-	-

brsscla:	brsscla.o $(BPLIBS) libstcpcla.a
		$(CC) -o brsscla brsscla.o -L./lib -L$(ROOT)/lib -lstcpcla $(LBP) -lici $(PTHREADS) -lm
		cp brsscla ./bin

brsccla:	brsccla.o $(BPLIBS) libstcpcla.a
		$(CC) -o brsccla brsccla.o -L./lib -L$(ROOT)/lib -lstcpcla $(LBP) -lici $(PTHREADS) -lm
		cp brsccla ./bin

#	-	-	BIBE executable	-	-	-	-	-

bibeclo:	bibeclo.o $(BPLIBS)
		$(CC) -o bibeclo bibeclo.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bibeclo ./bin

#	-	-	IPND executable	-	-	-	-	-

#ipnd:		$(IPNDOBJS) $(BPLIBS)
#		$(CC) -o ipnd $(IPNDOBJS) -L./lib -L$(ROOT)/lib $(LBP) -lici -lbloom $(PTHREADS) -lm
#		cp ipnd ./bin

#	-	-	Test executables	-	-	-	-

bpsource:	bpsource.o libbp.a $(BPLIBS)
		$(CC) -o bpsource bpsource.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpsource ./bin

bpsink:		bpsink.o libbp.a $(BPLIBS)
		$(CC) -o bpsink bpsink.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpsink ./bin

bpdriver:	bpdriver.o libbp.a $(BPLIBS)
		$(CC) -o bpdriver bpdriver.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpdriver ./bin

bpecho:		bpecho.o libbp.a $(BPLIBS)
		$(CC) -o bpecho bpecho.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpecho ./bin

bpcounter:	bpcounter.o libbp.a $(BPLIBS)
		$(CC) -o bpcounter bpcounter.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpcounter ./bin

bpsendfile:	bpsendfile.o libbp.a $(BPLIBS)
		$(CC) -o bpsendfile bpsendfile.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpsendfile ./bin

bprecvfile:	bprecvfile.o libbp.a $(BPLIBS)
		$(CC) -o bprecvfile bprecvfile.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bprecvfile ./bin

bpnmtest:	bpnmtest.o libbp.a $(BPLIBS)
		$(CC) -o bpnmtest bpnmtest.o -L./lib -L$(ROOT)/lib $(LBP) -lici $(PTHREADS) -lm
		cp bpnmtest ./bin

#	-	-	Libraries	-	-	-	-	-

libbp.a:	libbp.o $(BPPOBJS) libbpnm.o
		$(LD) libbp.a libbp.o $(BPPOBJS) libbpnm.o
		cp libbp.a ./lib

libcgr.a:	libcgr.o
		$(LD) libcgr.a libcgr.o
		cp libcgr.a ./lib

libipnfw.a:	libipnfw.o
		$(LD) libipnfw.a libipnfw.o
		cp libipnfw.a ./lib

libimcfw.a:	libimcfw.o
		$(LD) libimcfw.a libimcfw.o
		cp libimcfw.a ./lib

libdtn2fw.a:	libdtn2fw.o
		$(LD) libdtn2fw.a libdtn2fw.o
		cp libdtn2fw.a ./lib

libstcpcla.a:	libstcpcla.o
		$(LD) libstcpcla.a libstcpcla.o
		cp libstcpcla.a ./lib

libudpcla.a:	libudpcla.o
		$(LD) libudpcla.a libudpcla.o
		cp libudpcla.a ./lib

#	-	-	Object modules	-	-	-	-	-

%.o:		$(API)/%.c
		$(CC) -c $<

#%.o:		$(API)/ext/snid/%.c
#		$(CC) -c $<

%.o:		$(API)/ext/ecos/%.c
		$(CC) -c $<

%.o:		$(API)/ext/meb/%.c
		$(CC) -c $<

%.o:		$(API)/ext/bae/%.c
		$(CC) -c $<

%.o:		$(API)/ext/bpsec/%.c
		$(CC) -c $<

%.o:		$(API)/ext/phn/%.c
		$(CC) -c $<

%.o:		$(TEST)/%.c
		$(CC) -c $<

%.o:		$(UTILS)/%.c
		$(CC) -c $<

%.o:		$(DAEMON)/%.c
		$(CC) -c $<

%.o:		$(CGR)/%.c
		$(CC) -c $<

%.o:		$(IPN)/%.c
		$(CC) -c $<

%.o:		$(IMC)/%.c
		$(CC) -c $<

%.o:		$(BSSP)/%.c
		$(CC) -c $<

%.o:		$(DTN2)/%.c
		$(CC) -c $<

%.o:		$(LTP)/%.c
		$(CC) -c $<

%.o:		$(STCP)/%.c
		$(CC) -c $<

%.o:		$(TCP)/%.c
		$(CC) -c $<

%.o:		$(UDP)/%.c
		$(CC) -c $<

#%.o:		$(DCCP)/%.c
#		$(CC) -c $<

%.o:		$(BRS)/%.c
		$(CC) -c $<

%.o:		$(DGR)/%.c
		$(CC) -c $<

%.o:		$(BIBE)/%.c
		$(CC) -c $<

%.o:		$(API)/acs/%.c
		$(CC) -c $<

%.o:		$(API)/ext/cteb/%.c
		$(CC) -c $<

#%.o:		$(IPND)/%.c
#		$(CC) -I$(IPND) -c $<
