//31. Write a program to arrange the list based on the ascending or descending order of the information field (linked list, dynamic memory allocation techniques).
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
 void Swap(int &x,int &y)
  {
      int temp;
      temp=x;
      x=y;
      y=temp;
  }
 void Ascending()
    {
      Node *temp1=head,*temp2;
     
      while(temp1!=nullptr)
      {
        temp2=temp1->next;
       while(temp2!=nullptr)
       {
         if(temp1->data > temp2->data)
           {
               Swap(temp1->data,temp2->data);
           }
         temp2=temp2->next;
       }
      temp1=temp1->next;
      }
      
    }
   void Descending()
     {
        Node *temp1=head,*temp2;
     
       while(temp1!=nullptr)
       {
        temp2=temp1->next;
        while(temp2!=nullptr)
        {
         if(temp1->data<temp2->data)
           {
              Swap(temp1->data,temp2->data);
           }
         temp2=temp2->next;
       }
      temp1=temp1->next;
      }
    }
 };
 int main()
 {
  Linkedlist list;
  int n,ch,y;
  do
  {
    cout<<"\n enter the element you want to insert: ";
    cin>>n;
    list.create(n);
    cout<<"\n do you want to add one more element(enter 1 to continue) : ";
    cin>>y;
  }while(y==1);
  cout<<"\n the linked list is: ";
  list.display();
  do
  {
    cout<<"...menu..."<<endl
        <<"1.ascending order"<<endl
        <<"2.descending order"<<endl
        <<"0.exit"<<endl
        <<"enter your choice: ";
     cin>>ch;
     switch(ch)
     {
       case 1:list.Ascending();
               cout<<"\n the sorted list in ascending order is: ";
               list.display();
               break;
       case 2: list.Descending();
               cout<<"the sorted list in descending order is: ";
               list.display();
               break;
       case 0:cout<<"\n exiting...";
              break;
      default:cout<<"\n oinvalid choice";
     }
  }while(ch!=0);
return 0;
 }