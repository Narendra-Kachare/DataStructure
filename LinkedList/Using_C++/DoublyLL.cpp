/*
    Cpp Linked list program : Doubly Linked List
*/




/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include<iostream>
using namespace std;

typedef class Node
{
    public:
        int Data;
        struct Node *next;
        struct Node *prev;

        Node()
        {
            Data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int Value)
        {
            Data = Value;
            next = NULL;
            prev = NULL;
        }


}NODE, *PNODE;


class LinkedList
{
    public :
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

            cout<<"Elements of the linked list are : "<<"\n";

            for (int iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<"| "<<Temp->Data<<" | -> ";
                Temp = Temp->next;
            }
            cout<<"NULL"<<"\n\n";
            
        }


};

class DoublyLL : public LinkedList
{
    public:
        DoublyLL();

        ~DoublyLL();

        void InsertFirst(int No);

        void InsertLast(int No);

        void InsertAtPos(int iPos,int No);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);

        
};
;

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

DoublyLL :: DoublyLL()
{
    iCount = 0;
    First = NULL;
}

DoublyLL :: ~DoublyLL()
{
    cout<<"Inside Destructor"<<"\n";

    PNODE Temp = First;
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Temp = First;
        First = First->next;
        delete Temp;
    }
    
}

void DoublyLL :: InsertFirst(int No)
{
    PNODE newn = new Node(No);
    

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }

    iCount++;
}

void DoublyLL :: InsertLast(int No)
{
    PNODE newn = new Node(No);

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE Temp = First;
        for (int i = 1; i < iCount; i++)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }

    iCount++;
}

void DoublyLL :: InsertAtPos(int iPos, int No)
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
        newn->prev = Temp;
        Temp->next = newn;
        newn->next->prev = newn;
    }
    
    

    iCount++;
}

void DoublyLL :: DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    

    iCount--;
}

void DoublyLL :: DeleteLast()
{
    if (First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE Temp = First;

        for (int i = 1; i < iCount; i++)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next = NULL;
        
    }
    

    iCount--;
}

void DoublyLL :: DeleteAtPos(int iPos)
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
    DoublyLL obj1;

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

    int iRet = obj1.Count();
    cout<<"Length of the Doubly LL are : "<<iRet<<"\n\n";

    return 0;
}