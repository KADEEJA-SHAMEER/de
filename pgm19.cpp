//19. Write a program to add two Polynomials using arrays
#include<iostream>
using namespace std;
class Poly
 {
    public:
     int coeff;
     int expn;
 };
class Polynomial
 {
    Poly p[20];
    public:
     int n;
     void read()
       {
           int i;
           for(i=0;i<n;i++)
             {
              cout<<"\n enter the coefficient & exponent: ";
              cin>>p[i].coeff>>p[i].expn;
             }
       }
     void display()
        {
         for(int i=0;i<n;i++)
            {
             cout<<p[i].coeff<<"x^"<<p[i].expn;
             if(i!=n-1)
                cout<<" + ";
            }
        cout<<"\n";
        }
    void sort(int s)
     {
        Polynomial p4;
        int k=0;
        for(int i=0;i<n-1;i++)
           {
             for(int j=i+1;j<n;j++)
               {
                  if(p[i].expn<p[j].expn)
                    {
                        p4.p[k].expn=p[i].expn;
                        p4.p[k].coeff=p[i].coeff;
                        p[i].expn=p[j].expn;
                        p[i].coeff=p[j].coeff;
                        p[j].expn=p4.p[k].expn;
                        p[j].coeff=p4.p[k].coeff;
                        k++;
                    }
               }
           }
        cout<<endl;
         for(int i=0;i<n-1;i++)
           {
             for(int j=i+1;j<n;j++)
               {
                  if(p[i].expn==p[j].expn)
                    {
                        cout<<"\n invalid polynomail expression for polynomial "<<s<<" .addition is not possible";
                        exit(0);
                    }
               }
           }
    }
     Polynomial operator + (Polynomial p2)
         {
            Polynomial p3;
            int i=0,j=0,k=0;
            while((i<n)&&(j<p2.n))
             { 
               if(p[i].expn>p2.p[j].expn)
                  {
                     p3.p[k]=p[i];
                     i++;
                  }
                else if(p[i].expn<p2.p[j].expn)
                       {
                           p3.p[k]=p2.p[j];
                           j++;
                       }
                      else
                        {
                         p3.p[k].coeff=p[i].coeff+p2.p[j].coeff;
                         p3.p[k].expn=p[i].expn;
                         i++;
                         j++;
                        }
                     k++;
             }
          while (i<n)
           {
               p3.p[k]=p[i];
               i++;
               k++;
           }
          while(j<p2.n)
            {
             p3.p[k]=p2.p[j];
             j++;
             k++;
            }
        p3.n=k;
        return p3;
     }
 };
 int main()
 {
  Polynomial p1,p2,p3;
  cout<<"\n enter the no of terms in 1st polynomial: ";
  cin>>p1.n;
  p1.read();
  cout<<"\n enter the no of terms of 2nd polynomial: ";
  cin>>p2.n;
  p2.read();
  p1.sort(1);
  p2.sort(2);
  cout<<"\n first polynomial is: ";
  p1.display();
  cout<<"\n 2nd polynomial is: ";
  p2.display();
  p3=p1+p2;
  p3.display();
  return 0;
 }