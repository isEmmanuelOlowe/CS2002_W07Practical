CC = clang
CFLAGS = -c -Wall -Wextra -O0
LFLAGS = -Wall -Wextra
DEPS =

all : CounterMain $(DEPS)
	${CC} ${LFLAGS} CounterMain.o -o CounterMain

CounterMain.o: CounterMain.c
	${CC} ${CFLAGS} CounterMain.c
clean:
	rm *.o CounterMain
