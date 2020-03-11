#include "counter.h"
/*
* The main method of the program
*/
int main(int argc, char *argv[]) {
  if (argc == 2) {
    //reads the characters of the file
    countCharacters(argv[1]);
  }
  else if (argc == 3) {
    //deciphers a file using cipher and key
    decipher(argv[1], argv[2]);
  }
  else {
    //invalid arugments
    error_message();
  }
  return 0;
}
