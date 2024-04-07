#include "lab9.h"
#include <stdio.h>


// Structdef

typedef struct Node_t {
    char data;
    struct Node_t* next;
    struct Node_t* back;
} Node;

// Must use a deque would like to have two dummy nodes
// Second dummy node must have null terminator
// Size does not include either of the dummy nodes
typedef struct StringBuilder_t{
    int size;
    Node* head;
    Node* tail;
    char* stringPt;
} StringBuilder;





//* Actual function defs
/*
    newBuilder()
        Returns
            Pointer to StringBuilder ready to be used
        Uses
            Inits a new StringBuilder object ready for use with asc functs
*/
StringBuilder* newBuilder(void) {
    StringBuilder* sb = malloc(sizeof(StringBuilder));
    if (sb == NULL) {
        return NULL;
    }
    sb->size = 0;
    sb->stringPt = NULL;

    Node *headDummy, *tailDummy;
    headDummy = malloc(sizeof(Node));
    if (headDummy == NULL) {
        free(sb);
        return NULL;
    }
    tailDummy = malloc(sizeof(Node));
    if (tailDummy == NULL) {
        free(sb);
        free(headDummy);
        return(NULL);
    }
    headDummy->back = tailDummy->next = NULL;
    headDummy->next = tailDummy;
    tailDummy->back = headDummy;
    tailDummy->data = '\0';
    headDummy->data = '\0';
    sb->head = headDummy;
    sb->tail = tailDummy;
    return sb;
}


/*
    getSize(StringBuilder)
        Parameters
            b StringBuilder pointer
        Returns
            int number of characters in string
*/
int getSize(StringBuilder *b) {
    return b->size;
}


/*
    appendChar(StringBuilder, char)
        Parameters
            b pointer to StringBuilder
            c char to append
        returns
            int errorCode
                0 Bad
                1 Good
        Notes
            Always appends to back but not nessiesarily needs to 
*/
int appendChar(StringBuilder *b, char c) {
    Node* nNode = malloc(sizeof(Node));
    if (nNode == NULL) {
        return 0;
    }
    nNode->data = c;
    nNode->next = b->tail;
    nNode->back = b->tail->back;
    b->tail->back->next = nNode;
    b->tail->back = nNode;

    b->size++;
    return 1;
}


/*
    firstChar(StringBuilder)
        Parameter
            b pointer to StringBuilder
        Returns
            char first char in list
*/
char firstChar(StringBuilder *b) {
    return b->head->next->data;
}


/*
    appendStr(StringBuilder, char)
        Parameters
            b pointer to StringBuilder
            s pointer to char array
        Return
            int error code
                0 Bad
                1 Good
        Notes
            String must be null term
        Notes On implementation dets given
            Not clear if O(n) refers to n length of existing string or of added string
*/
int appendStr(StringBuilder *b, char *s) {
    int error = 1;
    while ((*s != '\0') || (error == 0)) {
        error = appendChar(b, *s);
        s++;
    }
    if (error == 0) {
        return 0;
    }
    return 1;
}


/*
    toStr(StringBuilder)
        Parameters
            b pointer to StringBuilder
        Returns
            char* pointer to char array
    for case size = 0 runs correctly because last node has null termination character
*/
char* toStr(StringBuilder *b) {

    char* uString = malloc(sizeof(char) * (b->size + 1));
    if (uString == NULL) return NULL;
    if (b->stringPt != NULL) free(b->stringPt);
    b->stringPt = uString;
    Node* cNode = b->head->next;
    for (int i = 0; i <= b->size; i++) {
        printf("%d\n ", i);
        uString[i] = cNode->data;
        cNode = cNode->next;
    }
    return b->stringPt;
}


/*
    countChars(StringBuilder, char)
        Parameters
            b pointer to StringBuilder
            c character of intrest
        Returns
            int Number of times 'c' was found in 'b'
*/
int countChars(StringBuilder *b, char c) {
    int cCount = 0;
    Node* cNode= b->head->next;
    while (cNode != NULL) {
        if (cNode->data == c) {
            cCount++;
        }
        cNode = cNode->next;
    }
    return cCount;
}


/*
    destroy
        Takes a pointer to StringBuilder and frees associated mem
*/
void destroy(StringBuilder *b) {
    Node* cNode = b->head;
    Node* nNode = b->head->next;
    while (nNode != NULL) {
        free(cNode);
        cNode = nNode;
        nNode = nNode->next;
    }
    // Deal with dummy tail-node
    free(cNode);
    free(b->stringPt);
    free(b);
}