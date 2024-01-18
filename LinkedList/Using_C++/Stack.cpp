/*
    Cpp Linked list program
*/

/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////
// Class
/////////////////////////////////////////////////

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
}NODE,*PNODE;


class LinkedList
{
    public :
        PNODE First;
        int iCount;

        LinkedList()
        {
            First = NULL;
            iCount = 0;
        }

        virtual void Push(int No) = 0;
        virtual void Pop() = 0;

        void Display()
        {
            cout<<"Elements of the stack are : "<<"\n";
            PNODE Temp = First;
            for (int i = 1; i <= iCount; i++)
            {   
                cout<<"| "<<Temp->Data<<" | -> ";
                Temp = Temp->next;
            }
            cout<<"NULL"<<"\n\n";
        }

        int Count()
        {
            return iCount;
        }
};

class Stack : public LinkedList
{
    public:
        Stack();

        ~Stack();

        void Push(int No);

        void Pop();

};

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

Stack :: Stack()
{
    cout<<"Inside Constructor"<<"\n";
}

Stack :: ~Stack()
{
    cout<<"Inside Destructor"<<"\n";
    PNODE Temp = First;
    for (int i = 1; i <= iCount; i++)
    {   
        Temp = First;
        First = First->next;
        delete First;
    }
    
}

void Stack :: Push(int No)
{   
    PNODE newn = new Node(No);

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE Temp = First;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }

    iCount++;
    
}

void Stack :: Pop()
{
    PNODE Temp = First;
    if(First == NULL)
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
        delete Temp;
    }

    iCount--;
}

/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    Stack obj1;
    
    obj1.Push(11);
    obj1.Push(21);
    obj1.Push(51);
    obj1.Push(101);
    obj1.Display();

    obj1.Pop();
    obj1.Display();

    int iRet = obj1.Count();
    cout<<"Length of the Stack are : "<<iRet<<"\n";


    return 0;
}