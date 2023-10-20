/*30. Write a program to implement singly linked list. Menu driven program.*/
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
      if(current==nullptr)
        {
         cout<<"\n empty list!! "<<endl;
         return;
        }
    else
    { cout<<"\n the linked list is:";
      while(current!=nullptr)
        {
        cout<<current->data<<"->";
        current=current->next;
        }
      cout<<"nullptr"<<endl;
    }
    }
 void Delete(int item)
  {
      Node *ptr,*loc,*temp;
      ptr=head;
      loc=nullptr;
      if(ptr==nullptr)
        {
          cout<<"\n list is empty"<<endl;
          exit(0);
        }
     else
      {
          while(ptr!=nullptr)
          {
          if(ptr->data==item)
            {
             loc=ptr;
             break;
            }
           else
            ptr=ptr->next;
          }
       if(loc==nullptr)
          cout<<"\n item not found ";
       else
          {
           
           temp=head;
           if(temp==loc)
             {
                 head=head->next;
                 delete loc;
                 cout<<"\n node with element "<<item<<" deleted ";
                 display();
             }
          else
          {
           while(temp->next!=loc)
               {
                   temp=temp->next;
               }
            temp->next=loc->next;
            delete loc;
            cout<<"\n node with element "<<item<<" deleted ";
            display();
          }
          }
      }
  }
       
  void insertspecific(int n,int p )
  {   int ch;
      Node *ptr,*loc=head;
      int temp=p-1,k;
      Node *prev=head;
      for(k=0;k<temp;k++)
        {
            prev=loc;
            loc=loc->next;
            if(loc==nullptr)
              {
                 if(k+1==temp)
                  {
                     ptr=new Node(n);
                     prev->next=ptr;
                     display();
                     return;
                  }
               else
                 {
                  cout<<"\n insertion is not possible at the specified position";
                  return;
                 }
              }
        }
    if(loc==head)
      {
          ptr=new Node(n);
          ptr->next=loc;
          head=ptr;
          display();
      }
    else 
    {
    ptr=new Node(n);
    ptr->next=loc;
    prev->next=ptr;
    display();
    }
  }
};
int main()
{
    Linkedlist list;
    int ch,a,item,p;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>a;
        list.create(a);
        cout<<"\n do you want to add one more element(enter 1 to continue): ";
        cin>>ch;
    }while(ch==1);
    list.display();
    do
    {
        cout<<"\n....menu..."<<endl
            <<"1.insert an element"<<endl
            <<"2.delete an element"<<endl
            <<"0.exit"<<endl
            <<"enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n enter the element to insert: ";
                   cin>>item;
                   top:cout<<"\n the position you want to insert element: ";
                   cin>>p;
                   if(p==0)
                     {
                         cout<<"\n invalid entry position should be greater than 0";
                          goto top;
                     }
                   list.insertspecific(item,p);
                   break;
           case 2:cout<<"\n enter the element you want to delete: "    ;
                  cin>>item;
                  list.Delete(item);
                  break;
         case 0: cout<<"\n exiting...";
                 break;
        default:cout<<"\n invalid cchoice..";
        }
    }while(ch!=0);
 return 0;
}