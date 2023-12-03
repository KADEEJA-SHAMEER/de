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
     if(head==nullptr)
        {
            cout<<"\n list is empty";
            return;
        }
     else
     {
      Node *current=head;
     do
        {
        cout<<current->data<<"->";
        current=current->next;
        } while(current!=head);
      cout<<"nullptr"<<endl;
    }
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
                  
                   if(prev==nullptr)
                    {
                      Node *lastnode=head;
                      while(lastnode->next!=head)
                        lastnode=lastnode->next;
                     if(current->next!=head)
                     {
                      head=current->next;
                      lastnode->next=head;
                     }
                    else
                      head=nullptr;
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
    int countNodes()
 {
     int countnode=1;
     if(head==nullptr)
       {
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
            if(head==nullptr)
             {
                head=ptr;
                head->next=head; 
             }
            else
            {
            ptr->next=head;
            Node *temp=head;
            while(temp->next!=head)
           {
              temp=temp->next;
           }
          temp->next=ptr;
           head=ptr;
         }
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
    int countN;
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
            case 1:countN=list.countNodes();
                   cout<<"\n enter the element you want to insert:   ";
                  cin>>item;
                  cout<<"\n enter the position you want to insert: ";
                  cin>>p;
                  list.insertspecific(item,p,countN);
                  break;
            case 2:countN=list.countNodes();
                   if(countN==0)
                     cout<<"\n nothing to delete.list is empty";
                   else
                   {
                   cout<<"\n enter the position you want to delete:    ";
                   cin>>p;
                   list.deleteAtSpecific(p);
                   }
                  break;
            case 0:cout<<"\n exiting...";
                   break;
          default:cout<<"\n invalid choice";
        }
    }while(ch!=0);
return 0;
}