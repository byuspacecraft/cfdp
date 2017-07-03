OPT = /home/ecestudent/cfdp/ion-3.6.0/opt
HEAP_PTRS = 0
PLATFORMS = arm-uClibc
# i86-redhat
# sparc-sol9
# i86-freebsd

all:
		for PF in $(PLATFORMS); \
			do \
				cd $$PF; \
				mkdir -p bin; \
				mkdir -p lib; \
				gmake all ROOT=$(OPT) PTRS=$(HEAP_PTRS); \
				cd ..; \
			done

all-doc:
		cd doc; \
		mkdir -p man; \
		mkdir -p man/man1; \
		mkdir -p man/man3; \
		mkdir -p html; \
		mkdir -p html/man1; \
		mkdir -p html/man3; \
		gmake all ROOT=$(OPT); \
		cd ..; \

clean:
		for PF in $(PLATFORMS); \
			do cd $$PF; gmake -i clean; cd ..; done

clean-doc:
		cd doc; \
		gmake -i clean; \
		cd ..; \

install:
		for PF in $(PLATFORMS); \
			do cd $$PF; gmake -i install ROOT=$(OPT); cd ..; done

install-doc:
		cd doc; \
		gmake -i install ROOT=$(OPT); \
		cd ..; \
