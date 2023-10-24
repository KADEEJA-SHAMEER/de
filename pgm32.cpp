//32. Write a C++ program to concatenate two linked lists
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
    Linkedlist()
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
  Linkedlist concatinate(Linkedlist list2)
   {
     Linkedlist list4;
     Node *current;
     list4.head=head;
     current=list4.head;
     while(current->next!=nullptr)
       {
        current=current->next;
       }
     current->next=list2.head;
     return list4;
   }
 };
 int main()
 {
    Linkedlist list1,list2,list3;
    int a1,a2,y;
    cout<<"\n creating list 1 ";
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>a1;
        list1.create(a1);
        cout<<"\n do you want to add one more element (enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    cout<<"\n creating list 2 ";
     do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>a2;
        list2.create(a2);
        cout<<"\n do you want to add one more element (enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    cout<<"\n the linked list 1: ";
    list1.display();
    cout<<"\n the linked list 2: ";
    list2.display();
    list3=list1.concatinate(list2);
    cout<<"\n the merged list is: ";
    list3.display();
    return 0;
 }
