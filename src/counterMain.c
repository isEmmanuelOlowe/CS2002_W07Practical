#include "counter.h"

int main(int argc, char *argv[]) {
  if (argc == 2) {
    countCharacters(argv[1]);
  }
  else if (argc == 3) {
    decipher(argv[1], argv[2]);
  }
  else {
    error_message();
  }
  return 0;
}
