#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **  PPNODE;

class DoublyLL
{
    public: 
        PNODE first;
        int iCount;

        DoublyLL()
        {

            cout<<"Object of SinglylL gets created\n";
            first = NULL;
            iCount=0;

        }
        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;
                first = newn;
            }

            iCount++;

        }
        void InsertLast(int no)
        { 
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;

            }

            iCount++;

        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first->next;
                first == NULL;
            }
            else
            {
                temp = first;
                first = first->next;
                first->prev = NULL;
                delete temp;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first->next;
                first == NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }

            iCount--;
        }

        void Display()
        {
            cout<<"| NULL |<=>";
            while(first != NULL)
            {
                cout<<"|"<<first->data<<"| <=> ";
                first = first->next;
            }
            cout<<"| NULL |\n";
        }
        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no ,int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            
            int iCnt = 0;
            int iSize = 0;
            iSize = Count();

            if(pos < 1 || pos > iSize+1)
            {
                cout<<"Invalid position...";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iSize + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                newn->next->prev = newn;
                newn->prev = temp;
                temp->next = newn;
            }

            iCount++;
        }

        void DeleteAtPos(int pos)
        { 
            PNODE temp = NULL;
            
            int iCnt = 0;
            int iSize = 0;
            iSize = Count();

            if(pos < 1 || pos > iSize)
            {
                cout<<"Invalid position...";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iSize )
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                temp->next = temp->next->next;
                delete temp->next->prev;
                temp->next->prev = temp;
                
            }

            iCount--;  
        }
};

int main()
{

    DoublyLL obj;
    int iRet=0;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.InsertAtPos(404 , 3);

    obj.DeleteAtPos(6);

    obj.Display();
    iRet=obj.Count();
    cout<<"number of nodes are :"<<iRet<<"\n";

    return 0;

}