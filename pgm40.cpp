//40. Write a C++ program to delete an element in the Doubly linked list. Menu driven program. (at beginning, end, anywhere).
#include<iostream>
using namespace std;
class Node
{
    public:
      int data;
      Node *prev;
      Node *next;
      Node (){}
      Node(int value)
       {
            data=value;
            prev=nullptr;
            next=nullptr;
       }
};
class DLL
{
    private:
     Node *head;
     Node *tail;
    public:
     DLL()
      {
          head=nullptr;
          tail=nullptr;
      }
    void insertelement(int value)
     {
         Node *newnode =new Node(value);
         if(!head)
           {
               head=tail=newnode;
           }
          else
           {
               tail->next=newnode;
               newnode->prev=tail;
               tail=newnode;
           }
     }

 void display()
  {  
     if(head==nullptr)
        {
            cout<<"list is empty";
            return;
        }
      Node *current=head;
      while(current!=nullptr)
       {
           cout<<current->data<<"->";
           current=current->next;
       }
      cout<<"End"<<endl;
  }
void deleteAtBeg()
 {
    if(!head)
      {
        cout<<"\n list is empty";
        return;
      }
    Node *toDelete=head;
    head=head->next;
    if(head)
      head->prev=nullptr;
    else
      tail=nullptr;
    delete toDelete;
    display();
 }
void deleteAtEnd()
{
    if(!tail)
      {
        cout<<"\n list is empty";
        return;
      }
    Node *todelete=tail;
    tail=tail->prev;
    if(tail)
      tail->next=nullptr;
    else
      head=nullptr;
    delete todelete;
    display();
}
void delete_position(int position)
 {
    if(!head)
      {
        cout<<"\n list is empty";
        return;
      }
    if(position==1)
      {
        Node *todelete=head;
        head=head->next;
        if(head)
          head->prev=nullptr;
        else
          tail=nullptr;
        delete todelete;
        display();
      }
    else
     {
        int currentposition=1;
        Node *current=head;
        while(current!=nullptr && currentposition<position)
            {
                current=current->next;
                currentposition++;
            }
        if(current==nullptr)
          {
            cout<<"\n position exceeds the length of the list"<<endl;
            return;
          }
        Node *todelete=current;
        current->prev->next=current->next;
        if(current->next)
          current->next->prev=current->prev;
        else
          tail=current->prev;
        delete todelete;
        display();
     }
 }
};
int main()
{
  DLL list;
  int n,y=0,ch,p;
  do
  {
      cout<<"\n enter the element you want to insert: ";
      cin>>n;
      list.insertelement(n);
      cout<<"\n do you want to add one more element(enter 1 to continue): ";
      cin>>y;
  }while(y==1);
  cout<<"\n the doubly linked list is: ";
  list.display();
  do
  {
     cout<<"\n...menu.."<<endl
         <<"1. delete at beginning"<<endl
         <<"2. delete at end"<<endl
         <<"3.delete at position"<<endl
         <<"0.exit"<<endl
         <<"enter your choice: ";
     cin>>ch;
    switch(ch)
      {
           case 1:
                  list.deleteAtBeg();
                 
                  break;
           case 2:
                  list.deleteAtEnd();
                 
                  break;
          case 3:cout<<"\n enter the position to delete: ";
                 cin>>p;
                 if(p>0)
                   {
                     list.delete_position(p);
                   
                   }
                 else
                   cout<<"\n invalid postion"<<endl;
                 break;
         case 0:cout<<"\n exiting....";
                 break;
         default:cout<<"\n invalid choice";
      }
  }while(ch!=0);
  return 0;
}
