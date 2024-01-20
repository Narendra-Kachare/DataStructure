/*
    By using Linked List Summation
*/

/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *next;
} NODE, *PNODE, **PPNODE;

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

void InsertFirst(PPNODE Head, int No)
{
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the node
    newn->Data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    printf("Nodes of the linked list are : \n");
    while (Head != NULL)
    {
        printf("| %d | -> ", (*Head).Data);
        Head = Head->next;
    }
    printf("NULL\n\n");
}

void CheckPerfect(PNODE Head)
{

    while (Head != NULL)
    {
        int iSum = 0;

        for (int i = 1; i < (Head->Data / 2) + 1; i++)
        {
            if (Head->Data % i == 0)
            {
                iSum = iSum + i;
                
            }
        }
        if (iSum == Head->Data)
        {
            printf("%d is perfect number\n", Head->Data);
        }
        Head = Head->next;
    }
}

/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{

    PNODE First = NULL;
    int Result = 0;

    InsertFirst(&First, 67);
    InsertFirst(&First, 6);
    InsertFirst(&First, 8128);
    InsertFirst(&First, 28);
    InsertFirst(&First, 496);
    InsertFirst(&First, 11);

    Display(First);

    CheckPerfect(First);

    return 0;
}