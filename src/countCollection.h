//countingCount.h
#ifndef COUNTCOLLECTION_H //only if COUNTCOLLECTION is not defined
#define COUNTCOLLECTION_H // #define COUNTCOLLECTION flag

/*
* declares the structure that will be used to count the node
*/
typedef struct _node node;

char decode(node *cipher, node *key, char c);
node* incrementCount(node *base, char c);
void printCount(node *base);
void cleanSpace(node *base);
#endif
