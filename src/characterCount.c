#include <ctype.h>
#include <stdio.h>
#include "countCollection.h"

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
* Deciphers a file text
*/
void decrypt(node *cipher, node *key, char *filename) {
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
* Counts the occurences of characters and white space.
* returns a Linked List with character and occurences in alphabetical order
*/
node* new_occurence(const char *filename) {
  //Sets the base of linked this to NULL to represent creating new linked list.
  //Creates the base or head of linked list.
  node *base = NULL;
  FILE *fp;
  //returns null pointer if opening failed
  fp = fopen(filename, "r");
  if (fp) {
    char ch = getc(fp);
    //For empty files
    while (ch != EOF) {
      base = incrementCount(base, setGroup(ch));
      ch = getc(fp);
    }
    fclose(fp);
  }
  else {
    printf("Trying to open file: No such file or directory");
    exit(0);
  }
  return base;
}

/*
* Prints the number of characters which have been counted.
*/
void countCharacters(char * filename) {
  node *base = new_occurence(filename);
  if (base) {
    //prints the counter
    printCount(base);
    cleanSpace(base);
  }
  else {
    //No characters were counted
    printf("Total chars counted: 0");
  }
}

void decipher(char *cipherFilename, char *keyFilename) {
  //decipher(arg[1], argv[2]);
  node *cipher = new_occurence(cipherFilename);
  //prints the cipher if the linked list of both are non-null
  if(cipher){
    node *key = new_occurence(keyFilename);
    if (key) {
      //decipher
      decrypt(cipher, key, cipherFilename);
      //cleans the space used
      cleanSpace(key);
    }
    //cleans the space used.
    cleanSpace(cipher);
  }
}

/*
* Error message if program not found.
*/
void error_message() {
  printf("Usage: ./CounterMain <some_file.txt> [key.txt]");
}
