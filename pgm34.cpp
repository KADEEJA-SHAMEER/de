//34. Write a C++ program to interchange n and n+1th nodes in a list.
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
        ++count;
        current=current->next;
      }
}
void interchange()
 {
    int n;
    top:cout<<"\n enter the position of the node : ";
     cin>>n;
     if(n<1||n>count)
       {
         cout<<"\n invalid position ";
         goto top;
       }
    Node *prevn=nullptr,*currn=head;
    for(int i=0;i<n-1;i++)
    {
      prevn=currn;
      currn=currn->next;
    }
   if(currn->next==nullptr)
   {
       cout<<"\n last node, interchanging is not possible";
       exit(0);
   }
   else
   {
   Node *currm=currn->next;
   if(prevn==nullptr)
     head=currm;
  else
   prevn->next=currm;
   currn->next=currm->next;
   currm->next=currn;
   cout<<"\n after interchanging the linked list is: ";
   display();
  }
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