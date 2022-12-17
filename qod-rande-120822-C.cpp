// Given a dictionary of words and a string made up of those words (no spaces),
// return the original sentence in a list. If there is more than one possible
// reconstruction, return any of them. If there is no possible reconstruction,
// then return null.

// For example, given the set of words 'quick', 'brown', 'the', 'fox', and the
// string "thequickbrownfox", you should return ['the', 'quick', 'brown',
// 'fox'].

// Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the
// string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or
// ['bedbath', 'and', 'beyond'].

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define W 80

void lookUpAndPrint(char **, char *);

int main(int argc, char *argv[]) {
  //////   SET UP
  // hard code "the", "quick", "brown", "fox"
  char **dictionary1 = (char **)malloc(4 * sizeof(char *));
  for (int i = 0; i < 4; i++)
    dictionary1[i] = (char *)malloc(W * sizeof(char));
  strcpy(dictionary1[0], "the");
  strcpy(dictionary1[1], "quick");
  strcpy(dictionary1[2], "brown");
  strcpy(dictionary1[3], "fox");

  char line[] = "thequickbrownfox ";
  ///////////////////////////////////////////////

  // Get the lengh of  line
  int N;
  for (N = 0; line[N] != '\0'; N++)
    ;

  // Sanity Check
  for (int i = 0; i < 4; i++)
    printf("%s\n", dictionary1[i]);
  printf("%s\n", line);
  printf("%d\n\n", N);

  // Here We Go.
  char *b = line;  // a pointer to the back
  char *f = b + 1; // a pointer to the front
  int offset = 0;  // use to walk through string
  char token[W];   // the part of string we have currently captured.
  char *s = (char *)malloc(W);  // buffer
  
  // n-square through the string and examine each pointer-bracked-item.
  while (*b != '\0') {
    while (*f != '\0') {
      // copy the string between the pointers
      char *i = b; // the 'index'
      char *p = s; // temp string-pointer to front of buffer
      while (i != f) {
        *p = *i;
        p++;
        i++;
      }
      *p = '\0';

      // look in the dictionary
      lookUpAndPrint(dictionary1, s);

      f++;
    }
    offset++;
    b = line + offset;
    f = b + 1;
  }

  // free
  free(s);
  for (int i = 0; i < 4; i++)
    free(dictionary1[i]);
  free(dictionary1);
}

void lookUpAndPrint(char **dict, char *word) {
  // just loop through the dictionary looking for the word.
  printf("Looking up:  %s ...", word);
  int found = 0;

  for (int i = 0; i < 4; i++)
    if (strcmp(dict[i], word) == 0)
      found = 1;

  if (found)
    printf(" YES\n");
  else
    printf("\n");
}

