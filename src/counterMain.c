#include "counter.h"

int main(int argc, char *argv[]) {
  // printf("The number of arguments: %d", argc);
  // printf("You typed \"%s\"\n", argv[1]);
  if (argc == 2) {
    node* base = new_occurence(argv[1]);
    if (base) {
      //Prints the count if the Linked List is not null
      printCount(base);
    }
  }
  else if (argc == 3) {
    node *cipher = new_occurence(argv[1]);
    node *key = new_occurence(argv[2]);
    //prints the cipher if the linked list of both are non-null
    if(cipher && key){
      //decipher
      decipher(cipher, key, argv[1]);
    }
  }
  else {
    error_message();
  }
  return 0;
}
