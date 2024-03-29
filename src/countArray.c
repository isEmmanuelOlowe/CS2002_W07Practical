#include <stdio.h>
#include <stdlib.h>
#define ALPHABETICAL ('a' - 1)
#define WHITESPACE 0
#define MAX_LENGTH ('z' - '_')

/*
* Node stores Total and Character
*/
typedef struct _node {
  unsigned int character[MAX_LENGTH];
  unsigned int total;
} node;

/*
* Adjusts index provided to get and set correct index from array.
*/
int indexCorrector(char c) {
  if (c == '_') {
    return WHITESPACE;
  }
  else {
    return c - ALPHABETICAL;
  }
}


/*
* Increases the occurences of a valid character found.
*/
node* incrementCount(node* base, char c) {
  //Doesn't counter null characters
  if (c != '\0') {
    if (base == NULL) {
      base = (node *) malloc(sizeof(node));
    }
    base->character[indexCorrector(c)] += 1;
    base->total += 1;
  }
  return base;
}

/*
* Prints out all the occurences of characters.
*/
void printCount(node* base) {
  if (base) {
    printf("Total chars counted: %d\n", base->total);
    printf("Char, Count\n");
    //prints the whitespace found if any.
    if (base->character[WHITESPACE]) {
      printf("_, %d\n", base->character[WHITESPACE]);
    }
    //Prints the alphabetical characters if found.
    for (int i = 1; i < MAX_LENGTH; i++) {
      if (base->character[i]) {
        printf("%c, %d\n", i + ALPHABETICAL, base->character[i]);
      }
    }
  }
}

/*
* Decodes a give cipher by parsing in character.
*/
char decode(node *cipher, node *key, char c) {
  char ch;
  //gets the characters count form the cipher
  unsigned int count = cipher->character[indexCorrector(c)];
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (count == key->character[i]){
      if (i == 0) {
        ch = ' ';
      }
      else {
        //adjusts it to be correct character
        ch = i + ALPHABETICAL;
      }
    }
  }
  return ch;
}

/*
* Cleans dynamically allocated memory used.
*/
void cleanSpace(node *base) {
  free(base);
}
