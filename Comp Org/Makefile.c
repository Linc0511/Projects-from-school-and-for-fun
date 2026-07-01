CC = gcc
CFLAGS = -Wall -Werror

all: generator demo1 demo2

generator: generator.c
    $(CC) $(CFLAGS) generator.c -o generator

demo1: demo1.c functions.h
    $(CC) $(CFLAGS) demo1.c -o demo1

demo2: demo2.c functions.h
    $(CC) $(CFLAGS) demo2.c -o demo2

clean:
    rm -f generator demo1 demo2

submit:
    zip -9qjX submission.zip generator.c demo1.c demo2.c functions.h Makefile

.PHONY: all clean submit
