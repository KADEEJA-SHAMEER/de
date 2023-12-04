//42. Write a C++ program to Implementation of queue using linked list. Menu driven program.
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
class Queue
{
    public:
     Node *front,*rear;
    Queue()
     {
         front=nullptr;
         rear=nullptr;
     }
    void insert(int value)
     {
         Node *newnode =new Node(value);
         if(front==nullptr)
            {
                front=newnode;
                rear=newnode;
            }
          else
            {
                rear->next=newnode;
                newnode->next=nullptr;
                rear=newnode;
            }
     }
  void Delete()
    {
        if(front==nullptr)
          {
              cout<<"\n queue is empty";
              return;
          }
         else
          {
              Node *temp;
              temp=front;
              front=front ->next;
             cout<<"\n"<<temp->data<< "deleted from queue";
              delete temp;
              if(front==nullptr)
              {
                  cout<<"\n the queue is empty ";
                  return;
              }
              else
              {
                 cout<<"\n the queue after deletion is: ";
                 display();
              }
          }
    }
void display()
 {
    Node *current=front;
    while(current!=nullptr)
     {
         cout<<current->data<<"->";
         current=current->next;
     }
     cout<<"nullptr"<<endl;
 }
};
int main()
{
    Queue list;
    int n,y,ch;
    do
    {
    cout<<"\n enter the element you want insert into queue: ";
    cin>>n;
    list.insert(n);
    cout<<"\n do you want to add one more element int queue(enter 1 to continue): ";
    cin>>y;
    }while(y==1);
    cout<<"\n the queue is : ";
    list.display();
    do
    {
        cout<<"\n ...menu..."<<endl
            <<"1.insert element"<<endl
            <<"2.delete element"<<endl
            <<"0.exit"<<endl
            <<"enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n enter the element you want to insert:    ";
                   cin>>n;
                   list.insert(n);
                   cout<<"\n the queue after insertion is: ";
                   list.display();
                   break;
            case 2:list.Delete();
                   break;
            case 0:cout<<"\n exiting...";
                   break;
          default:cout<<"\n invalid choice ";
        }
    }while(ch!=0);
return 0;
}