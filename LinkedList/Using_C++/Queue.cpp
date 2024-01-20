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


class Queue
{
    private:
        PNODE First;
        int iCount;
    
    public :
        Queue();
        void Enqueue(int No);  // InsertLast
        int Dequeue();          // DeleteFirst
        void Display();
        int Count();
};

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

Queue :: Queue()
{
    cout<<"Inside Constructor"<<"\n";
    First = NULL;
    iCount = 0;

}

void Queue :: Enqueue(int No)  // InsertLast
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

int Queue :: Dequeue()  // DeleteFirst
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty"<<"\n";
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

        Value = Temp->Data;
        First = First->next;
        delete Temp;
        
    }
    iCount--;
    return Value;
}

void Queue :: Display()
{
    PNODE Temp = First;
    if(First == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }

    cout<<"Elements of the Queue are : "<<"\n";
    for (int i = 1; i <= iCount; i++)
    {   
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->next;
    }
    cout<<"NULL"<<"\n\n";
}


int Queue :: Count()
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

    Queue obj;

    cout<<"--------------------------------------------------------------\n";
    cout<<"Dynamic Implementation of Queue\n";
    cout<<"--------------------------------------------------------------\n";

    while(iChoice != 0)
    {   
        cout<<"--------------------------------------------------------------\n";
        cout<<"1 : Enqueue element into Queue\n";
        cout<<"2 : Dequeue element from the Queue\n";
        cout<<"3 : Count the number of element from Queue\n";
        cout<<"4 : Display the element from the Queue\n";
        cout<<"0 : Terminate the application\n";
        cout<<"--------------------------------------------------------------\n";

        cout<<"Please enter the option : \n";
        cin>>iChoice;

        switch (iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to Enqueue : \n";
                cin>>iValue;
                obj.Enqueue(iValue);
                break;
            case 2:
                iRet = obj.Dequeue();
                if(iRet != -1)
                {
                    cout<<"Dequeueed element from the Queue is : "<<iRet<<"\n";
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
                cout<<"Thank you for using Queue application\n";
                break;;

            default:
                cout<<"Invalid Input, Please enter valid input\n";
                break;
        }


    }

    return 0;

}