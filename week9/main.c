#include "lab9.h"
#include <stdio.h>


int main(){
    printf("hello owrld\n");
    char string1[] = "hello";
    char uchar = 'l';
    StringBuilder* uString = newBuilder();
    printf("Size: %d\n", getSize(uString));
    printf("First Char %c\n", firstChar(uString));
    printf("Append Results %d\n", appendChar(uString, uchar));
    printf("First Char %c\n", firstChar(uString));
    printf("Append String Results %d\n", appendStr(uString, string1));
    printf("String full %s\n", toStr(uString));
    printf("String full %s\n", toStr(uString));
    printf("String full %s\n", toStr(uString));
    printf("String full %s\n", toStr(uString));
    printf("String full %s\n", toStr(uString));
    printf("number of %c in String %d\n", uchar, countChars(uString, uchar));

    // getSize(uString);
    // firstChar(uString);
    // appendChar(uString, uchar);
    // firstChar(uString);
    // appendStr(uString, string1);
    // toStr(uString);
    // countChars(uString, uchar);


    destroy(uString);

    return 0;
}