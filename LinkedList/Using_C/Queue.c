
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

void Enqueue(PPNODE Head, int No)  // InsertLast
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

int Dequeue(PPNODE Head)       // DeleteFirst
{
    PNODE Temp = *Head;
    int Value = 0;
    if(*Head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if((*Head)->next == NULL)
    {
        Value = Temp->Data;
        free(*Head);
        *Head = NULL;
    }
    else
    {
        Value = Temp->Data;
        *Head = (*Head)->next;
        free(Temp);
    }
    return Value;
}


/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;
    int iRet = 0;
    int iChoice = 1;
    int iValue = 0;

    printf("-----------------------------------------------------\n");
    printf("Dynamic Implementation of Queue\n");
    printf("-----------------------------------------------------\n");

    while(iChoice != 0)
    {
            printf("-----------------------------------------------------\n");
            printf("1 : Insert element into Queue\n");
            printf("2 : Remove element from the Queue\n");
            printf("3 : Display elements from Queue\n");
            printf("4 : Count number of elements from Queue\n");
            printf("0 : Terminate the application\n");
            printf("-----------------------------------------------------\n");

            printf("Please enter the option : \n");
            scanf("%d",&iChoice);

            switch(iChoice)
            {
                case 1: 
                    printf("Enter the element that you want to insert\n");
                    scanf("%d",&iValue);
                    Enqueue(&First,iValue);
                    break;
                
                case 2: 
                    iRet = Dequeue(&First);
                    if(iRet != -1)
                    {
                        printf("Removed element from Queue is : %d\n",iRet);
                    }
                    break;

                case 3: 
                    Display(First);
                    break;

                case 4:
                    iRet = Count(First);
                    printf("Number of elements are : %d\n",iRet);
                    break;

                case 0:
                    printf("Thank you for using the applicatoion\n");
                    break;

                default:
                    printf("Please enter valid option\n");
                    break;
            }  // End of switch 
    } // End of while 

    return 0;
}