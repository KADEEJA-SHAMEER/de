#include<iostream>
using namespace std;
class Node
{
     public:
      int data;
      Node *next;
      Node(int value)
        {
             data =value;
             next=nullptr;
        }
};
class Linkedlist
{
     Node *head;
    public:
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
            Node *temp=head;
            while(temp->next!=nullptr)
                temp=temp->next;
            temp->next=newnode;
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
            cout<<"\n the linked list is: ";
            Node *temp=head;
            while(temp!=nullptr)
              {
                 cout<<temp->data<<"->";
                 temp=temp->next;
              }
            cout<<"nullptr"<<endl;
        }
      }
    void deleteSpecific(int item)
       {
        Node *ptr,*loc,*temp;
        ptr=head;
        loc=nullptr;
        if(ptr==nullptr)
          {
            cout<<"\n list is empty"<<endl;
            exit(0);
          }
        if(head->next==nullptr)
          {
            cout<<"\n only one node left.deletion after an element is not possible";
            exit(0);
          }
        else
         {
            while(ptr!=nullptr)
              {
                if(ptr->data==item)
                  {
                    loc=ptr;
                    if(loc->next==nullptr)
                      {
                        cout<<"\n no node after "<<item<<". deletion is not possible";
                        exit(0);
                      }
                    break;
                  }
                else
                  ptr=ptr->next;
              }
            if(loc==nullptr)
               cout<<"\n item not found"<<endl;
            else
             {
                temp=loc->next;
                loc->next=temp->next;
                delete temp;
                display();
             }
         }
       }
};
int main()
{
    Linkedlist list;
    int item,n,ch;
    do
    {
        cout<<"\n enter the number you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want to add one more element(enter 1 to continue): ";
        cin>>ch;
    }while(ch==1);
   list.display();
   cout<<"\n after which element you want to delete element: ";
   cin>>item;
   list.deleteSpecific(item);
   return 0;
}
