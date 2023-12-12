//44.(not completed) Write a C++ program to Implementation of Insertion and deletion of nodes in the binary
//search trees.
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
            else
            {
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
      }
   void display()
    {
       if(root==nullptr)
          {
            cout<<"\n binary search tree is empty";
            return;
          }
        else
          {
            Inorder(root);
          }
     
    } 
   void Inorder(Node *node)
          {
            if(node!=nullptr)
              {
                Inorder(node->lchild);
                cout<<node->data<<" ";
                Inorder(node->rchild);
              }
          }
    void deleteN(int item)
         {
           Node *ptr=root,*ptr1;
           int f=0,ch;
           if(root==nullptr)
             {
                 cout<<"\n binary search tree is empty.deletion is not possible";
                 return;
             }
            while(ptr!=nullptr)
            {
            if(item<ptr->data)
               {
                 ptr1=ptr;
                 ptr=ptr->lchild;
               }
            else if(item>ptr->data)
                    {
                        ptr1=ptr;
                        ptr=ptr->rchild;
                    }
                 else if(item==ptr->data)
                         {
                           f=1;
                         }
            }
         if(f==0)
           {
            cout<<"\n "<<item<<" does not exist in binary search tree.deletion is not possinble";
            return;
           } 
         if((ptr->lchild==nullptr) && (ptr->rchild==nullptr))
             ch=1;
         else if((ptr->lchild!=nullptr) && (ptr->rchild!=nullptr))
                 ch=2;
              else 
                 ch=3;
         switch(ch)
          {
            case 1: if(ptr1->lchild==ptr)
                       ptr1->lchild=nullptr;
                    else
                       ptr1->rchild=nullptr;
                    cout<<"\n node with element "<<item<<" deleted";
                    delete ptr;
                    break;
            case 2: 
                      
          }
           
         }
};