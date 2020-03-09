#include<iostream>
using namespace std;
struct node{
int data;
struct node *lchild,*rchild;
}*root,*root1;
class bst
{
public:
bst()
{
root=NULL;
root1=NULL;
}
struct node *create();
struct node *insert1(struct node*,struct node*);
void search1(struct node*,int);
int height(struct node*);
int min1(struct node*);
struct node *swapp(struct node*);
struct node *inorder(struct node*);
};

struct node *bst::create()
{
struct node *current;
int info;
current=new node();
current->lchild=NULL;
current->rchild=NULL;
cout<<"\nEnter data ";
cin>>info;
current->data=info;
if(root==NULL)
{
root=current;
}
else
{
    insert1(root,current);
}
}
struct node *bst::insert1(struct node *root,struct node *current)
{
if(root->data>=current->data)
{
if(root->lchild==NULL)
{
root->lchild=current;
}
else{
insert1(root->lchild,current);
}
}
else{
if(root->rchild==NULL)
{
root->rchild=current;
}
else{
insert1(root->rchild,current);
}
}
}
void bst::search1(struct node *root,int dat)
{

    if(root->data==dat)
    {
        cout<<"Elemnt found\n";
    }
    else if(root->data<dat && root->rchild!=NULL)
    {
        search1(root->rchild,dat);
    }
    else if(root->data>dat && root->lchild!=NULL)
    {
        search1(root->lchild,dat);

    }
    else{

        cout<<"Elemnt not found\n";

    }
};
int bst::height(struct node *root)
{
    int l,r;
    if(root==NULL)
    {
        return 0;
    }
    if(root->lchild==NULL && root->rchild==NULL)
    {
        return 1;
    }
    else{
            l=height(root->lchild);
            r=height(root->rchild);
            if(l>=r)
            {
                return(l+1);
            }
            else{

                return(r+1);
            }


    }
}

int bst::min1(struct node *root)
{
    struct node *current;
    current=root;
    while(current->lchild!=NULL)
    {
        current=current->lchild;
    }
    return current->data;

}
struct node *bst::swapp(struct node *root1)
{
    struct node *temp;
    if(root1!=NULL)
    {
        swapp(root1->lchild);
        swapp(root1->rchild);
        temp=root1->lchild;
        root1->lchild=root1->rchild;
        root1->rchild=temp;
    }
    return root1;

};
struct node *bst::inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        cout<<root->data<<"\t";
        inorder(root->rchild);
    }
};
int main()
{

bst b;
while(1)
{
int ch,nheight;
cout<<"\n1.Add Element\n2.search\n3.height\n4.min\n5.swap\n(0 for EXIT)";
cout<<"\nEnter your choice ";
cin>>ch;
switch(ch)
{
case 1:
    b.create();
    break;

case 2:
    int dat;
    cout<"\nEnter data to be search ";
    cin>>dat;
   b.search1(root,dat);
    break;
case 3:
    nheight=b.height(root);
    cout<<"\nHeight of tree is="<<nheight;
    break;
    case 4:nheight=b.min1(root);
    cout<<"\nminimum element is="<<nheight;
    case 5:
        root1=b.swapp(root);
        b.inorder(root1);
        break;
case 0:
    return 0;
    default:cout<<"\nYou have entered wrong choice!!!!\n";
    break;
}


}
}

