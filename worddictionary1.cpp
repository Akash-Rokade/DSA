#include<iostream>
#include<string.h>
using namespace std;
class node{
public:
char k[20];
char m[20];
class node *l,*r;
};
class dict
{
public:
node *root;
void create();
void insert1(node *root,node *temp);
void display(node *);
int search1(node *,char []);
int update(node *,char []);

};
void dict::create(){
class node *temp;
int ch;

do{
        if(ch==0)
        {
            break;
        }
temp=new node;
cout<<"Enter Keyword ";
cin>>temp->k;
cout<<"Enter meaning ";
cin>>temp->m;

temp->l=NULL;
temp->r=NULL;
if(root==NULL)
{
root=temp;

}
else{
insert1(root,temp);

}
cout<<"Do you want add more\n";
int ch;
cin>>ch;

}
while(ch==1);
}
void dict::insert1(node *root,node *temp)
{
if(strcmp(temp->k,root->k)<0)
{
if(root->l==NULL)
root->l=temp;

else
insert1(root->l,temp);

}
else{
if(root->r==NULL){
root->r=temp;
}
else{insert1(root->r,temp);}
}}
void dict::display(node *root)
{
    if(root!=NULL)
    {
        display(root->l);
        cout<<"\n key word "<<root->k;
        cout<<"\nMeaning "<<root->m;
        display(root->r);
    }


}
int dict::search1(node *root,char k[20])
{
    int c=0;
    while(root!=NULL)
    {
        if(strcmp(k,root->k)==0)
        {
            cout<<"\nno of comparision";
            return 1;
        }
        if(strcmp(k,root->k)<0)
            root=root->l;
        if(strcmp(k,root->k)>0)
            root=root->r;
    }
    return -1;
}
int dict::update(node *root,char k[20])
{
    while(root!=NULL)
    {
        if(strcmp(k,root->k)==0)
        {
            cout<<"Enter the new meaning of word "<<root->k;
            cin>>root->m;
            return 1;
        }
        if(strcmp(k,root->k)<0)
            root=root->l;
        if(strcmp(k,root->k)>0)
            root=root->r;
    }
    return -1;
}

int main()
{
int ch;
char k[20];
dict d;
d.root=NULL;
do{
cout<<"ENter your choice \n1.create\n2.display\n3.search\n4.update\n5.delete";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\n";
d.create();
break;
case 2:
    if(d.root==NULL)
    {
        cout<<"\nNo any keyword";

    }
    else{
    d.display(d.root);}
break;
case 3:
    if(d.root==NULL)
    {
        cout<<"\nNo data ";

    }
    else {
        cout<<"\nEnter keyword to search ";
        cin>>k;
        if(d.search1(d.root,k)==1)
            cout<<"Keyword found\n";
        cout<<"Keyword not found\n";
    }
break;
case 4:
    if(d.root==NULL)
    {
        cout<<"Dictionary is empty.first add keyword then try again ";
    }
    else{
        cout<<" Enter keyword which meaning want to update:";
        char k[20];
        cin>>k;
        if(d.update(d.root,k)==1)
            cout<<"\nMeaning update";
            else{
        cout<<"Mening not found\n";
    }}
    break;

}
}
while (ch==1);

}
