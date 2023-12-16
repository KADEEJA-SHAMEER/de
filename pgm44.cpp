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
            cout<<"\n the inorder traversal of the binary search tree is: ";
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
    Node *successor(Node *ptr)
      {
         Node *ptr2=ptr,*ptr1=ptr->rchild;
         if(ptr1!=nullptr)
            {
              while(ptr1->lchild!=nullptr)
                 {
                  ptr2=ptr1;
                  ptr1=ptr1->lchild;
                 }
              ptr2->rchild=nullptr;
            }
          return ptr1;
      }
    void deleteN(int item)
         {
           
           Node *ptr=root,*ptr1;
           int f=0,ch,item1;
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
                           break;
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
                    delete ptr;
                    display();
                    break;
            case 2: Node *succ;
                    succ=successor(ptr);
                    item1=succ->data;
                    ptr->data=item1;
                    delete succ;
                    display();
                    break;
            case 3: if(ptr1->rchild==ptr)
                       {
                        if(ptr->lchild==nullptr)
                           ptr1->rchild=ptr->rchild;
                        else
                           ptr1->rchild=ptr->lchild;
                       }
                    else
                      {
                        if(ptr1->lchild==ptr)
                          {
                             if(ptr->lchild==nullptr)
                                ptr1->lchild=ptr->rchild;
                             else
                                ptr1->lchild=ptr->lchild;
                          }
                      }
                    delete ptr;
                    display();
                    break;  
          }
   }  
         
};
int main()
{
  int n,y,ch;
  BST bst;
  do
  {
    cout<<"\n enter the element you want to insert: ";
    cin>>n;
    bst.create(n);
    cout<<"\n do you want to add another element(enter 1 to continue): ";
    cin>>y;
  }while(y==1);
  bst.display();
  do
  {
    cout<<"\n ...menu..."<<endl
        <<"1.insert int BST"<<endl
        <<"2.delete fron BST"<<endl
        <<"0.exit"<<endl
        <<"enter your choice: ";
    cin>>ch;
    switch(ch)
      {
        case 1: cout<<"\n enter the element you want to insert: ";
                cin>>n;
                bst.create(n);
                bst.display();
                break;
        case 2: cout<<"\n enter thr element you want to delete: ";
                cin>>n;
                bst.deleteN(n);
                break;
        case 0: cout<<"\n exiting...";
                break;
       default: cout<<"\n invalid choice";
      }
  }while(ch!=0);
  return 0;
}