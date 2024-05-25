#include "header.h"

int main() {
    char work = 1;
    do {
        printf("Введите [1] или [2] для выбора заданий 1 или 2 соответственно\n "
               "или [0]-чтобы закончить: ");
        char sw;
        scanf("%c", &sw);
        switch (sw) {
            case '0':
                printf("Программа завершена\n");
                work = 0;
                break;
            case '1': {
                printf("Полином 1:\n");
                Node *Polynom1;
                Polynom1 = createPoly();
                printPoly(Polynom1);

                printf("Полином 2:\n");
                Node *Polynom2;
                Polynom2 = createPoly();
                printPoly(Polynom2);

                printf("Итоговый полином:\n");
                Node *Polynom;
                Polynom = makeNewPoly(Polynom1, Polynom2);
                printPoly(Polynom);
                deleteList(&Polynom1);
                deleteList(&Polynom2);
                deleteList(&Polynom);
            }
                break;
            case '2': {
                List *Sentense = fromString();
                newList(Sentense);
                printList(Sentense);
                deleteSentanse(&Sentense);
            }
                break;
            default:
                printf("Неправильный ввод!\n");
        }
    } while (work);
    return 0;
}
