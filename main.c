#include <stdio.h>
#include <stdlib.h>
#include "Vector/vector.h"
#include "Linked_List/single_linked_list.h"
#include <stdbool.h>

int main()
{
    Node_t *ListHead = NULL;

    LinkedList_Insert_End(&ListHead, 1);
    LinkedList_Insert_End(&ListHead, 3);
    printf("Lisit before inserting \n");
    LinkedList_Print(&ListHead);
    printf("List size before inserting is %d\n", LinkedList_getSize(&ListHead));

    LinkedList_InsertPos(&ListHead, 1, 2);
    printf("Lisit After inserting \n");
    LinkedList_Print(&ListHead);
    printf("List size after inserting is %d\n", LinkedList_getSize(&ListHead));
}

