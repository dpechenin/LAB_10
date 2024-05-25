#include "header.h"

List* createList() {
    List *Sentense = (List*)malloc(sizeof(List));
    Sentense->size = 0;
    Sentense->head = NULL;
    Sentense->tail = NULL;
    return Sentense;
}

void addElem(List *Sentense, char *word) {
    Word *tmp = Sentense->head;
    Word *new_word = (Word*)malloc(sizeof(Word));
    new_word->word = word;
    new_word->next = NULL;
    if(!tmp) {
        Sentense->head = new_word;
        Sentense->tail = new_word;
        return;
    }
    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_word;
    new_word->prev = tmp;
    if(!Sentense->tail) {
        Sentense->tail = new_word;
    }
    Sentense->size++;
}

void printList(List *Sentense) {
    if(!Sentense->head) {
        printf("Строка пустая!");
    }
    Word *tmp = Sentense->head;
    while(tmp) {
        fputs(tmp->word, stdout);
        fputs(" ", stdout);
        tmp = tmp->next;
    }
}

List* fromString() {
    char str[1000];
    getchar();
    printf("Введите строку:\n");
    fgets(str, 999, stdin);
    printf("Введеная строка:\n");
    fputs(str, stdout);
    List *Sentense = createList();
    char *token = strtok(str, " .");
    while(token) {
        addElem(Sentense, token);
        token = strtok(NULL, " .");
    }
    return Sentense;
}

char *strrev(char *str) {
    size_t len = strlen(str);

    for (size_t i = 0, j = len - 1; i <= j; i++, j--) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return str;
}

void insertElem(List *Sentense, char *str, Word *word) {
    Word *ins = NULL;
    ins = (Word*)malloc(sizeof(Word));
    char *str1 = (char*)malloc(sizeof(str));
    strcpy(str1, str);
    if(strlen(str1) != 1) {
        ins->word = strrev(str1);
    }
    else {
        ins->word = str1;
    }
    ins->prev = word->prev;
    ins->next = word;
    if(Sentense->head == word) {
        Sentense->head = ins;
    }
    else {
        word->prev->next = ins;
    }
    word->prev = ins;
    Sentense->size++;
}

void newList(List *Sentense) {
    Word *tmp2 = Sentense->head->next;
    Word *tmp1 = Sentense->head;
    while(tmp2->next) {
        if(strcmp(tmp1->word, tmp2->word) >= 0) {
            tmp1 = tmp2;
        }
        tmp2 = tmp2->next;
    }
    insertElem(Sentense, tmp1->word, tmp1);
}

void deleteSentanse(List **list) {
    Word *tmp = (*list)->head;
    Word *next = NULL;
    while(tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;

    printf("List was deleted!\n");
}



