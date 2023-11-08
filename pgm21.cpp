//21. Write a program to Implementation of queue using array (linear queue) menu driven program.
#include<iostream>
#define size 5
using namespace std;
class Queue
{
  int queue[size],front =0,rear=0,x;
  public:
     void readdata(int n)
        {
              x=n;
             for(int i=front;i<x;i++)
                {
                    cin>>queue[i];
                }
             rear=x-1;
          }
      void insert()
         {
            int item;
            if(rear>=size-1)
              {
                 cout<<"\n queue is full.insertion is not possible";
                 return;
              }
            else
              {
                cout<<"\n enter the item to be inserted: ";
                cin>>item;
                if(front==-1)
                   front=0;
                rear=rear+1;
                x=x+1;
                queue[rear]=item;
              
                display();
              }
           
         }
    void Delete()
     { 
         int item;
         if((front <0)||(front >rear))
            {
                cout<<"\n queue is empty ";
               return;
            }
          else
          {
           item=queue[front];
           front =front+1;
           cout<<"\n "<<item <<" deleted from queue";
           if(front>rear)
             {
              cout<<"\n queue is empty.deletion is not possible";
              front=rear=-1;
              x=0;
             }
           else
             {
                display();
             }
          }
     }
     void display()
    {  
        if(rear==-1 )
           {
             cout<<"\n queue is empty ";
             return;
           }
        else
        {
        cout<<"\n queue elements are: ";
        for(int i=front;i<x;i++)
           cout<<queue[i]<<" ";
        }
    }
};
int main()
{
    Queue q1;
    int n,ch;
    top:cout<<"\n enter the number of elements in queue: ";
    cin>>n;
    if((n<=size)&&(n>0))
    {
        cout<<"\n enter the elements of queue: ";
        q1.readdata(n);
       
        q1.display();
        do
        {
            cout<<"\n 1.insert an element";
            cout<<"\n 2.delete an item";
            cout<<"\n 3.display";
            cout<<"\n 0.exit";
            cout<<"\n enter your choice: ";
            cin>>ch;
            switch(ch)
             {
               case 1:q1.insert();
                       break;
               case 2:q1.Delete();
                      break;
               case 3:q1.display();
                       break;
               case 0: cout<<"\n exiting.... ";
                       break;
              default:cout<<"\n invalid choice";
             }
        }while(ch!=0);
    }
   else
    {
      cout<<"\n invalid size entry.enter size between 1-5";
      goto top;
    }
return 0;
}