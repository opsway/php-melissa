# --------------------- #
# libmdAddrPHP.so
# Melissa Data
# Date: 04/03/2006
# --------------------- #

#libmdAddr.so directory
DIR=./

#php directory
DIRPHP=./

CC=gcc
ifeq ($(shell uname), SunOS)
INCL= -I$(DIRPHP)  -I$(DIRPHP)main -I$(DIRphp)Zend -I$(DIRPHP)TSRM  
LDFLAGS=-shared
LDLIBS=-L$(DIR) -R$(DIR):/usr/local/lib -lmdAddr
CFLAGS=-g -Wall -DNDEBUG
PIC=-fpic
else
INCL=-I$(DIRPHP) -I$(DIRPHP)main -I$(DIRPHP)Zend -I$(DIRPHP)TSRM
LDFLAGS=-shared
LDLIBS=-L$(DIR) -Wl,-rpath,$(DIR) -lmdAddr
CFLAGS=-g -Wall -DNDEBUG
PIC=-fpic
endif

libmdAddrPHP.so: mdAddrPHP.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS) 

mdAddrPHP.o : mdAddrPHP.c mdAddrPHP.h mdAddr.h mdEnums.h 
	$(CC) -c $(PIC)  $< $(INCL) 

clean:
	rm -f *.o
	rm -f libmdAddrPHP.so 

