CC=gcc  #compiler
TARGET=main #target file name
 
all:	main.o init.o sort.o process.o queue.o 
	$(CC) main.c init.c sort.c process.c queue.c -o $(TARGET)
 
clean:
	rm -r *.o $(TARGET)
