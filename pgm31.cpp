//31. Write a program to arrange the list based on the ascending or descending order of the information field (linked list, dynamic memory allocation techniques).
#include<iostream>
using namespace std;
class Node
{
    public:
     int data;
     Node next;
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
    linkedlist()
    {
      head=nullptr;
    }
    void create(int value)
     {
        Node *newnode=new Node(value);
        if(head==nullptr)
         {
          head=newnode;
         }
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
 }
 void Ascending()
    {
      Node *temp;
      
    }