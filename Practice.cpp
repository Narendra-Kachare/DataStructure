
/*
    Practice.cpp for practice purpose

*/


/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////

#include <iostream>
using namespace std;

//////////////////////////////////////////////////
// Class Name : Node 
// Description : used for create new Node members.
// Input : 
// Output : 
// Author : Narendra Mahadev Kachare
// Date : 17/01/2024
//////////////////////////////////////////////////
typedef class Node
{
    public:
        int Data;
        struct Node* next;
        struct Node* prev;

        Node()
        {
            Data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int X)
        {
            Data = X;
            next = NULL;
            prev = NULL;
        }

}NODE, *PNODE;

//////////////////////////////////////////////////
// Class Name : LinkedList 
// Description : used for defining linked list members
// Input : 
// Output : 
// Author : Narendra Mahadev Kachare
// Date : 17/01/2024
//////////////////////////////////////////////////
class LinkedList
{
    public:
        int iCount;
        PNODE First;

    LinkedList()
    {
        iCount = 0;
        First = NULL;
    }

    virtual void InsertFirst(int No) = 0;

    virtual void InsertLast(int No) = 0;

    virtual void InsertAtPos(int iPos,int No) = 0;

    virtual void DeleteFirst() = 0;

    virtual void DeleteLast() = 0;

    virtual void DeleteAtPos(int iPos) = 0;

    int Count()
    {
        return iCount;
    }

    void Display()
    {
        PNODE Temp = First;

        for (int iCnt = 1; iCnt <= iCount; iCnt++)
        {
            cout<<" | "<<Temp->Data<<" | -> ";
            Temp = Temp->next;
        }
        cout<<"NULL"<<"\n";
    }

};

class DoublyCLL : public LinkedList
{
    public:
        PNODE Last;

    public:
        DoublyCLL();
        ~DoublyCLL();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int iPos,int No);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};



/////////////////////////////////////////////////
// Helper Function
/////////////////////////////////////////////////

DoublyCLL :: DoublyCLL()
{
    Last = NULL;
}

DoublyCLL :: ~DoublyCLL()
{}

void DoublyCLL :: InsertFirst(int No)
{
    PNODE newn = new Node(No);

    /*
        PNODE newn = new Node;
        newn->Data = No;
        newn->next = NULL;
        newn->prev = NULL;
    */

   if (First == NULL && Last == NULL)
   {
        First = newn;
        Last = newn;
   }
   else
   {
        newn->next = First;
        First->prev = newn;
        First = newn;
        
   }
   Last->next = First;
   First->prev = Last;

   iCount++;
   
}

void DoublyCLL :: InsertLast(int No)
{
    PNODE newn = new Node(No);

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        
        Last->next = newn;
        newn->prev = Last;
        Last = Last->next;
            
    }
    First->prev = Last;
    Last->next = First;

    iCount++;
}

void DoublyCLL :: DeleteFirst()
{   
    if (iCount == 0)        // LL is empty
    {
        return;
    }
    else if(iCount == 1)    // LL contains one Node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // LL contain more than one Node
    {
        First = First->next;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

void DoublyCLL :: DeleteLast()
{
    if (iCount == 0)        // LL is empty
    {
        return;
    }
    else if(iCount == 1)    // LL contains one Node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // LL contain more than one Node
    {
        Last = Last->prev;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

void DoublyCLL :: InsertAtPos(int iPos, int No)
{
    if (iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    

    if(iPos == 1)
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
        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }

        PNODE newn = new Node(No);

        

        newn->next = Temp->next;
        newn->prev = Temp;
        Temp->next = newn;
        newn->next->prev = newn;
        
    }
    iCount++;
}

void DoublyCLL :: DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = First;
        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete Temp->next->prev;
        Temp->next->prev = Temp;
        
    }
    iCount--;
}




/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    DoublyCLL obj1;



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

    obj1.DeleteAtPos(3);
    obj1.Display();

    obj1.InsertAtPos(4,33);
    obj1.Display();

    cout<<"Length of the linked list is : "<<obj1.iCount<<"\n";



    return 0;
}