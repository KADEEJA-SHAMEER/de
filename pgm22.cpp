#include<iostream>
#define size 5
using namespace std;
class  C_Queue
{
  int queue[size],front =0,rear=-1,x;
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
            if(front==(rear+1)%5)
              {
                 cout<<"\n queue is full.insertion is not possible";
                 return;
              }
            else
              {
                if (front == -1)
                    front =0;
                  rear = ((rear+ 1)%5);
                  cout<<"\n enter the item to insert: ";
                  cin>>item;
                  queue[rear]=item;
                x=x+1;
                display();
                
              }
           
         }
    void Delete()
     { 
         int item;
         if(front ==-1)
            {
                cout<<"\n queue is empty";
                return;
            }
          else
         {
           item=queue[front];
         if(front==rear) 
           front=rear=-1;
        else
          front=((front+1)%5);
           cout<<"\n "<<item <<" deleted from queue \n";
                display();
          }
     }
     void display()
    {   int i;
        if(front==-1)
          {
            cout<<"\n queue is empty";
            return;
          }
        else
        {
         cout<<"\n queue elements are : ";
         if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                    cout << queue[i] << " ";
            }
             else 
            {   
                for (i = 0; i <= rear; i++)
                    cout << queue[i] << " ";
                for (i = front; i < size; i++)
                    cout << queue[i] << " ";
            }
        }
    }
    
};
int main()
{
    C_Queue q1;
    int n,ch,r,f;
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