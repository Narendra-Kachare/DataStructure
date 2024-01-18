
/*
    Singly LL : 
*/

/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;



/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////
int Count(PNODE Head)
{   
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

void Display(PNODE Head)
{
    printf("Elements of linkedlist are : \n");

    while(Head != NULL)
    {
        printf("| %d |->",Head->Data);
        Head = Head->next;
    }
    printf("NULL\n\n");
}

void InsertFirst(PPNODE Head, int No)
{
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialised Node
    newn->Data = No;
    newn->next = NULL;

    if(*Head == NULL)
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

    // Allocate memory for Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialised Node
    newn->Data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
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
    if(*Head == NULL)
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
    int iResult = Count(*Head);
    if ((iPos < 1) || (iPos > iResult+1))
    {
        printf("Invalid Argument\n");
        return;
    }

    PNODE Temp = *Head;
    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos == iResult+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        // Create node
        PNODE newn = NULL;

        // Allocate memory for node
        newn = (PNODE)malloc(sizeof(NODE));

        // Initialise the node
        newn->Data = No;
        newn->next = NULL;


        int iCnt = 0;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }

        // Sequence is Important
        newn->next = Temp->next;
        Temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    PNODE Temp2 = NULL;
    int iResult = Count(*Head);
    if ((iPos < 1) || (iPos > iResult))
    {
        printf("Invalid Argument\n");
        return;
    }
    
    PNODE Temp = *Head;
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iResult+1)
    {
        DeleteLast(Head);
    }
    else
    {
        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        Temp2 = Temp->next;
        Temp->next = Temp->next->next;
        free(Temp2);
    }
}



/////////////////////////////////////////////////
// Entry Point function
/////////////////////////////////////////////////

int main()
{

    PNODE First = NULL;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    Display(First);

    InsertLast(&First,100);
    InsertLast(&First,200);
    InsertLast(&First,300);
    Display(First);

    DeleteFirst(&First);
    DeleteFirst(&First);
    Display(First);

    DeleteLast(&First);
    Display(First);

    InsertAtPos(&First,2,33);
    InsertAtPos(&First,3,34);
    InsertAtPos(&First,4,35);
    Display(First);

    return 0;
}