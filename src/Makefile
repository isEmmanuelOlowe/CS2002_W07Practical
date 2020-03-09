CC = clang
CFLAGS = -c -Wall -Wextra -O0
LFLAGS = -Wall -Wextra
DEPS = counter.h

CounterMain: counterMain.o counter.o
	${CC} ${LFLAGS} counterMain.o counter.o -o CounterMain

counterMain.o: counterMain.c $(DEPS)
	${CC} ${CFLAGS} counterMain.c

counter.o: counter.c
	${CC} ${CFLAGS} counter.c

clean:
	rm *.o CounterMain
