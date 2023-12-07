//48. Write a C++ program to Implementation of circular doubly linked list.
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
       void deleteSpecific()
        {
         int p;
         if(!head)
           {
             cout<<"\n list is empty.deletion is not possible";
             return;
           }
         cout<<"\n enter the position where you want to delete element: ";
         cin>>p;
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
                  if(head==nullptr)
                    {
                        head=newnode;
                        head->next=head->prev=head;
                    }
                 else
                 {
                  Node *lastNode=head->prev;
                  newnode->prev=lastNode;
                  head->prev=newnode;
                  newnode->next=head;
                  lastNode->next=newnode;
                  head=newnode;
                 }
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
                display();
          }
        int countNode()
        {
          if(head==nullptr)
             {
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
};
int main()
{
 CDLL list;
    int n,y,ch,p,c;
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
          <<"1. insert an element"<<endl
          <<"2. delete an element"<<endl
          <<"0.exit"<<endl
          <<"enter your choice: ";
      cin>>ch;
      switch(ch)
        {
           case 1: cout<<"\n enter the element you want to insert: ";
                   cin>>n;
                   cout<<"\n enter the position where you want to insert element : ";
                   cin>>p;
                   c=list.countNode();
                   list.inserAtSpecific(n,p,c);
                   break;
           case 2: list.deleteSpecific();
                   break;
           case 0: cout<<"\n exiting..."<<endl;
                  break;
         default: cout<<"\n invalid choce"<<endl;
        }
    }while(ch!=0);
    return 0;
}