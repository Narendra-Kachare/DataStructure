/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *next;
    struct Node *prev;
}NODE, *PNODE, **PPNODE;



/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////
void Display(PNODE Head)
{
    printf("Nodes of the linked list are : \n");
    while (Head != NULL)
    {
        printf("| %d | <-> ",Head->Data);
        Head = Head->next;
    }
    printf("NULL\n\n");
}

int Count(PNODE Head)
{
    int iCount = 0;
    while (Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

void InsertFirst(PPNODE Head, int No)
{
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the Node
    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;
        *Head = newn;
        
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE Temp = *Head;
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the Node
    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        newn->prev = Temp;
        Temp->next = newn;
       
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Head)->prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int iPos, int No)
{
    int Result= 0;
    Result = Count(*Head);
    if ((iPos < 1) || (iPos > Result+1))
    {
        printf("Invalid Argument\n");
        return;
    }

    PNODE Temp = *Head;

    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos == Result+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        // Create Node
        PNODE newn = NULL;

        // Allocate memory for Node
        newn = (PNODE)malloc(sizeof(NODE));

        // Initialise the Node
        newn->Data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        
        newn->next = Temp->next;
        newn->prev = Temp;
        Temp->next->prev = newn;
        Temp->next = newn;

    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int Result = 0;
    Result = Count(*Head);
    if ((iPos < 1) || (iPos > Result+1))
    {
        printf("Invalid Argument\n");
        return;
    }    

    PNODE Temp = *Head;
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == Result)
    {
        DeleteLast(Head);
    }   
    else
    {
        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        free(Temp->next->prev);
        Temp->next->prev = Temp;
    }

}


/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;

    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);
    Display(First);

    InsertLast(&First,100);
    InsertLast(&First,200);
    InsertLast(&First,300);
    Display(First);

    DeleteFirst(&First);
    Display(First);

    DeleteLast(&First);
    Display(First);

    InsertAtPos(&First,4,44);
    Display(First);

    DeleteAtPos(&First,3);
    Display(First);

    int iRet = Count(First);
    printf("Total number of count of Nodes in LL is : %d\n",iRet);


    return 0;
}