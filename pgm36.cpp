//36. Write a C++ program to delete an element in the circular list. Menu driven program. (at beginning, end, anywhere).
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
      cout<<endl;
      Node *current=head;
     do
        {
        cout<<current->data<<"->";
        current=current->next;
        } while(current!=head);
      cout<<"nullptr"<<endl;
    }
 void deletebeg()
   {
    if(head==nullptr)
      {
         cout<<"\n the linked list is empty.nothing to delete"<<endl;
         return;
      }
     else
      {
          Node *temp=head;
          Node *lastnode =head;
          while(lastnode->next!=head)
            {
                lastnode=lastnode->next;
            }
         if(head==lastnode)
           {      cout<<temp->data<<" deleted ";
               delete temp;
               head=nullptr;
               cout<<"\n list is empty";
               return;
           }
          head=head->next;
          lastnode->next=head;
          cout<<temp->data<<" deleted ";
          delete temp;
          display();
      }
   }
  void deleteEnd()
    {
        if(head==nullptr)
          {
             cout<<"\n the circular linked list is empty.nothing to delete";
             return;
          }
         else
          {
              Node *current=head;
              Node *prev=nullptr;
              while(current->next!=head)
               {
                   prev=current;
                   current=current->next;
               }
              if(prev==nullptr)
                {
                    head=nullptr;
                    cout<<current->data<<" deleted ";
                    delete current;
                    cout<<"\n list is empty";
                    return;
                }
              else
               {
                   prev->next=head;
                   cout<<current->data<<" deleted ";
                   delete current;
                   display();
               }
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
                  if(current->next==head && prev==nullptr)
                    {
                        head=nullptr;
                        cout<<current->data<<" deleted ";
                        delete current;
                        cout<<"\n list is empty"<<endl;
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
                  cout<<current->data<<" deleted";
                 delete current;
                 display();
                }
             else
              {
                  cout<<"\n invalid position.nothing to delete"<<endl;
                  return;
              }
        }
};
int main()
{
    Circularlist list;
    int n,y,ch,p;
    do
    {
        cout<<"\n enter the element you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want insert another element(enter 1 to continue): ";
        cin>>y;
    }while(y==1);
    cout<<"\n the circular linked list is: ";
    list.display();
    do
    {
        cout<<"\n....menu..."<<endl
            <<"1.delete at beginning"<<endl
            <<"2.delete at end"<<endl
            <<"3.delete at specific position"<<endl
            <<"0.exit"<<endl
            <<"enter your choice: ";
        cin>>ch;
        switch(ch)
         {
          case 1:list.deletebeg();
                 break;
          case 2:list.deleteEnd();
                 break;
          case 3:if(list.head==nullptr)
                    {
                      cout<<"\n list is empty .deletion is not possible";
                    }
                else
                {
                 cout<<"\n enter the position you want to delete: "    ;
                 cin>>p;
                 list.deleteAtSpecific(p);
                }
                 break;
         case 0 :cout<<"\n exiting....";
                 break;
         default:cout<<"\n invalid choice "<<endl;
        }
    }while(ch!=0);
 return 0;
}