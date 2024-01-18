/*
        SinglyCLL .cpp
*/

/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include<iostream>
using namespace std;


//////////////////////////////////////////////////
// Class
//////////////////////////////////////////////////

typedef class Node
{
    public :
        int Data;
        Node *next;
    
        Node()
        {
            Data = 0;
            next = NULL;
        }

        Node(int X)
        {
            Data = X;
            next = NULL;
        }
}NODE, *PNODE;


class LinkedList
{
    public:
        PNODE First;
        int iCount;

        LinkedList()
        {
            First = NULL;
            iCount = 0;
        }

        virtual void InsertFirst(int No) = 0;
        virtual void InsertLast(int No) = 0;
        virtual void InsertAtPos(int iPos, int No) = 0;

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

            cout<<"Elements of the linked list are : "<<"\n\n";
            for (int iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<"| "<<Temp->Data<<" | -> ";
                Temp = Temp->next;
            }
            cout<<Temp->Data<<"\n\n";

        }

};


class SinglyCLL : public LinkedList
{
    private:
        PNODE Last;

    public:
        SinglyCLL();
        ~SinglyCLL();

        void InsertFirst(int No);

        void InsertLast(int No);

        void InsertAtPos(int iPos, int No);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);
};

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

SinglyCLL :: SinglyCLL()
{
    Last = NULL;
}

SinglyCLL :: ~SinglyCLL()
{
    cout<<"Inside Destructor"<<"\n";
    PNODE Temp = First;

    for (int iCnt = 1; iCnt < iCount; iCnt++)
    {
        Temp = First;
        First = First->next;
        delete Temp;
    }
    
}

void SinglyCLL :: InsertFirst(int No)
{
    PNODE newn = new Node(No);

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    
    iCount++;
}

void SinglyCLL :: InsertLast(int No)
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
        Last = Last->next;
        newn->next = First;
    }
    Last->next = First;

    iCount++;
}

void SinglyCLL :: InsertAtPos(int iPos, int No)
{

    if (iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE Temp = First;
        PNODE newn = new Node(No);

        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        
        newn->next = Temp->next;
        Temp->next = newn;
    }
    
    
    


    iCount++;
}

void SinglyCLL :: DeleteFirst()
{

    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    


    iCount--;
}

void SinglyCLL :: DeleteLast()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE Temp = First;

        for (int iCnt = 1; iCnt < iCount-1; iCnt++)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Last = Temp;
        Last->next = First;
    }

    iCount--;
}

void SinglyCLL :: DeleteAtPos(int iPos)
{

    if (iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = First;
        PNODE TempX = NULL;

        for (int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            Temp = Temp->next;
        }
        
        TempX = Temp->next;

        Temp->next = Temp->next->next;
        delete TempX;

        iCount--;
    }
}

/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    int iRet  = 0;
    SinglyCLL obj1;

    obj1.InsertFirst(101);
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

    obj1.DeleteAtPos(4);
    obj1.Display();
    
    obj1.InsertAtPos(4,44);
    obj1.Display();


    iRet = obj1.Count();
    cout<<"Length of the linked list are : "<<iRet<<"\n\n";


    return 0;
}