//////////////////////////////////////////////////////////////
//          Generalised Data structure Library
//////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------
    Type                 Name of class for node          Name of class for Functionality
-----------------------------------------------------------------------------------------
    Singly Linear            SinglyLLLnode                   SinglyLLL          Done
    Singly Circular          SinglyCLLnode                   SinglyCLL          Done
    Doubly Linear            DoublyLLLnode                   DoublyLLL          Done
    Doubly Circular          DoublyCLLnode                   DoublyCLL          Done
    Stack                    Stacknode                       Stack              Done
    Queue                    Queuenode                       Queue              Done
------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////
//       Singly Linear Linked List using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public :
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL; 
        }
};

template <class T>
class SinglyLLL
{
    private :       
        SinglyLLLnode<T> * first;
        int iCount;

    public :
        SinglyLLL();

        void InsertFirst(T);        
        
        void InsertLast(T);
       
        void DeleteFirst();

        void DeleteLast();

        void Display();

        int Count();
      
        void InsertAtPos(T  , int );
        
        void DeleteAtPos(int );
        
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"object of SinglyLLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertFirst(T no)        
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;        

    this->iCount++;
}


/////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)      
    {
        this->first = newn;
    }
    else
    {
        temp= this->first;
        while(temp->next!=NULL)
        {
            temp=temp->next;   
        }
        temp->next=newn;
    }
    this->iCount++;
}

/////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to remove the node of first position
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)       
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
}


/////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to remove the node of Last position
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next !=NULL)
        {
            temp = temp->next;
            
        }
        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display the linked list
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)       
    {
        cout<<"| "<<temp->data<<" | ->";
        temp = temp->next;
    }
    cout<<"| NULL |\n";
}

/////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            count of elements present in linked list
//  Description :       Used to return count of elements present in linked list
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to return count of elements present in linked list
//  Author :            Omkar Shankar Ghadge
//  Date :              06/01/2026
//
//////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position...";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp=NULL;
    SinglyLLLnode<T> * target=NULL;
    int icnt=0;

    if(pos <1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(icnt = 1; icnt < pos-1; icnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////
//       Singly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public :
        T data;
        SinglyCLLnode<T> * next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private :
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public :
        SinglyCLL();

        void InsertFirst(T);

        void InsertLast(T);

        void InsertAtPos(T , int);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int);

        void Display();

        int Count();
};

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"object of SinglyCLL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
} 

template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn; 
    }

    this->last->next = this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyCLLnode<T> *newn = NULL;
    SinglyCLLnode<T> *temp = NULL;
    int iCnt = 0;
     
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;       
    }

    this->last->next = this->first;
    this->iCount--;
}

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != this->first)
        {
            temp = temp->next;
        }
        delete temp->next;
        this->last = temp;
    }

    this->last->next = this->first;
    this->iCount--;
}

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

template <class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> * temp = NULL;
    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != this->last->next);
    cout<<"\n";
}

template <class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//       Doubly Linear Linked List using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public :
        T data;
        DoublyLLLnode *prev;
        DoublyLLLnode *next;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private :
        DoublyLLLnode<T> * first;
        int iCount;

    public :
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

        
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<" object of DoublyLLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no , int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position \n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                     
    {
       temp = this->first;

       while(temp->next->next != NULL)
       {
            temp = temp->next;
       }

       delete temp->next;
       temp->next = NULL;
    }

    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position \n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL \n";

}

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////
//       Doubly Circular Linked List using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public :
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    private :
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public :
        DoublyCLL();

        void InsertFirst(T);

        void InsertLast(T);

        void InsertAtPos(T , int);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int);

        void Display();

        int Count();
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"object of DoublyCLL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        newn->next->prev = newn;
        this->first = newn;
    }

    this->first->prev = this->last;
    this->last->next = this->first;

    this->iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->first->prev = this->last;
    this->last->next = this->first;

    this->iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no , int pos)
{
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
    }
    
    this->first->prev = this->last;
    this->last->next = this->first;
    
    this->iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->first->prev; 
    }
    
    this->first->prev = this->last;
    this->last->next = this->first;
    
    this->iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
 
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    cout<<"<=>";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }while(temp != this->first);
    cout<<"\n";
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}


