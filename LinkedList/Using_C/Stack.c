
/*
    Implementation of stack using SinglyLL
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
}NODE,*PNODE,**PPNODE;


/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

void Display(PNODE Head)
{
    printf("Elements of the stack are : \n");
    while (Head != NULL)
    {
        printf("| %d | -> ",Head->Data);
        Head = Head->next;
    }
    printf("NULL\n");
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

void Push(PPNODE Head, int No)
{
    // create Node
    PNODE newn = NULL;

    // Allocate memory for Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Initialise the Node
    newn->Data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE Temp = *Head;

        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

void Pop(PPNODE Head)
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
        *Head = (*Head)->next;
        free(Temp);
    }
}


/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;
    int iRet = Count(First);



    Push(&First,11);
    Push(&First,21);
    Push(&First,51);
    Push(&First,101);
    Display(First);

    Pop(&First);
    Pop(&First);
    Display(First);


    printf("Length of the stack is : %d",iRet);

    return 0;
}