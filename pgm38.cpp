//38. Write a C++ program to create and count number of nodes in the Doubly linked list.
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
int countNodes()
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
 void display()
  {
      Node *current=head;
      while(current!=nullptr)
       {
           cout<<current->data<<"->";
           current=current->next;
       }
      cout<<"End"<<endl;
  }
};
int main()
{
  DLL list;
  int a,y=0;
  do
  {
      cout<<"\n enter the element you want to insert: ";
      cin>>a;
      list.insertelement(a);
      cout<<"\n do you want ton add one more element(enter 1 to continue): ";
      cin>>y;
  }while(y==1);
  cout<<"\n the doubly linked list is: ";
  list.display();
  int nodecount=list.countNodes();
  cout<<"\n number of  nodes created : "<<nodecount<<endl;
  return 0;
}