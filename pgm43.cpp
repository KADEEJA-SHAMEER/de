//43. Write a C++ program to Creation of binary search trees. Tree traversals. Recursive function
//for traversals.
#include<iostream>
using namespace std;
class Node
{
    public:
      int data;
      Node *lchild;
      Node *rchild;
      Node(){}
      Node(int value)
        {
            data=value;
            lchild=nullptr;
            rchild=nullptr;
        }
};
class BST
{
    public:
      Node *root;
      BST()
      {
        root=nullptr;
      }
      void create(int value)
        {
            Node *newnode = new Node(value);
            if(root==nullptr)
              {
                root=newnode;
              }
            Node *ptr=root,*ptr1;
            while(ptr!=nullptr)
            {
            if(newnode->data<ptr->data)
               {
                 ptr1=ptr;
                 ptr=ptr->lchild;
               }
            else if(newnode->data>ptr->data)
                    {
                        ptr1=ptr;
                        ptr=ptr->rchild;
                    }
                 else if(newnode->data==ptr->data)
                         {
                            cout<<"\n item already exist";
                            return;
                         }
            }
           if(ptr==nullptr)
             {
                if(ptr1->data<newnode->data)
                    ptr1->rchild=newnode;
                else
                  ptr1->lchild=newnode;
             }
        }
      
};