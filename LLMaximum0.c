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

int Maximum(PNODE Head)
{
    int iMax = 0;
    while (Head != NULL)
    {
        if(iMax < Head->Data)
        {
            iMax = Head->Data;
        }
        Head = Head->next;
    }
    return iMax;
    
}



/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{

    PNODE First = NULL;
    int Result = 0;

    InsertFirst(&First,29);
    InsertFirst(&First,45);
    InsertFirst(&First,68);
    InsertFirst(&First,99);
    InsertFirst(&First,19);
    InsertFirst(&First,67);
    
    Display(First);

    Result = Maximum(First);
    printf("Maximum number of above linked list is : %d\n",Result);






    return 0;
}