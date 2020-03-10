//counter.h
#ifndef COUNTER_H //only if COUNTER_H is not defined
#define COUNTER_H // # define COUNTER_H flag

/*
* Defines the data structure that will be used to store the occurences.
*/
typedef struct _node node;

void decipher(char *cipherFilename, char *keyFilename);
void error_message();
void countCharacters();
#endif
