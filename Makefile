CC = gcc
CFLAGS  =-w
LDFLAGS =
LEX     =flex
YACC    =bison -dy
YFLAGS  = 
OBJFILES =LLC_Liste.o ERREURs.o OperationTypeG.o TableDesSymbole.o Quadruplets.o lexical.o synt.o 
TARGET = COMPILER

all: $(TARGET)
	
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

lexical.o: lexical.l synt.c LLC_Liste.h Colors.h 
synt.o: synt.y Colors.h

LLC_Liste.o:LLC_Liste.c LLC_Liste.h
	$(CC) $(CFLAGS) -c LLC_Liste.c
ERREURs.o:ERREURs.h LLC_Liste.h Colors.h
	$(CC) $(CFLAGS) -c ERREURs.c
OperationTypeG.o:OperationTypeG.c TypeGlobale.h OperationTypeG.h ERREURs.h 
	$(CC) $(CFLAGS) -c OperationTypeG.c
TableDesSymbole.o:TableDesSymbole.c TypeGlobale.h OperationTypeG.h LLC_Liste.h
	$(CC) $(CFLAGS) -c TableDesSymbole.c
Quadruplets.o:Quadruplets.c LLC_Liste.h Colors.h
	$(CC) $(CFLAGS) -c Quadruplets.c

clean:
	rm -f $(OBJFILES) $(TARGET) *~
