#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char character;
  int count;
  struct Node *next;
} Node;


int total = 0;
Node *base = NULL;

void addToStructure(Node *node, char c) {
  if (node->character == c) {
    total += 1;
    node->count += 1;
  }
  else if (node->next== NULL){
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
      printCount();
    }
    else {
      printf("Trying to open file: No such file or directory");
    }
    return 0;
  }
}
