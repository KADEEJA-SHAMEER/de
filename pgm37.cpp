//37. Write a C++ program to Implementation of circular list.
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
             {
              current=current->next;
             }
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
  void deleteAtSpecific(int position)
      {
          if(head==nullptr)
            {
              cout<<"\n the circular linked list is empty.nothing to delete";
              return;
            }
             Node *current=head;
             Node *prev=nullptr;
             int currentposition=1;
             while(currentposition<position && current->next!=head)
               {
                   prev=current;
                   current=current->next;
                   currentposition++;
               }
              if(currentposition==position)
                {
                  if(current==head&&prev==nullptr)
                    {
                        head=nullptr;
                        cout<<current->data<< " deleted"<<endl;
                        delete current;
                        cout<<" list is empty"<<endl;
                        return;
                    }
                  else if(prev==nullptr)
                    {
                      Node *lastnode=head;
                      while(lastnode->next!=head)
                        lastnode=lastnode->next;
                      head=current->next;
                      lastnode->next=head;
                    }
                   else
                    prev->next=current->next;
                  cout<<current->data<< " deleted"<<endl;
                 delete current;
                 display();
                }
             else
              {
                  cout<<"\n invalid position.nothing to delete"<<endl;
                  return;
              }
        }  
    void insertspecific(int n,int p )
  { 
      int ch;
       Node *ptr,*loc=head;
      int temp=p-1,k;
      Node *prev=nullptr;
      if(head==nullptr && p>1)
                {
                    cout<<"\n invalid position";
                    return;
                }
      for(k=0;k<temp;k++)
        {   
            prev=loc;
            loc=loc->next;
            if(loc==head)
              {
                 if(k+1==temp)
                  {
                     ptr=new Node(n);
                     prev->next=ptr;
                     ptr->next=head;
                    cout<<"\n the linked list : ";
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
          if(head==nullptr)
            {
                create(n);
                cout<<"\n the linked list is: ";
                display();
                return;
            }
          else
          {
          ptr=new Node(n);
          ptr->next=loc;
           Node *temp=head;
         while(temp->next!=head)
          {
              temp=temp->next;
          }
         temp->next=ptr;
          head=ptr;
        cout<<"\n the linked list : ";
                    display();
                    return;
          }
      }
    else 
    {
    ptr=new Node(n);
    ptr->next=loc;
    prev->next=ptr;
    cout<<"\n the linked list : ";
     display();
    return;
    }
  }
};
int main()
{
    Circularlist list;
    int ch,a,item,p;
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
        cout<<"\n...menu..."<<endl
           <<"1.insert a node"<<endl
           <<"2.delete a node"<<endl
           <<"0.exit"<<endl
           <<"enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n enter the element you want to insert:   ";
                  cin>>item;
                  cout<<"\n enter the position you want to insert: ";
                  cin>>p;
                  list.insertspecific(item,p);
                  break;
            case 2:cout<<"\n enter the position you want to delete:    ";
                  cin>>p;
                  list.deleteAtSpecific(p);
                  break;
            case 0:cout<<"\n exiting...";
                   break;
          default:cout<<"\n invalid choice";
        }
    }while(ch!=0);
return 0;
}