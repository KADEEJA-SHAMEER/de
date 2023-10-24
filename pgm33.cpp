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
   }
};
class Linkedlist
{
  public:
   Node *head;
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
int countnodes()
{
    int count=0;
    Node *current=head;
    while(current!=nullptr)
      {
        count++;
        current=current->next;
      }
    return count;
}
Node search(int x,int count)
 {
    Node *loc=head,*prev=nullptr;
    for(int i=0;i<x-1;i++)
      {
        prev=loc;
         loc=loc->next;
      }
    return prev;
 }
  void interchange(int count)
  {
     int n,m;
     top: cout<<"\n enter the position of nodes you want to interchange: ";
     cin>>n>>m;
     if(n<0||n>count && m<0||m>count)
       {
         cout<<"\n invalid positions";
         goto top;
       }
     else
      {
        if(n==m)
           cout<<"\n same positions cannot interchange";
      }
    Node *prevn,current_exception
    prevn=search(n);
    currn=prev->next;
    
  }
};