#include <stdlib.h>
#include <stdio.h>
/*
* Node linked list implementation
*/
typedef struct _node {
  char character;
  int count;
  struct _node* next;
} node;

//Stores the total number of characters which have been found.
int total;
/*
* Adds a character to the create node in the Linked List.
*/
void addToStructure(node *current, char c) {
  //Determines if the character is the same as one for node
  if (current->character == c) {
    //another character found.
    total += 1;
    //Increments occurences of character as another one of same type found.
    current->count += 1;
  }
  else if (current->next == NULL){
    //adds a new node to the end of the linked list
    total += 1;
    //Dynamically allocates space for this node.
    current->next = (node *) malloc(sizeof(node));
    current->next->character = c;
    current->next->count = 1;
    current->next->next = NULL;
  }
  else {
    //Determines if the current character is larger than the next one
    node *next = current->next;
    if (next->character > c) {
      total += 1;
      //Dyanamically allocates space to store it since it is smaller.
      node *new = (node *) malloc(sizeof(node));
      new->character = c;
      new->count = 1;
      new->next = current->next;
      current->next = new;
    }
    else {
      //erforms operation on next current.
      addToStructure(current->next, c);
    }
  }
}

/*
* Increases the occurences of all valid characters found.
*/
node* incrementCount(node* base, char c) {
  //Doesn't counter null characters
  if (c != '\0') {
    //If there are no items in the linked list sets first item to the head of linked list.
    if (base == NULL) {
      total += 1;
      //creates new node and pointer
      base = (node *) malloc(sizeof(node));
      base->character = c;
      base->count = 1;
      base->next = NULL;
    }
    //Determines if character is larger than the base of the linked list and makes nececesary changes.
    else if (base->character > c) {
      total += 1;
      //creates next node and pointer
      node *next = (node *) malloc(sizeof(node));
      next->count = 1;
      next->character = c;
      next->next = base;
      base = next;
    }
    else {
      //adds it to the inner nodes of the linked list.
      addToStructure(base, c);
    }
  }
  return base;
}

/*
* Prints out all the occurences of characters.
*/
void printCount(node* base) {
  if (base) {
    printf("Total chars counted: %d\n", total);
    node *current = base;
    printf("Char, Count\n");
    while(current != NULL) {
      printf("%c, %d\n", current->character, current->count);
      current = current->next;
    }
  }
}

/*
* Decodes a give cipher by parsing in character.
*/
char decode(node *ciper, node *key, char c) {
  //uses found to represent a boolean.
  //determines if correct value has been found.
  int found = 0;
  //Gets the count of the character from it cipher
  int count;
  //gets the char that will replace the character.
  char ch;
  //loops till the character count has been found.
  node *current = ciper;
  while (current != NULL && found == 0) {
    if (current->character == c) {
      count = current->count;
      found = 1;
    }
    current = current->next;
  }

  found = 0;
  current = key;

  //Loops over till a character will identical count has been found.
  while (current != NULL && found == 0) {
    if (current->count == count) {
      ch = current->character;
      found = 1;
    }
    current = current->next;
  }
  //replaces the whitespace indicator with actual space.
  if (ch == '_') {
    ch = ' ';
  }
  //returns the determined character
  return ch;
}
/*
* cleans space dynamically allocated after use.
*/
void cleanSpace(node *base) {
  //Cleans all the next nodes of the program
  if (base->next != NULL) {
    cleanSpace(base->next);
  }
  free(base);
}
