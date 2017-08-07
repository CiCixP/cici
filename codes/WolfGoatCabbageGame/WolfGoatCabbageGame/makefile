OBJS = main.o WGCFunc.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

runFile : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runFile

main.o : main.C WGCFunc.h WGCFunc.C
	$(CC) $(CFLAGS) main.C

WGCFunc.o : WGCFunc.h
	$(CC) $(CFLAGS) WGCFunc.C

clean:
	\rm *.o *~ runFile

tar:
	tar cfv runFile.tar main.C WGCFunc.h WGCFunc.C
