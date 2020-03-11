CC = clang
CFLAGS = -c -Wall -Wextra -O0
LFLAGS = -Wall -Wextra
MAIN_DEPS = counter.h
COLLECTION_DEPS = countCollection.h

All: CounterMain AlternativeMain

CounterMain: counterMain.o characterCount.o countArray.o
	${CC} ${LFLAGS} counterMain.o characterCount.o countArray.o -o CounterMain

AlternativeMain:counterMain.o characterCount.o countLinkedList.o
	${CC} ${LFLAGS} counterMain.o characterCount.o countLinkedList.o -o AlternativeMain

counterMain.o: counterMain.c $(MAIN_DEPS)
	${CC} ${CFLAGS} counterMain.c

characterCount.o: characterCount.c $(COLLECTION_DEPS)
	${CC} ${CFLAGS} characterCount.c

countLinkedList.o: countLinkedList.c
	${CC} ${CFLAGS} countLinkedList.c

countArray.o: countArray.c
	${CC} ${CFLAGS} countArray.c

clean:
	rm *.o CounterMain AlternativeMain
