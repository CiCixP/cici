OBJS = main.o Calculator.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

runFile : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runFile

main.o : main.C Calculator.h Calculator.C
	$(CC) $(CFLAGS) main.C

Calculator.o : Calculator.h
	$(CC) $(CFLAGS) Calculator.C

clean:
	\rm *.o *~ runFile

tar:
	tar cfv runFile.tar main.C Calculator.h Calculator.C