/////////////////////////////////////////////////////////////////
//              Stack using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public :
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
}; 

template <class T>
class Stack
{
    private :
        Stacknode<T> *first;
        int iCount;

    public :
        Stack();

        void push(T);

        T pop();

        T peep();

        void Display();

        int Count();
};

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully \n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;

}

template <class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    
    return Value;
}

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}


/////////////////////////////////////////////////////////////////
//              Queue using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public :
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
}; 

template <class T>
class Queue
{
    private :
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public :
        Queue();

        void enqueue(T);

        T dequeue();

        void Display();

        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully \n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->iCount++;
}

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;

}

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }

    cout<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}


///////////////////////////////////// End of Library /////////////////////////////////////

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->DeleteFirst();
    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->DeleteLast();   
    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->InsertAtPos(105 , 4);
    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->DeleteAtPos(4);
    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    delete obj;

///////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *cobj = new SinglyCLL<int>();

    cobj->InsertFirst(51);
    cobj->InsertFirst(21);
    cobj->InsertFirst(11);

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->InsertLast(101);
    cobj->InsertLast(111);
    cobj->InsertLast(121);
    
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->DeleteFirst();
    
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->DeleteLast();
    
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->InsertAtPos(105 , 4);
    
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->DeleteAtPos(4);
    
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    delete cobj;

///////////////////////////////////////////////////////////////////////


    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('a');
    dobj->InsertFirst('b');
    dobj->InsertFirst('c');

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    

    dobj->InsertLast('x');
    dobj->InsertLast('y');
    dobj->InsertLast('z');

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$' , 4);
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
    dobj->DeleteAtPos(4);
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    delete dobj;
///////////////////////////////////////////////////////////////////////

 DoublyCLL<int> *dcobj = new DoublyCLL<int>();

    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();
    cout<<"Number of nodes are :"<<dcobj->Count()<<"\n";

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);
    
    dcobj->Display();
    cout<<"Number of nodes are :"<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();
    
    dcobj->Display();
    cout<<"Number of nodes are :"<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();
    
    dcobj->Display();
    cout<<"Number of nodes are :"<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(105 , 4);
    
    dcobj->Display();
    cout<<"Number of nodes are :"<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(4);
    
    dcobj->Display();
    cout<<"Number of nodes are :"<<dcobj->Count()<<"\n";

    delete dcobj;   

//////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');
    
    sobj->Display();
    cout<<"Number of elements are :"<<sobj->Count()<<"\n";
    cout<<"\n";

    cout<<"return value of peep is :"<<sobj->peep()<<"\n";
        
    sobj->Display();
    cout<<"Number of elements are :"<<sobj->Count()<<"\n";
    cout<<"\n";

    cout<<"poped element  is :"<<sobj->pop()<<"\n";
            
    sobj->Display();
    cout<<"Number of elements are :"<<sobj->Count()<<"\n";
    cout<<"\n";
   
    cout<<"poped element  is :"<<sobj->pop()<<"\n";
            
    sobj->Display();
    cout<<"Number of elements are :"<<sobj->Count()<<"\n";
    cout<<"\n";

    sobj->push('e');
    
    sobj->Display();
    cout<<"Number of elements are :"<<sobj->Count()<<"\n";
    cout<<"\n";

    delete sobj;

///////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.2345);
    qobj->enqueue(21.34567);
    qobj->enqueue(51.23456);
    qobj->enqueue(101.23456);
    
    qobj->Display();
    cout<<"Number of elements are :"<<qobj->Count()<<"\n";
    cout<<"\n";

    cout<<"Removed element  is :"<<qobj->dequeue()<<"\n";
            
    qobj->Display();
    cout<<"Number of elements are :"<<qobj->Count()<<"\n";
    cout<<"\n";
   
    cout<<"Removed element  is :"<<qobj->dequeue()<<"\n";
            
    qobj->Display();
    cout<<"Number of elements are :"<<qobj->Count()<<"\n";
    cout<<"\n";

    qobj->enqueue(121.3456);
    
    qobj->Display();
    cout<<"Number of elements are :"<<qobj->Count()<<"\n";
    cout<<"\n";

    delete qobj;

    return 0;
}