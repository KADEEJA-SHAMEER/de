//45. Write a C++ program to create circular doubly linked list.
#include<iostream>
using namespace std;
class Node
{
    public:
     int data;
     Node *prev;
     Node *next;
     Node(int value)
        {
            data=value;
            next=nullptr;
            prev=nullptr;
        }
};
class CDLL
{
    private:
      Node *head;
    public:
       CDLL()
        {
            head=nullptr;
        }
       void create(int value)
         {
            Node *newnode=new Node(value);
            if(!head)
             {
                head=newnode;
                head->next=head;
                head->prev=head;
             }
            else 
              {
                 Node *lastnode=head->prev;
                 lastnode->next=newnode;
                 newnode->prev=lastnode;
                 newnode->next=head;
                 head->prev=newnode;
              }
         }
        void display()
          {
            if(!head)
               {
                cout<<"list is empty";
                return;
               }
            Node *current=head;
            do
            {
                cout<<current->data<<"->";
                current=current->next;
            }while(current!=head);
            cout<<"nullptr"<<endl;
          }
};
int main()
{
    CDLL list;
    int n,y;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want to continue(enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    cout<<"\n the circularly doubly linked list is: ";
    list.display();
    return 0;
}