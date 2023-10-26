//35. Write a C++ program to create and insert an element anywhere in the circular list.

#include<iostream>
using namespace std;
class Node
{
  public:
    int data;
    Node *next;
  Node(){}
  Node(int value)
   {
       data=value;
       next=nullptr;
   }
};
class Circularlist
{
  public:
   Node *head;
  Circularlist()
   {
       head=nullptr;
   }
  void create(int value)
    {
        Node *newnode =new Node(value);
       if(head==nullptr)
        {
         head=newnode;
         head->next=head;
        }
       else
        {
            Node *current=head;
            while(current->next!=nullptr)
              current=current->next;
            current->next=newnode;
            newnode->next=head;
        }
    }
void display()
    {
      Node *current=head;
     do
        {
        cout<<current->data<<"->";
        current=current->next;
        } while(current!=head);
      cout<<"nullptr"<<endl;
    }
void insertbeg(int value)
 {
     Node *newnode=new Node(value);
     if(head==nullptr)
      {
          head=newnode;
          newnode->next=newnode;
      }
     else
     {
         Node *temp=head;
         while(temp->next!=head)
          {
              temp=temp->next;
          }
         temp->next=newnode;
         newnode->next=head;
         head=newnode;
     }
     }
    void insertend(int value)
     {
         Node *newnode =new Node(value);
     if(head==nullptr)
      {
          head=newnode;
          newnode->next=newnode;
      }
     else
     {
         Node *temp=head;
         while(temp->next!=head)
          {
              temp=temp->next;
          }
         temp->next=newnode;
         newnode->next=head;
     }
 }
 void insertspecific(int n,int p )
  {   int ch;
      Node *ptr,*loc=head;
      int temp=p-1,k;
      Node *prev=nullptr;
      for(k=0;k<temp;k++)
        {
            prev=loc;
            loc=loc->next;
            if(loc==head)
              {
                 if(k+1==temp)
                  {
                     ptr=new Node(n);
                     prev->next=ptr;
                     ptr->next=head;
                     return;
                  }
               else
                 {
                  cout<<"\n insertion is not possible at the specified position";
                  return;
                 }
              }
        }
    if(loc==head)
      {
          ptr=new Node(n);
          ptr->next=loc;
          head=ptr;
           Node *temp=head;
         while(temp->next!=head)
          {
              temp=temp->next;
          }
         temp->next=ptr;
         return;
      }
    else 
    {
    ptr=new Node(n);
    ptr->next=loc;
    prev->next=ptr;
   return;
    }
  }
 };
 int main()
 {
  Circularlist list;
    int ch,a,item,p;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>a;
        list.create(a);
        cout<<"\n do you want to add one more element(enter 1 to continue): ";
        cin>>ch;
    }while(ch==1);
    cout<<"\n the linked lisyt is: ";
    list.display();
    do
    {
        cout<<"\n....menu..."<<endl
            <<"1.insert at beginning"<<endl
            <<"2.insert at end"<<endl
            <<"3.insert at position"<<endl
            <<"0.exit"<<endl
            <<"enter your choice: ";
        cin>>ch;
        switch(ch)
        {   case 1:cout<<"\n enter the element you want to insert at beginning: ";
                   cin>>a;
                   list.insertbeg(a);
                   cout<<"\n the linked list is: ";
                   list.display();
                   break;
             case 2:cout<<"\n enter the element you want to insert  at end: ";
                   cin>>a;
                   list.insertend(a);
                   cout<<"\n the linked list is :";
                   list.display();
                   break;
            case 3:cout<<"\n enter the element to insert: ";
                   cin>>item;
                   top:cout<<"\n the position you want to insert element: ";
                   cin>>p;
                   if(p<=0)
                     {
                         cout<<"\n invalid position ";
                          goto top;
                     }
                   list.insertspecific(item,p);
                   cout<<"\n the linked list is: ";
                   list.display();
                   break;
         case 0: cout<<"\n exiting...";
                 break;
        default:cout<<"\n invalid cchoice..";
        }
    }while(ch!=0);
 return 0;
}