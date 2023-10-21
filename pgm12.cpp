//12.(corrected final) Write a program to sort a list of elements using quick sort.
#include<iostream>
#define size 5
using namespace std;
class Array
{
    int pi,pivot,a[size],x;
  public:
  void readdata(int n)
  {
    x=n;
    for(int i=0;i<x;i++)
      cin>>a[i];
  }
     void quicksort(int low,int high)
        {
          if(low<high)
            {
                pi=partition(low,high);
                quicksort(low,pi-1);
                quicksort(pi+1,high);
            }
        }
    int partition(int low,int high)
      {
        int i,j;
        pivot=a[high];
        i=(low-1);
        for(j=low;j<high;j++)
           {
               if(a[j]<pivot)
                 {
                     i=i+1;
                     swap(i,j);
                 }
           }
        i=i+1;
        swap(i,j);
       return(i);
      }
    void swap(int i,int j)
     {   
         int temp;
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
     }
    void display()
     {
          for(int i=0;i<x;i++)
           cout<<a[i]<<" ";
     }
};
int main()
{   
    Array q1;
    int n,i,high,low;
    top: cout<<"\n enter the number of array elements : ";
    cin>>n;
    low=0;
    high=n-1;
    if((n<=size)&&(n>0))
    {
        cout<<"\n enter "<<n<<" elements: ";
        q1.readdata(n);
        cout<<"\n array elements are: ";
        q1.display();
        q1.quicksort(low ,high);
        cout<<"\n the sorted array is: ";
        q1.display();
    }
  else
    {
       cout<<"\n invalid size entry.enter a valid size between 1-5";
        goto top;
    }
  return 0;
}