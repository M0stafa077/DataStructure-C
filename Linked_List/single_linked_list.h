/* --------------- Section : Includes --------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* --------------- Section: Macro Declarations --------------- */

/* --------------- Section: Macro Functions Declarations --------------- */

/* --------------- Section: Data Type Declarations --------------- */
typedef struct node
{
    int data;
    struct node *next;
} Node_t;
/*---------------  Section: Function Declarations --------------- */
void LinkedList_Insert_Beginning(Node_t **ListHead_ptr, int data);
void LinkedList_Insert_End(Node_t **ListHead_ptr, int data);
void LinkedList_InsertPos(Node_t **ListHead_ptr, int position, int data);
bool LinkedList_IsEmpty(Node_t **ListHead_ptr);
int LinkedList_getSize(Node_t **ListHead_ptr);
void LinkedList_Print(Node_t **ListHead_ptr);
void LinkedList_DeletePos(Node_t **ListHead_ptr, int pos);
