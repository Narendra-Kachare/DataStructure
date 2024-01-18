
/*
    Singly Circular LL : 
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
int Count(PNODE Head, PNODE Tail)
{   
    int iCount = 0;
    do
    {
        iCount++;
        Head = Head->next;
    }while (Head != Tail->next);
    return iCount;
}

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

void InsertFirst(PPNODE Head, PPNODE Tail, int No)
{
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialised Node
    newn->Data = No;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn; 
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head, PPNODE Tail, int No)
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
        *Tail = newn;
    }
    else
    {
        (*Tail)->next = newn;
        (*Tail) = (*Tail)->next;
    }
    (*Tail)->next = *Head;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if(*Head == NULL && *Tail == NULL)
    {
        return;
    }
    else if (*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        PNODE Temp = *Head;
        *Head = (*Head)->next;
        free(Temp);
        (*Tail)->next = *Head;

        // // or without using Temp Variable
        // (*Head) = (*Head)->next;
        // free((*Tail)->next);
        // (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE Temp = *Head;
    
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
        while (Temp->next != *Tail)
        {
            Temp = Temp->next;
        }
        
        free(*Tail);
        *Tail = Temp;
        (*Tail)->next = *Head;
    }
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int iPos, int No)
{
    int Result = 0;
    Result = Count(*Head,*Tail);

    if((iPos < 1) || (iPos > Result+1))
    {
        printf("Invalid Position");
        return;
    }
    
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
        PNODE Temp = *Head;

        // Allocate memory for Node
        newn = (PNODE)malloc(sizeof(NODE));

        // Initialised Node
        newn->Data = No;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
        
    }
    
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
    PNODE Temp = *Head;
        PNODE Temp2 = NULL;
    int Result = 0;
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
    PNODE Last = NULL;

    InsertFirst(&First,&Last,40);
    InsertFirst(&First,&Last,30);
    InsertFirst(&First,&Last,20);
    InsertFirst(&First,&Last,10);
    Display(First,Last);

    InsertLast(&First,&Last,100);
    Display(First,Last);

    DeleteFirst(&First,&Last);
    Display(First,Last);

    DeleteLast(&First,&Last);
    Display(First,Last);

    InsertAtPos(&First,&Last,2,33);
    Display(First,Last);

    DeleteAtPos(&First,&Last,3);
    Display(First,Last);

    return 0;
}
