
/*
    Singly LL 

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

void Display(PNODE Head)
{
    printf("Value of the nodes are : \n");
    while (Head != NULL)
    {
        printf("|%d|->", Head->Data);
        Head = Head->next;
    }
    printf("NULL\n\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    while (Head != NULL)
    {
        Head = Head->next;
        iCnt++;
    }
    return iCnt;
}

void InsertFirst(PPNODE Head, int No)
{
    // Create Node
    PNODE newn = NULL;

    // Initialise Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the memory
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

void InsertLast(PPNODE Head, int No)
{
    // Create Node
    PNODE newn = NULL;
    PNODE Temp = *Head;

    // Initialise Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the memory
    newn->Data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;
    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int iPos, int No)
{
    int Result = 0;
    Result = Count(*Head);
    PNODE Temp = *Head;

    if ((iPos < 1) || (iPos > Result + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if (iPos == Result + 1)
    {
        InsertLast(Head, No);
    }
    else
    {
        // Allocate node
        PNODE newn = NULL;

        // Alllocate the memory
        newn = (PNODE)malloc(sizeof(NODE));

        // Initialise the memory
        newn->Data = No;
        newn->next = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int Result = 0;
    Result = Count(*Head);

    PNODE Temp1 = *Head;
    PNODE Temp2 = NULL;

    if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if (iPos == Result)
    {
        DeleteLast(Head);
    }
    else
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next;
        Temp1->next = Temp1->next->next;
        free(Temp2);
    }
}

/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    Display(First);

    InsertLast(&First, 100);
    InsertLast(&First, 200);
    InsertLast(&First, 300);
    Display(First);

    DeleteFirst(&First);
    Display(First);

    DeleteLast(&First);
    Display(First);

    InsertAtPos(&First, 3, 33);
    InsertAtPos(&First, 4, 44);
    Display(First);

    DeleteAtPos(&First, 3);
    DeleteAtPos(&First, 3);
    Display(First);

    return 0;
}