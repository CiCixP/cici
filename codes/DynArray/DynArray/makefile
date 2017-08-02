OBJS = main.o DynamicArray.o DynamicDouble.o
CC = clang++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

runFile : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runFile

main.o : main.C DynamicArray.h DynamicDouble.h
	$(CC) $(CFLAGS) main.C

DynamicArray.o : DynamicArray.h
	$(CC) $(CFLAGS) DynamicArray.C

DynamicDouble.o : DynamicDouble.h
	$(CC) $(CFLAGS) DynamicDouble.C

clean:
	\rm *.o *~ runFile

tar:
	tar cfv runFile.tar main.C DynamicArray.h DynamicArray.C \
		DynamicDouble.h DynamicDouble.C
