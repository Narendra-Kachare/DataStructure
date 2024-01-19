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
    
        Node(int X)
        {
            Data = X;
            next = NULL;
        }
}NODE,*PNODE;


class Stack
{
    private:
        PNODE First;
        int iCount;
    
    public :
        Stack();
        void Push(int No);  // InsertLast
        int Pop();          // DeleteFirst
        void Display();
        int Count();
};

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

Stack :: Stack()
{
    cout<<"Inside Constructor"<<"\n";
    First = NULL;
    iCount = 0;

}

void Stack :: Push(int No)  // InsertLast
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

int Stack :: Pop()  // DeleteLast
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Stack is empty"<<"\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First->Data;
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
        Value = Temp->next->Data;
        delete Temp->next;
        Temp->next = NULL;
        
        
    }
    iCount--;
    return Value;
}

void Stack :: Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as stack is empty\n";
        return;
    }

    cout<<"Elements of the stack are : "<<"\n";
    PNODE Temp = First;
    for (int i = 1; i <= iCount; i++)
    {   
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->next;
    }
    cout<<"NULL"<<"\n\n";
}


int Stack :: Count()
{
    return iCount;
}



/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{

    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    Stack obj;

    cout<<"--------------------------------------------------------------\n";
    cout<<"Dynamic Implementation of Stack\n";
    cout<<"--------------------------------------------------------------\n";

    while(iChoice != 0)
    {   
        cout<<"--------------------------------------------------------------\n";
        cout<<"1 : Push element into stack\n";
        cout<<"2 : Pop element from the stack\n";
        cout<<"3 : Count the number of element from stack\n";
        cout<<"4 : Display the element from the stack\n";
        cout<<"0 : Terminate the application\n";
        cout<<"--------------------------------------------------------------\n";

        cout<<"Please enter the option : \n";
        cin>>iChoice;

        switch (iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to push : \n";
                cin>>iValue;
                obj.Push(iValue);
                break;
            case 2:
                iRet = obj.Pop();
                if(iRet != -1)
                {
                    cout<<"Poped element from the stack is : "<<iRet<<"\n";
                }
                break;
                
            case 3:
                iRet = obj.Count();
                cout<<"Number of element are : "<<iRet<<"\n";
                break;
            
            case 4:
                obj.Display();
                break;
            
            case 0:
                cout<<"Thank you for using stack application\n";
                break;;

            default:
                cout<<"Invalid Input, Please enter valid input\n";
                break;
        }


    }

    return 0;

}