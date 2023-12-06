//46. Write a C++ program to insert an element in the circular doubly linked list. Menu driven
//program. (at beginning, end, anywhere).

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
            do
            {
                cout<<current->data<<"->";
                current=current->next;
            }while(current!=head);
            cout<<"nullptr"<<endl;
          }
        void insertAtBeg(int value)
          {
            Node *newnode=new Node(value);
            if(!head)
              {
                head=newnode;
                head->next=head->prev=newnode;
              } 
            else
              {
                Node *lastnode=head->prev;
                newnode->next=head;
                newnode->prev=lastnode;
                lastnode->next=head->prev=newnode;
                head=newnode;
              }
          }
      int countNode()
        {
          if(head==nullptr)
             {
              cout<<"\n list is empty";
              return 0;
             }
          else
            {
              Node *current=head;
              int countN=1;
               while(current->next!=head)
                  {
                    countN++;
                    current=current->next;
                  }
              return countN;
            }
        }
       void inserAtSpecific(int n,int p,int countN)
          {
             if(((p!=countN)&&(p>countN+1))||(p<=0))
                {
                  cout<<"\n invalid position"<<endl;
                  return;
                }
              
              if(p==1)
                 {
                  Node *newnode=new Node(n);
                  Node *lastNode=head->prev;
                  newnode->prev=lastNode;
                  head->prev=newnode;
                  newnode->next=head;
                  lastNode->next=newnode;
                  head=newnode;
                 }
              else if(p==countN+1)
                     {
                      Node *newnode=new Node(n);
                      newnode->next=head;
                      Node *lastNode=head->prev;
                      lastNode->next=newnode;
                      newnode->prev=lastNode;
                      head->prev=newnode;
                     }
                   else
                    {
                       int currentposition=1;
                       Node *current=head;
                       while(currentposition<p-1 && current->next!=head)
                             {
                              current=current->next;
                              currentposition++;
                             }
                       Node *newnode = new Node(n);
                       newnode->next=current->next;
                       current->next=newnode;
                       newnode->prev=current;
                    }
                cout<<"\n the list after insertion: ";
                display();
          }
};
int main()
{
    CDLL list;
    int n,y,ch,c,p;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want to continue(enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    cout<<"\n the circularly doubly linked list is: ";
    list.display();
    do
    {
      cout<<"\n ....menu..."<<endl
          <<"1. insert at beg"<<endl
          <<"2. insert at end"<<endl
          <<"3. insert at specific position"<<endl
          <<"0.exit"<<endl
          <<"enter your choice: ";
      cin>>ch;
      switch(ch)
        {
           case 1: cout<<"\n enter the element to insert: ";
                   cin>>n;
                   list.insertAtBeg(n);
                   cout<<"\n list after insertion: ";
                   list.display();
                   break;
           case 2: cout<<"\n enter the element to insert: ";
                   cin>>n;
                   list.create(n);
                   cout<<"\n list after insertion: ";
                   list.display();
                   break;
          case 3:  c=list.countNode();
                   cout<<"\n enter the position where you want to insert element: ";
                   cin>>p;
                   if(p>0)
                    {
                      cout<<"\n enter the element you want to insert: ";
                      cin>>n;
                      list.inserAtSpecific(n,p,c);
                    }
                   else
                    {
                      cout<<"\n invalid position";
                    }
                   break;
          case 0: cout<<"\n exiting..."<<endl;
                  break;
         default: cout<<"\n invalid choce"<<endl;
        }
    }while(ch!=0);
    return 0;
}