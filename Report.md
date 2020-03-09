# W07 Practical Report

## Overview

The specification required that a program which reads in the characters from a file and counts the occurrences of each alphabetic (upper case and lower case regraded as the same) or whitespace character in the file. Then after this program is complete it is required that a program which decodes from two files (key and cipher). Where the cipher is the correct order of the characters and the key has the correct letters. There is 1-1 mapping between key and cipher of letter which have the same number of occurrences. 

It is required that the file names be taken in the form of command line arguments.  If 1 argument is passed in then it means the occurrences of characters are being. Where are If 2 arguments are passed then that means that the 

### Assumptions

#### Counting Occurrences

* Only counter Alphabetic and Whitespace Characters
* All whitespace characters are treated as one character type.

#### Decoding

* The number of occurrences of a character is unique
* 

## Design

To store the occurrences of each letter an ordered linked list was made.

```c
typedef struct _node {
    char character;
    int count;
    struct _node *next;
} node;
```

This means that a fixed length array doesn't need to be stored to count the occurrences of characters. Only characters which are found are stored. This also made it easier to handle as the length of linked list can be determined by going all the way to the end of the linked list.

It was decided to keep the main method and the `counterMain.c` as simple as possible. So all the necessary methods required to implement where abstracted to another file called `counter.c`. The header file `counter.h` contains the definition for the Node and also the necessary libraries which are to be used outwith the file by `counterMain.c`.

```c
(node *) malloc(sizeof(node))
```

This was used when dynamically creating a node and setting the address of the node to the value of a pointer.

## Testing

## Evaluation

* Global Variable `total`
* Opening File 1 multiple times
* constructor for nodes

## Conclusion

