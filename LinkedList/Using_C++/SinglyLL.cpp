/*
    Cpp Linked list program
*/

/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include<iostream>
using namespace std;

typedef struct Node
{
    int Data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

/////////////////////////////////////////////////
// Helper function or class
/////////////////////////////////////////////////
class SinglyLL      // #2 Advance LL with 0 Complexity (due to Watchmen )
{
    private:
        PNODE First;    // Characteristics
        int iCount;

    public:
        SinglyLL();     // Default Constructor  Inline Function
        ~SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);

        void DeleteFirst();
        void DeleteLast();

        void InsertAtPos(int iPos, int No);
        void DeleteAtPos(int iPos);

};

// Implementation of all Behaviours

void SinglyLL :: InsertFirst(int No)
{
    // Create Node
    PNODE newn = NULL;

    // Allocate memory for node
    // newn = (PNODE)malloc(sizeof(Node))
    newn = new Node;    

    // Initialisation of Node
    newn->Data = No;
    newn->next = NULL;

    if(First == NULL)   // LL is empty
    {
        First = newn;
    }
    else    // LL contain at least Node
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
    
}

void SinglyLL :: InsertLast(int No)
{
    // Create Node
    PNODE newn = NULL;
    PNODE Temp = First;

    // Allocate memory for Node
    newn = new Node;

    // Initialisation of Node
    newn->Data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
    iCount++;
}

void SinglyLL :: DeleteFirst()
{
    if (First == NULL)  
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE Temp = First;

        First = First->next;
        delete Temp;        
    }
    iCount--;
}

void SinglyLL :: DeleteLast()
{
   if (First == NULL)
   {
        return;
   }
   else if (First->next == NULL)
   {
        delete First;
        First = NULL;
   }
   else
   {
        PNODE Temp = First;

        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete (Temp->next);
        Temp->next = NULL;
   }
   
   iCount--;
}

void SinglyLL :: InsertAtPos(int iPos, int No)
{
    if (iPos < 1 || iPos > (iCount+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE Temp = First;
        PNODE newn = new NODE;

        newn->Data = No;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }


        newn->next = Temp->next;
        Temp->next = newn;

        iCount++;
    }
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = First;
        PNODE TempX = NULL;
        
        for (int i = 1; i < iPos-1; i++)
        {
            Temp = Temp->next;
        }
        TempX = Temp->next;
        Temp->next = Temp->next->next;
        delete TempX;
    }
}

void SinglyLL :: Display()
{
    PNODE Temp = First;

    cout<<"Elements of linked list are : "<<"\n";

    while (Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->next;
    }
    cout<<"NULL"<<"\n\n";
    
}

int SinglyLL :: Count()
{
    return iCount;
}

SinglyLL :: SinglyLL()
{
    cout<<"Inside Constructor"<<"\n";

    First = NULL;
    iCount = 0;
}

SinglyLL :: ~SinglyLL()
{
   cout<<"Inside Destructor"<<"\n";
}


/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////
int main()
{
    SinglyLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.Display();

    obj1.InsertLast(100);
    obj1.InsertLast(200);
    obj1.InsertLast(300);
    obj1.Display();

    obj1.DeleteFirst();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    obj1.InsertAtPos(3,33);
    obj1.Display();

    obj1.DeleteAtPos(3);
    obj1.Display();



    return 0;
}