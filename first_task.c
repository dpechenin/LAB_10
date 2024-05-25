#include "header.h"

void addELem(Node* head, int coef, int pow) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->coef=coef;
    new_node->pow=pow;
    Node* tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

Node* createPoly() {
    Node *head = (Node*)malloc(sizeof(Node));
    printf("Введите количество членов в полиноме: ");
    int n;
    scanf("%d", &n);
    if(n == 0) return NULL;
    printf("Введите коэффициент и степень при x для 1 - го члена: ");
    scanf("%d %d", &(head->coef), &(head->pow));
    getchar();
    Node *tmp1 = head;
    int i = 1;
    while(tmp1 && i < n) {
        printf("Введите коэффициент и степень при x для %d - го члена: ", i + 1);
        int coef, pow;
        scanf("%d %d", &coef, &pow);
        getchar();
        if(tmp1->pow == pow) {
            printf("Вы уже вводили данную степень!\n");
            continue;
        }
        else {
            addELem(head, coef, pow);
            i++;
        }
        tmp1 = tmp1->next;
    }
    return head;
}

void printMonom(int coef, int pow) {
    if(coef == 0) {
        return;
    }
    else if(coef == 1) {
        printf("x^%d", pow);
    }
    else if(pow == 1) {
        printf("%dx", coef);
    }
    else if(pow == 0) {
        printf("%d", coef);
    }
    else {
        printf("%dx^%d", coef, pow);
    }
}

void printPoly(Node *tmp) {
    if(!tmp) {
        printf("Полином не содежит членов");
    }
    while(tmp) {
        printMonom(tmp->coef, tmp->pow);
        if(tmp->next  && tmp->next->coef && tmp->coef) {
            printf("+");
        }
        tmp = tmp->next;
    }
    printf("\n");
}

int max(int a, int b) {
    if(a >= b) {
        return a;
    }
    return b;
}

Node* makeNewPoly(Node *p1, Node *p2) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    int c = 0;
    while(p1) {
        while(p2) {
            if(p1->pow == p2->pow) {
                int coef = max(p1->coef, p2->coef);
                int pow = p2->pow;
                addELem(tmp, coef, pow);
                c++;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    if(!c) {
        return NULL;
    }
    return tmp;
}

void deleteList(Node **head) {
    Node *next, *tmp = *head;

    while(tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }

    *head = NULL;

    printf("List was deleted!\n");
}