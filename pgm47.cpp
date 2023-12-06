//47. Write a C++ program to delete an element in the circular Doubly linked list. Menu driven program.
#include<iostream>
using namespace std;
class Node
{
    public:
     int data;
     Node *prev;
     Node *next;
     Node(int value)
        {
            data=value;
            next=nullptr;
            prev=nullptr;
        }
};
class CDLL
{
    private:
      Node *head;
    public:
       CDLL()
        {
            head=nullptr;
        }
       void create(int value)
         {
            Node *newnode=new Node(value);
            if(!head)
             {
                head=newnode;
                head->next=head;
                head->prev=head;
             }
            else 
              {
                 Node *lastnode=head->prev;
                 lastnode->next=newnode;
                 newnode->prev=lastnode;
                 newnode->next=head;
                 head->prev=newnode;
              }
         }
        void display()
          {
            if(!head)
               {
                cout<<"list is empty";
                return;
               }
            Node *current=head;
            cout<<"\n the linked list is: ";
            do
            {
                cout<<current->data<<"->";
                current=current->next;
            }while(current!=head);
            cout<<"nullptr"<<endl;
          }
     void deleteEnd()
       {
        if(!head)
           {
             cout<<"\n list is empty. deletion is not possible";
             return;
           }
        else
          {
            if(head->next==head)
               {
                 Node *temp=head;
                 head=nullptr;
                 delete temp;
               }
            else
            {
            Node *lastnode=head->prev;
            lastnode->prev->next=head;
            head->prev=lastnode->prev;
            delete lastnode;
            }
            display();
          }
       }
    void deleteBeg()
     {
        if(!head)
          {
            cout<<"\n list is empty";
            return;
          }
        if(head->next==head)
           {
            Node *temp=head;
            head=nullptr;
            delete temp;
           }
        else
          {
            Node *lastnode=head->prev;
            head->next->prev=lastnode;
            lastnode->next=head->next;
            Node *temp=head;
            head=head->next;
            delete temp;
          }
        display();
     }
    void deleteSpecific(int p)
      {
         if(!head)
           {
             cout<<"\n list is empty.deletion is not possible";
             return;
           }
         if(p==1)
           {
            if(head->next==head)
              {
               Node *temp=head;
               head=nullptr;
               delete temp;
              }
            else
              {
                Node *lastnode=head->prev;
                head->next->prev=lastnode;
                lastnode->next=head->next;
                Node *temp=head;
                head=head->next;
                 delete temp;
              }
           }
         else
           {
            int currentposition=1;
            Node *current=head;
            while(currentposition<p && current->next!=head)
             {
                currentposition++;
                current=current->next;
             }
            if(current->next==head && currentposition<p)
              {
                cout<<"\n invalid position.position exceed the limit";
                return;
              }
            else
             {
                Node *temp=current;
                current->prev->next=current->next;
                current->next->prev=current->prev;
                if(current->next==head)
                  {
                    head->prev=current->prev;
                  }
                delete temp;
             }
           }
         display();   
      }
};
int main()
{
    CDLL list;
    int n,y,ch,p;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want to continue(enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    list.display();
     do
    {
      cout<<"\n ....menu..."<<endl
          <<"1. delete at beg"<<endl
          <<"2. delete at end"<<endl
          <<"3. delete a specific position"<<endl
          <<"0.exit"<<endl
          <<"enter your choice: ";
      cin>>ch;
      switch(ch)
        {
           case 1: list.deleteBeg();
                   break;
           case 2: list.deleteEnd();
                   break;
          case 3:  cout<<"\n enter the position where you want to delete element: ";
                   cin>>p;
                   if(p>0)
                      list.deleteSpecific(p);
                   else
                      cout<<"\n invalid position";
                   break;
          case 0: cout<<"\n exiting..."<<endl;
                  break;
         default: cout<<"\n invalid choce"<<endl;
        }
    }while(ch!=0);
    return 0;
}