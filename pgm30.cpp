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
         return;
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
 int countNode()
  {
     int countN=1;
     Node*temp=head;
     if(head==nullptr)
       {
        return 0;
       }
     while(temp->next!=nullptr)
      {
        countN++;
        temp=temp->next;
      }
    return countN;
  }
       
  void insertspecific(int n,int p,int countN)
  {   
    Node *ptr,*temp;
     if(((p!=countN)&&(p>countN+1))||(p<=0))
       {
        cout<<"\n invalid position";
        return;
       }
    if(p==1)
     {
       ptr=new Node(n);
       ptr->next=head;
       head=ptr;
     }
    else if(p==countN+1)
            {
              ptr=new Node(n);
              if(head==nullptr)
                  head=ptr;
               else
                 {
                  temp=head;
                  while(temp->next!=nullptr)
                    temp=temp->next;
                  temp->next=ptr;
                 }
            }
          else
            {
              temp=head;
              int currp=1;
              while((currp< p-1)&&(temp->next!=nullptr))
                {
                    currp++;
                    temp=temp->next;
                }
              ptr=new Node(n);
              ptr->next=temp->next;
              temp->next=ptr;
            }
        display();
  }
};
int main()
{
    Linkedlist list;
    int ch,a,item,p,c;
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
                   cout<<"\n the position you want to insert element: ";
                   cin>>p;
                   c=list.countNode();
                   list.insertspecific(item,p,c);
                   break;
           case 2:if(list.head==nullptr)
                     {
                      cout<<"\n list is empty.deletion is not poosible"<<endl;
                     }
                  else
                  {
                  cout<<"\n enter the element you want to delete: "    ;
                  cin>>item;
                  list.Delete(item);
                  }
                  break;
         case 0: cout<<"\n exiting...";
                 break;
        default:cout<<"\n invalid cchoice..";
        }
    }while(ch!=0);
 return 0;
}