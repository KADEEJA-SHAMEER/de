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
     Node *start;
     int count;
    public:
     Linkedlist()
     {
         start=nullptr;
         count=0;
     }
    void create(int value)
      {
         Node *newnode =new Node(value);
         if(start==nullptr)
            start=newnode;
        else
        {
            Node *temp=start;
            while(temp->next!=nullptr)
                temp=temp->next;
            temp->next=newnode;
        }
      }
    void display()
      {
        if(start==nullptr)
          {
             cout<<"\n list is empty";
             return;
          }
        else
        {
            Node *temp=start;
            while(temp!=nullptr)
              {
                 cout<<temp->data<<"->";
                 temp=temp->next;
              }
            cout<<"nullptr"<<endl;
        }
      }
    int countNodes()
      {
         Node *temp=start;
         while(temp!=nullptr)
           {
            temp=temp->next;
            count++;
           }
        return count;
      }
};
int main()
{
    Linkedlist list;
    int countN,n,ch;
    do
    {
        cout<<"\n enter the number you want to insert: ";
        cin>>n;
        list.create(n);
        cout<<"\n do you want to add one more element(enter 1 to continue): ";
        cin>>ch;
    }while(ch==1);
   cout<<"\n the linked list is : ";
   list.display();
   countN =list.countNodes();
   cout<<"\n number of nodes created: "<<countN <<endl;
   return 0;
}
