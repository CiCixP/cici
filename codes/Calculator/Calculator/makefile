OBJS = main.o Calculator.o CalcFunc.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

runFile : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runFile

main.o : main.C Calculator.h Calculator.C CalcFunc.h CalcFunc.C
	$(CC) $(CFLAGS) main.C

Calculator.o : Calculator.h
	$(CC) $(CFLAGS) Calculator.C

CalcFunc.o : CalcFunc.h
	$(CC) $(CFLAGS) CalcFunc.C

clean:
	rm *.o runFile

tar:
	tar cfv runFile.tar main.C Calculator.h Calculator.C
