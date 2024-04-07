#include <stdio.h>
#include <stdlib.h>

typedef struct StringBuilder_t StringBuilder;


// O(1)

StringBuilder * newBuilder(void);

// O(1)

int getSize(StringBuilder *b);

// O(1)

int appendChar(StringBuilder *b, char c);

// O(1)

char firstChar(StringBuilder *b);

// O(n)

int appendStr(StringBuilder *b, char *s);

// O(n)

char * toStr(StringBuilder *b);

// O(n)

int countChars(StringBuilder *b, char c);

// O(n)

void destroy(StringBuilder *b);

