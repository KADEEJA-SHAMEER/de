//39. Write a C++ program to insert an element in the Doubly linked list.
// Menu driven program. (at beginning, end, anywhere).
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
  void insertatP(int value, int position)
   {
     Node* newNode = new Node(value);
     if (position == 1) 
       {
         if (!head)
           {
            head = tail = newNode;
           }
         else 
          {
           newNode->next = head;
           head->prev = newNode;
           head = newNode;
          }
       }
     else
      {
        int currentPosition = 1;
       Node* current = head;
       while (current != nullptr && currentPosition < position - 1)
         {
          current = current->next;
          currentPosition++;
         }
      if (current == nullptr) 
        {
          cout << "Position exceeds the length of the list." << endl;
         return;
        }
    else
    {
     newNode->next = current->next;
     if (current->next != nullptr) 
     {
       current->next->prev = newNode;
     }
    current->next = newNode;
    newNode->prev = current;
  }
 }
  cout<<"\n the doubly linked list is : ";
    display();
 }
void insertAtBeg(int value)
      {
          Node *newnode=new Node(value);
          if(!head)
            {
                head=tail=newnode;
            }
          else
            {
              newnode->next=head;
              head->prev=newnode;
              head=newnode;
            }
         cout<<"\n the linked list is : ";
         display();
      }
};
int main()
{
  DLL list;
  int n,y=0,ch,p;
  do
  {
      cout<<"\n enter the element you want to insert: ";
      cin>>n;
      list.insertelement(n);
      cout<<"\n do you want to add one more element(enter 1 to continue): ";
      cin>>y;
  }while(y==1);
  cout<<"\n the doubly linked list is: ";
  list.display();
  do
  {
     cout<<"\n...menu.."<<endl
         <<"1. insert at beginning"<<endl
         <<"2. insert at end"<<endl
         <<"3.insert at position"<<endl
         <<"0.exit"<<endl
         <<"enter your choice: ";
     cin>>ch;
    switch(ch)
      {
           case 1:cout<<"\n enter the element to insert: ";
                  cin>>n;
                  list.insertAtBeg(n);
                  break;
           case 2:cout<<"\n enter the element to insert: ";
                  cin>>n;
                  list.insertelement(n);
                  cout<<"\n the list is: ";
                  list.display();
                  break;
          case 3:cout<<"\n enter the position to insert: ";
                 cin>>p;
                 if(p>0)
                   {
                       cout<<"\n enter the element to insert: ";
                       cin>>n;
                       list.insertatP(n,p);
                   }
                 else
                   cout<<"\n invalid postion"<<endl;
                 break;
         case 0:cout<<"\n exiting....";
                 break;
         default:cout<<"\n invalid choice";
      }
  }while(ch!=0);
  return 0;
}