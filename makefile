CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic

all: writer reader parent

parent: parent.c
	$(CC) $(CFLAGS) parent.c -o parent
	
writer: writer.c
	$(CC) $(CFLAGS) writer.c -o writer

reader: reader.c
	$(CC) $(CFLAGS) reader.c -o reader

clean:
	-rm writer reader parent
