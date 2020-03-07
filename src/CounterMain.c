#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
* Defines the Node which will be used to form the linked lists
*/
typedef struct Node {
  //stores the charater
  char character;
  //Stores the occurenes of the character
  int count;
  //Stores the next node
  struct Node *next;
} Node;

//Stores the total number of characters which have been found.
int total = 0;
//Creates the base or head of linked list.
Node *base = NULL;

/*
* Adds a character to the create node in the Linked List.
*/
void addToStructure(Node *node, char c) {
  //Determines if the character is the same as one for node
  if (node->character == c) {
    //another character found.
    total += 1;
    //Increments occurences of character as another one of same type found.
    node->count += 1;
  }
  else if (node->next == NULL){
    total += 1;
    node->next = (Node *) malloc(sizeof(Node));
    node->next->character = c;
    node->next->count = 1;
    node->next->next = NULL;
  }
  else {
    Node *next = node->next;
    if (next->character > c) {
      total += 1;
      Node *new = (Node *) malloc(sizeof(Node));
      new->character = c;
      new->count = 1;
      new->next = (Node *) malloc(sizeof(Node));
      new->next = node->next;
      node->next = new;
    }
    else {
      //erforms operation on next node.
      addToStructure(node->next, c);
    }
  }
}

char setGroup(char c) {
  char standardChar;
  if (isspace(c)) {
    standardChar = '_';
  }
  else if(isalpha(c)){
    standardChar = tolower(c);
  }
  else {
    return '\0';
  }
  return standardChar;
}

void incrementCount(char ch) {
  char c = setGroup(ch);
  if (c != '\0') {
    if (base == NULL) {
      total += 1;
      base = (Node *) malloc(sizeof(Node));
      base->character = c;
      base->count = 1;
      base->next = NULL;
    }
    else if (base->character > c) {
      total += 1;
      Node *next = (Node *) malloc(sizeof(Node ));
      next->count = 1;
      next->character = c;
      next->next = base;
      base = next;
    }
    else {
      addToStructure(base, c);
    }
  }
}

void printCount() {
  printf("Total chars counted: %d\n", total);
  printf("Char, Count\n");
  Node *current = base;
  while(current != NULL) {
    printf("%c, %d\n", current->character, current->count);
    current = current->next;
  }
}

char decode(Node *ciper, Node *key, char c) {
  int found = 0;
  int count;
  char ch;
  Node *current = (Node *) malloc(sizeof(Node));
  current = ciper;
  while (current != NULL && found == 0) {
    if (current->character == c) {
      count = current->count;
      found = 1;
    }
    current = current->next;
  }
  found = 0;
  current = (Node *) malloc(sizeof(Node));
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

int main(int argc, char *argv[]) {
  // printf("The number of arguments: %d", argc);
  // printf("You typed \"%s\"\n", argv[1]);
  if (argc == 1) {
    printf("Usage: ./CounterMain <some_file.txt> [key.txt]");
  }
  else {
    FILE* fp;
    //returns the null pointer if opening failed
    fp = fopen(argv[1], "r");
    if (fp) {
      char ch = getc(fp);
      while (ch != EOF) {
        incrementCount(ch);
        ch = getc(fp);
      }
      fclose(fp);
      if (argc == 3) {
        FILE* fp2;
        Node *base2 = (Node *) malloc(sizeof(Node));
        base2 = base;
        base = NULL;
        fp2 = fopen(argv[2], "r");
        if (fp2) {
          ch = getc(fp2);
          while (ch != EOF) {
            incrementCount(ch);
            ch = getc(fp2);
          }
          fclose(fp2);
          FILE* fp3;
          fp3 = fopen(argv[1], "r");
          if (fp3) {
            printf("Decoding\n");
            ch = getc(fp3);
            while (ch != EOF) {
              printf("%c", decode(base2, base, setGroup(ch)));
              ch = getc(fp3);
            }
            printf("\n");
            fclose(fp3);
          }
        }
        else {
          printf("Trying to open file: No such file or directory");
        }
      }
      else {
        printCount();
      }
    }
    else {
      printf("Trying to open file: No such file or directory");
    }
  }
  return 0;
}
