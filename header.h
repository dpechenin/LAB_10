#ifndef LAB_10_HEADER_H
#define LAB_10_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//для первого задания
typedef struct Node {
    int pow;
    int coef;
    struct Node *next;
} Node;

Node* createPoly();
void printPoly(Node*);
Node* makeNewPoly(Node*, Node*);
void deleteList(Node**);

//для второго задания
typedef struct Word{
    char *word;
    struct Word *prev;
    struct Word *next;
} Word;

typedef struct List{
    int size;
    Word *head;
    Word *tail;
} List;

List* fromString();
void printList(List*);
void newList(List*);
void deleteSentanse(List**);

#endif
