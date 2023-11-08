//16.(corrected final) Write a program to Implementation of stack using arrays (linear stack) menu driven program.
#include<iostream>
#define size 5
using namespace std;
class Stack
{   int stack[size],top,x;
    public:
    void readdata(int max)
        { x=max;
         for(top=0;top<x;top++)
            cin>>stack[top];
        top=top-1;
        }
    int pushitem(int item)
     {
       if(top==size-1) 
         {
           return x;
         }
       else
         {   x=x+1;
            top=top+1;
            stack[top]=item;
          }
        return x;
      }
     int popitem()
       { int item;
          if((top<0)||(top==-1))  
           {
             return x;
           }
          else
           {
            x=x-1;
            item=stack[top];
             cout<<"\n "<<item <<" deleted successfully \n";
            top=top-1;
           }
        return x;
      }
    void display()
       {  if(top==-1 || top<0)
             {
                cout<<"\n stack is empty";
                return;
             }
          else
          {
            cout<<"\n stack elements are: ";
          for(top=0;top<x;top++)
            cout<<stack[top]<<" ";
          cout<<endl;
         top=top-1;
          }
       }

};
int main()
{   
    Stack s1;
    int max,ch,item;
    top:cout<<"\n enter the size of stack: ";
    cin>>max;
    if((max<=size)&&(max>0))
    {
        cout<<"\n enter "<<max<<" elements: ";
        s1.readdata(max);
       
        s1.display();
        do
        {
        cout<<endl;
        cout<<"\n ...stack operations...";
        cout<<"\n 1.insert an element";
        cout<<"\n 2.delete an element";
        cout<<"\n 3.display stack";
        cout<<"\n 0.exit";
        cout<<"\n enter your choice: ";
        cin>>ch;
        switch(ch)
           {
            case 1: if(max!=size)
                      {
                        cout<<"\n enter the item to be inserted: ";
                        cin>>item;
                      max=s1.pushitem(item);
                        
                         s1.display();
                      if(max==size)
                        {
                            cout<<"\n satck is full more insertion is not possible ";
                        }
                       }
                      else
                       cout<<"\n stack is full .insertion is not possible";
                       break;
            case 2: 
                     max= s1.popitem();
                    if(max==0)
                      {
                       cout<<"\n stack  empty more deletion  is not possible";
                      }
                    else
                     { 
                      
                      s1.display();
                     }
                    break;
           case 3:
                  s1.display();
                  break;
           case 0:cout<<"exiting....";
                  break;
          default:cout<<"\n invalid choice";
         }
    }while(ch!=0);
 }
else
 {
    cout<<"\n invalid size entry.enter valid size between 1-5";
    goto top;
 }
 return 0;
}