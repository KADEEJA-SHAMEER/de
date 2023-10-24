//33. Write a C++ program to interchange any two nodes in a list.
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
class Linkedlist
{
  public:
   Node *head;
   int count;
  Linkedlist()
   {
       head=nullptr;
   }
  void create(int value)
    {
        Node *newnode =new Node(value);
       if(head==nullptr)
         head=newnode;
       else
        {
            Node *current=head;
            while(current->next!=nullptr)
              current=current->next;
            current->next=newnode;
        }
    }
void display()
    {
      Node *current=head;
      while(current!=nullptr)
        {
        cout<<current->data<<"->";
        current=current->next;
        }
      cout<<"nullptr"<<endl;
    }
void countnodes()
{
     count=0;
    Node *current=head;
    while(current!=nullptr)
      {
        count++;
        current=current->next;
      }
}
Node *search(int x)
 {
    Node *loc=head,*prev=nullptr;
    for(int i=0;i<x-1;i++)
      {
        prev=loc;
         loc=loc->next;
      }
    return prev;
 }
  void interchange()
  {
     int n,m;
    if(count==1)
    {
     cout<<"\n interchanging is not possible .only one element in list";
     exit(0);
    }
     top: cout<<"\n enter the position of nodes you want to interchange: ";
     cin>>n>>m;
     if((n<=0||n>count) || (m<=0||m>count))
       {
         cout<<"\n invalid positions";
         goto top;
       }
     else if(n==m)
     {
           cout<<"\n same positions cannot interchange";
            exit(0);
      }
     Node *prevn,*currn;
    if(n==1)
      {
        prevn=nullptr;
        currn=head;
      }
    else
    {
     prevn=search(n);
    currn=prevn->next;
    }
     Node *prevm,*currm;
    if(m==1)
        {
            prevm=nullptr;
            currm=head;
        }
    else
    {
    prevm=search(m);
    currm=prevm->next;
    }
   if(prevn==nullptr)
     {  Node *temp;
        head=currm;
        prevm->next=currn;
        temp=currn->next;
        currn->next=currm->next;
        currm->next=temp;
     }
    else if(prevm==nullptr)
           {
            Node *temp;
            head=currn;
            prevn->next=currm;
            temp=currm->next;
            currm->next=currn->next;
            currn->next=temp;
           }
         else
          {   Node *temp;
              prevn->next=currm;
              temp=currm->next;
              currm->next=currn->next;
              prevm->next=currn;
              currn->next=temp;
          }
     cout<<"\n after interchanging list is: ";
     display();
  }
};
int main()
{
 Linkedlist list;
    int n,y;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want to add one more element(enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    cout<<"\n the linked list is: ";
    list.display();
    list.countnodes();
    list.interchange();
     return 0;
}