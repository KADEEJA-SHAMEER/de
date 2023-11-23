//35. Write a C++ program to create and insert an element anywhere in the circular list.

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
class Circularlist
{
  
  public:
   Node *head;
  Circularlist()
   {
       head=nullptr;
   }
  void create(int value)
    {
        Node *newnode =new Node(value);
       if(head==nullptr)
        {
         head=newnode;
         head->next=head;
        }
       else
        {
            Node *current=head;
            while(current->next!=head)
              current=current->next;
            current->next=newnode;
            newnode->next=head;
        }
    }
void display()
    {
      Node *current=head;
     do
        {
        cout<<current->data<<"->";
        current=current->next;
        } while(current!=head);
      cout<<"nullptr"<<endl;
    }
int countNodes()
 {
     int countnode=1;
     if(head==nullptr)
       {
           cout<<"\n list is empty";
           return 0;
       }
      else
      {
          Node * current=head;
          while(current->next!=head)
            {
                countnode+=1;
                  current=current->next;
            }
      }
     return countnode;
 }
void insertbeg(int value)
 {
     Node *newnode=new Node(value);
     if(head==nullptr)
      {
          head=newnode;
          newnode->next=newnode;
      }
     else
     {
         Node *temp=head;
         while(temp->next!=head)
          {
              temp=temp->next;
          }
         temp->next=newnode;
         newnode->next=head;
         head=newnode;
     }
     }
    void insertend(int value)
     {
         Node *newnode =new Node(value);
     if(head==nullptr)
      {
          head=newnode;
          newnode->next=newnode;
      }
     else
     {
         Node *temp=head;
         while(temp->next!=head)
          {
              temp=temp->next;
          }
         temp->next=newnode;
         newnode->next=head;
     }
 }
 void insertspecific(int n,int p,int countnode )
  {  
      Node *ptr;
      if(((p!=countnode)&&(p>countnode+1)) ||( p<=0)) 
        {
            cout<<"\n invalid position";
            return;
        }
      else
      {
        if(p==1)
         {
            ptr=new Node(n);
            ptr->next=head;
            Node *temp=head;
            while(temp->next!=head)
           {
              temp=temp->next;
           }
          temp->next=ptr;
           head=ptr;
        }
       else if(p==countnode+1)
           {
               ptr=new Node(n);
               Node *temp=head;
               while(temp->next!=head)
                 temp=temp->next;
               ptr->next=head;
               temp->next=ptr;
           }
          else 
            {
             
              Node *temp=head;
              int currp=1;
              while((currp< p-1)&&(temp->next!=head))
                {
                    currp++;
                    temp=temp->next;
                }
              ptr=new Node(n);
              ptr->next=temp->next;
              temp->next=ptr;
            }
          cout<<"\n the linked list is: ";
          display();
      }
  }
 };
 int main()
 {
  Circularlist list;
    int ch,a,item,p,c;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>a;
        list.create(a);
        cout<<"\n do you want to add one more element(enter 1 to continue): ";
        cin>>ch;
    }while(ch==1);
    cout<<"\n the linked lisyt is: ";
    list.display();
    do
    {
        cout<<"\n....menu..."<<endl
            <<"1.insert at beginning"<<endl
            <<"2.insert at end"<<endl
            <<"3.insert at position"<<endl
            <<"0.exit"<<endl
            <<"enter your choice: ";
        cin>>ch;
        switch(ch)
        {   case 1:cout<<"\n enter the element you want to insert at beginning: ";
                   cin>>a;
                   list.insertbeg(a);
                   cout<<"\n the linked list is: ";
                   list.display();
                   break;
             case 2:cout<<"\n enter the element you want to insert  at end: ";
                   cin>>a;
                   list.insertend(a);
                   cout<<"\n the linked list is :";
                   list.display();
                   break;
            case 3: c=list.countNodes();
                   cout<<"\n enter the element to insert: ";
                   cin>>item;
                   cout<<"\n the position you want to insert element: ";
                   cin>>p;
                   list.insertspecific(item,p,c);
                  
                   break;
         case 0: cout<<"\n exiting...";
                 break;
        default:cout<<"\n invalid cchoice..";
        }
    }while(ch!=0);
 return 0;
}