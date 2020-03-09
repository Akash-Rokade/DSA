#include<iostream>
#include<string.h>
using namespace std;
struct node
{
string data;
struct node *child,*sibling;
}*root,*newnode,*uhead,*chead[20],*h,*c;
class book
{
public:
    book()
    {root=NULL;}
    void create();
    void insert();
    void display();

};

void book::create()
{
newnode=new node();
newnode->child=NULL;
newnode->sibling=NULL;
}

void book::insert()
{
int nunit,nchap;
string bname,cname,uname;
cout<<"ENter the book name\n";
cin>>bname;
create();
newnode->data=bname;
root=newnode;
cout<<"Enter how many units\n";
cin>>nunit;
for(int i=0;i<nunit;i++)
{
create();
cout<<"ENter the unit name\n";
cin>>uname;
newnode->data=uname;
if(i==0)
{
uhead=h=newnode;
root->child=uhead;
}
else{
h->sibling=newnode;
h=newnode;
}
cout<<"hw mny chap\n";
cin>>nchap;
for(int i=0;i<nchap;i++)
{
    cout<<"ENter the chap name\n";
    cin>>cname;
    create();
    newnode->data=cname;
    if(i==0)
    {
        chead[i]=c=newnode;
        uhead->child=newnode;

    }
    else{

        c->sibling=newnode;
        c=newnode;
    }
    }
}
display();
}
void book::display()
{
    struct node *p,*q;
    cout<<"\n\n\n\n\nBook name is=";
    cout<<"\t"<<root->data;
    cout<<"\n";
    p=uhead;
    cout<<"UNITs=\t";
    while(p!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->sibling;
    }
    cout<<"\nchapters=";
    for(int i=0;chead[i]!=0;i++)
    {
        q=chead[i];
        while(q!=NULL)
        {
            cout<<q->data<<"\t";
            q=q->sibling;
        }
    }
    cout<<"\n";
}
int main()
{
book b;
b.insert();
return 0;
}
