/*
    By using Linked List Summation
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

void InsertFirst(PPNODE Head, int No)
{
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the node
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

void Display(PNODE Head)
{
    printf("Nodes of the linked list are : \n");
    while (Head != NULL)
    {
        printf("| %d | -> ",(*Head).Data);
        Head = Head->next;
    }
    printf("NULL\n\n");
    
}

int Summation(PNODE Head)
{
    int iSum = 0;
    while (Head != NULL)
    {
        iSum = iSum + (Head->Data);
        Head = Head->next;
    }
    return iSum;
    
}



/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{

    PNODE First = NULL;
    int Result = 0;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    
    Display(First);

    Result = Summation(First);
    printf("Summation of above linked list is : %d\n",Result);






    return 0;
}