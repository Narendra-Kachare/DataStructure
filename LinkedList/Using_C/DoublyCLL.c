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
void Display(PNODE Head, PNODE Tail)
{
    if ((Head != NULL) && (Tail != NULL))
    {
        printf("Linked List will be\n");
        do
        {
            printf("| %d | -> ",Head->Data);
            Head = Head->next;
        }while (Head != Tail->next);
        printf("\n\n");
    }
    else
    {
        printf("Linked list is empty");
    }
}

int Count(PNODE Head, PNODE Tail)
{
    int iCount = 0;
    if ((Head != NULL) && (Tail != NULL))
    {
        printf("Linked List will be\n");
        do
        {
            iCount++;
            Head = Head->next;
        }while (Head != (*Tail).next);
        return iCount;
    }
    else
    {
        return 0;
    }
    
}

void InsertFirst(PPNODE Head, PPNODE Tail, int No)
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
        *Tail = newn;   // #
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;

        *Head = newn;
    }
    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head, PPNODE Tail, int No)
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
        *Tail = newn;
    }
    else
    {
        
        (*Tail)->next = newn;
        newn->prev = *Tail;
        
        *Tail = (*Tail)->next;
    }
    (*Tail)->next = *Head;
    (*Head)->prev = *Tail;
}

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Head)->prev);
        (*Tail)->next = *Head;
        (*Head)->prev = *Tail;
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Tail = (*Tail)->prev;
        free((*Tail)->next);

        (*Tail)->next = *Head;
        (*Head)->prev = *Tail;

    }
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int iPos, int No)
{
    int Result= 0;
    Result = Count(*Head,*Tail);

    PNODE Temp = *Head;

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,No);
    }
    else if(iPos == Result+1)
    {
        InsertLast(Head,Tail,No);
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

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    int Result = 0;
    PNODE Temp = *Head;
    Result = Count(*Head,*Tail);
    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos == Result)
    {
        DeleteLast(Head,Tail);
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

    InsertFirst(&First,&Last,40);
    InsertFirst(&First,&Last,30);
    InsertFirst(&First,&Last,20);
    InsertFirst(&First,&Last,10);
    Display(First,Last);

    InsertLast(&First,&Last,100);
    InsertLast(&First,&Last,200);
    InsertLast(&First,&Last,300);
    Display(First,Last);

    DeleteFirst(&First,&Last);
    Display(First,Last);

    DeleteLast(&First,&Last);
    DeleteLast(&First,&Last);
    Display(First, Last);

    InsertAtPos(&First,&Last,4,44);
    Display(First,Last);

    DeleteAtPos(&First,&Last,3);
    Display(First,Last);

    int iRet = Count(First,Last);
    printf("Total number of count of Nodes in LL is : %d\n",iRet);


    return 0;
}