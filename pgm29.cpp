//write a c++ program to delete an element anywhere from linear linked list .menu driven program.
//(at the beginning,end and after an element).
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
            return;
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
                        return;
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
    void deletebeg()
     {
        Node *ptr;
        if(head==nullptr)
          {
            cout<<"\n the list is empty"<<endl;
            exit(0);
          }
        else
         {
            ptr=head;
            head=head->next;
            delete ptr;
         }
        display();
     }
    void deleteEnd()
      {
        Node *ptr,*loc;
        if(head==nullptr)
         {
            cout<<"\n the list is empty no more deletion is possible";
            exit(0);
         }
        else 
         {
            if(head->next==nullptr)
              {
                ptr=head;
                head=nullptr;
                delete ptr;
              }
            else
             {
               loc=head;
               ptr=head->next;
               while(ptr->next!=nullptr)
                {
                    loc=ptr;
                    ptr=ptr->next;
                }
               loc->next=nullptr;
               delete ptr;
             }
           display();
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
   do
   {
    cout<<"\n...menu..."<<endl
        <<"1.delete from beginning"<<endl
        <<"2.delete from end"<<endl
        <<"3.delete after an element"<<endl
        <<"0.exit"<<endl
        <<"enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:list.deletebeg();
               break;
        case 2:list.deleteEnd();
               break;
        case 3:cout<<"\n after which element you want to delete: ";
               cin>>item;
               list.deleteSpecific(item);
               break;
        case 0:cout<<"\n exiting..."<<endl;
               break;
        default:cout<<"\n invalid choice.";
    }
   }while(ch!=0);
   return 0;
}
