#include<iostream>
#include<stdlib.h>
#define max 10
using namespace std;
struct list1
{
int data;
struct list1 *next;
}node,*ptr[max],*root[max],*temp[max];

class dictionary
{
int index;
public:
dictionary();
void insert1(int);
void display();
void search1(int);
void delete1(int);
};

dictionary::dictionary()
{
index=-1;
for(int i=0;i<max;i++)
{
root[i]=NULL;
ptr[i]=NULL;
temp[i]=NULL;
}
}
void dictionary::insert1(int key)
{
index=int(key%max);
ptr[index]=new list1;
ptr[index]->data=key;
if(root[index]==NULL)
{
root[index]=ptr[index];
root[index]->next=NULL;
temp[index]=ptr[index];

}
else{
temp[index]=root[index];
while(temp[index]->next!=NULL)
{
temp[index]=temp[index]->next;

}
temp[index]->next=ptr[index];
}
}
void dictionary::display()
{
    index=0;
    while(index<max)
    {
        if(root[index]!=NULL)
        {
            temp[index]=root[index];
            while(temp[index]!=NULL && temp[index]->data!=-1)
            {
                cout<<" \n"<<temp[index]->data;
                temp[index]=temp[index]->next;
            }
        }
        index++;
    }
}

void dictionary::search1(int key)
{
    int flag=0;
    index=int(key%max);
    temp[index]=root[index];
    while(temp[index]!=NULL)
    {
        if(temp[index]->data==key)
        {
            cout<<"\nsearch key found";
        flag=1;
        break;
        }
        else{temp[index]=temp[index]->next;}
    }
    if(flag==0)
    {
        cout<<"\nsearch key not found!!!!";
    }
}
void dictionary::delete1(int key)
{

index=int(key%max);
temp[index]=root[index];
while(temp[index]->data!=key && temp[index]!=NULL)
{
    ptr[index]=temp[index];
    ptr[index]=temp[index]->next;

}
ptr[index]->next=temp[index]->next;
cout<<temp[index]->data<<"has been deleted\n";
temp[index]->data=-1;
temp[index]=NULL;
free(temp[index]);

}

int main()
{
int n,ch,num,key;
dictionary d;
while(1)
{
cout<<"\nmenu\n1.Create\n2.Display\n3:Search\n4.Delete\n(press 0 to exit)\n";
cout<<"Enter choice ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter the the number of element to be inserted ";
cin>>n;
cout<<"\nENter the elemnt to be inserting ";
for(int i=0;i<n;i++)
{
cin>>num;
d.insert1(num);

}
break;
case 2:
    d.display();
    break;
case 3:
    cout<<"\nEnter key to search ";
    cin>>key;
    d.search1(key);
    break;
case 4:
    cout<<"\nEnter key to delete ";
    cin>>key;
    d.delete1(key);
    break;
case 0:
    return 0;
}
}
}
