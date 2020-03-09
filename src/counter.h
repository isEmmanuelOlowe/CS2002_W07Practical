//counter.h
#ifndef COUNTER_H //only if COUNTER_H is not defined
#define COUNTER_H // # define COUNTER_H flag

/*
* Defines the linked list that will be used to store the occurences.
*/
typedef struct _node {
  //stores the charater
  char character;
  //Stores the occurenes of the character
  int count;
  //Stores the next node
  struct _node *next;
} node;

char setGroup(char c);
node* incrementCount(node* base, char ch);
void printCount(node* base);
void decipher(node *ciper, node *key, char *filename);
void error_message();
node* new_occurence(const char* filename);
#endif
