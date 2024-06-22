CC= gcc
CFLAGS= -O2 

INC=  -I/usr/include/X11R5 -I/usr/include/X11 -I/usr/X11R6/include/X11  -I/opt/X11/include -I/usr/local/include
LIBS= -leggx -L/usr/X11R6/lib -lX11 -lgsl -lm

###  Run options  ############################################
RUN_OPTIONS= -DEGGX

SOURCES= main.c function.c egg.c 
OBJECTS= main.o function.o egg.o 

TARGET= thomas

.c.o	:$(SOURCES)
	$(CC) -c $(CFLAGS) $(INC) $(RUN_OPTIONS) $< -o $@ 

$(TARGET)	:$(OBJECTS)
	$(CC) $(CFLAGS) $(RUN_OPTIONS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean	:
	rm -f $(OBJECTS) *.core core a.out *~ "#"* *.ln $(TARGET)
#	rm -f $(OBJECTS) *.core core $(TARGET) a.out *~ "#"*

lint	:
	lint -cbx $(SOURCES)
