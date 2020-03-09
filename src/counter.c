#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

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
    total += 1;
    current->next = (node *) malloc(sizeof(node));
    current->next->character = c;
    current->next->count = 1;
    current->next->next = NULL;
  }
  else {
    node *next = current->next;
    if (next->character > c) {
      total += 1;
      node *new = (node *) malloc(sizeof(node));
      new->character = c;
      new->count = 1;
      new->next = (node *) malloc(sizeof(node));
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
* Determines the group which characters belong.
* Lower case for all alphabetical
* _ for all whitespace
*/
char setGroup(char c) {
  char standardChar;
  //The character is whitespace
  if (isspace(c)) {
    standardChar = '_';
  }
  //The character is alphabetical
  else if(isalpha(c)){
    //sends all the alphabetical characters to lower space
    standardChar = tolower(c);
  }
  //the character is not valid to be counted
  else {
    return '\0';
  }
  return standardChar;
}

/*
* Increases the occurences of all valid characters found.
*/
node* incrementCount(node* base, char ch) {
  char c = setGroup(ch);
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
      node *next = (node *) malloc(sizeof(node ));
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
  printf("Total chars counted: %d\n", total);
  if (total != 0) {
    printf("Char, Count\n");
  }
  node *current = base;
  while(current != NULL) {
    printf("%c, %d\n", current->character, current->count);
    current = current->next;
  }
}

/*
* Decodes a give cipher by parsing in character.
*/
char decode(node *ciper, node *key, char c) {
  int found = 0;
  int count;
  char ch;
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
  while (current != NULL && found == 0) {
    if (current->count == count) {
      ch = current->character;
      found = 1;
    }

    current = current->next;
  }
  if (ch == '_') {
    ch = ' ';
  }
  return ch;
}

/*
* Deciphers a file text
*/
void decipher(node *cipher, node *key, char *filename) {
  FILE *fp;
  //returns null pointer if opening failed
  fp = fopen(filename, "r");
  if (fp) {
    printf("Decoding\n");
    char ch = getc(fp);
    while (ch != EOF) {
      //Sets the character to its correct group and decodes the character.
      printf("%c", decode(cipher, key, setGroup(ch)));
      ch = getc(fp);
    }
    fclose(fp);
  }
}

/*
* Sends program usuage information.
*/
void error_message() {
  printf("Usage: ./CounterMain <some_file.txt> [key.txt]");
}

/*
* Counts the occurences of characters and white space.
* returns a Linked List with character and occurences in alphabetical order
*/
node* new_occurence(const char *filename) {
  //Sets the base of linked this to NULL to represent creating new linked list.
  //Creates the base or head of linked list.
  node* base = NULL;
  FILE *fp;
  //returns null pointer if opening failed
  fp = fopen(filename, "r");
  if (fp) {
    char ch = getc(fp);
    //For empty files
    if (ch == EOF) {
      printCount(NULL);
    }
    while (ch != EOF) {
      base = incrementCount(base, ch);
      ch = getc(fp);
    }
    fclose(fp);
  }
  else {
    printf("Trying to open file: No such file or directory");
  }
  return base;
}
