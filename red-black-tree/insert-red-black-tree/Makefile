
SHELL 	= /bin/sh
CC 	= cc
CFLAGS  = -fPIC 

TARGET  = insert-red-black-bin
TARGET_LIB = insert-red-black-bin.so
#SOURCES = $(shell echo *.c)
#HEADERS = $(shell echo *.h)
#OBJECTS = $(SOURCES:.c=.o)
SOURCE = insert-red-black-tree.c apis.c
HEADER = insert-red-black-tree.h
OBJECT = insert-red-black-tree.o apis.o

all: $(OBJECT) $(TARGET_LIB) $(TARGET)

$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECT)

$(TARGET_LIB): $(OBJECT)
	$(CC) $(CFLAGS) -shared -o $(TARGET_LIB) $(OBJECT)

$(OBJECT):
	$(CC) $(CFLAGS) -c $(SOURCE) 

clean:
	rm -rf ./*.o
	rm -rf ./*.so
	rm $(TARGET)
