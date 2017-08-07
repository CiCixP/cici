OBJS = main.o geomShapeClass.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

runFile : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o runFile

main.o : geomShapeClass.h geomShapeClass.C
	$(CC) $(CFLAGS) main.C

geomShapeClass.o : geomShapeClass.h
	$(CC) $(CFLAGS) geomShapeClass.C

clean:
	\rm *.o *~ runFile

tar:
	tar cfv runFile.tar main.C geomShapeClass.h geomShapeClass.C
