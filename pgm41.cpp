//41. Write a C++ program to Implementation of stack using of linked list. Menu driven program.
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
class Stack
{
    public:
     Node *top,*head;
    Stack()
     {
         top=nullptr;
         head=nullptr;
     }
    void insert(int value)
     {
         Node *newnode =new Node(value);
         if(head==nullptr)
            {
                top=newnode;
                head=top;
            }
          else
            {
                top->next=newnode;
                newnode->next=nullptr;
                top=newnode;
            }
     }
  void Delete()
    {
        if(head==nullptr)
          {
              cout<<"\n stack is empty";
              return;
          }
         else
          {
             Node *current=head;
             Node *temp;
             if(head->next==nullptr)
              {
                  temp=head;
                  head=nullptr;
                  cout<<"\n"<<temp->data<<" deleted from stack";
                  delete temp;
                  cout<<"\n the stack is empty";
                  return;
              }
             else
             {
             while(current->next!=top)
             {
                 current=current->next;
             }
             current->next=nullptr;
             temp=top;
             top=current;
             cout<<"\n"<<temp->data<<" deleted from stack";
             delete temp;
             cout<<"\n the stack  after deletion is: ";
             display();
             }
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
};
int main()
{
    Stack list;
    int n,y,ch;
    do
    {
    cout<<"\n enter the element you want insert into stack: ";
    cin>>n;
    list.insert(n);
    cout<<"\n do you want to add one more element into stack(enter 1 to continue): ";
    cin>>y;
    }while(y==1);
    cout<<"\n the stack is : ";
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
                   cout<<"\n the stack after insertion is: ";
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