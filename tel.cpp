#include<iostream>
using namespace std;
struct tel
{
char name;
long number;
};
class dir
{
tel book[25];
public:
dir()
{
for(int i=0;i<25;i++)
{
book[i].name=' ';
book[i].number=0;
}
}
void create(int,char,long);
void display();
void search1(char,int);
};
void dir::search1(char key,int i){
int flag=0,cnt=1;
if(book[i].name=key)
{
    cout<<"FOUND at "<<i<<"th position";
    cout<<"\nNumber of comparison "<<cnt;
}
else{
    for(int j=i+1;j<25;j++)
    {
        cnt++;
        if(book[j].name==key)
        {

            cout<<"Found AT"<<j<<"th position";
            cout<<"\nnumber of comparision"<<cnt;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        for(int j=0;j<i;j++)
        {

            cnt++;
            if(book[j].name==key)
            {

                cout<<"Key found at"<<j<<"th position\nNumber of comparision "<<cnt;
                flag=1;
            }

        }
    }
    if(flag==0)
    {
        cout<<"\nnot found\n";
    }
}

}
void dir::create(int i,char key,long n)
{
    int flag=0;
    if(book[i].name==' ')
    {
    book[i].name=key;
    book[i].number=n;
    }
    else{
        for(int j=i+1;j<25;j++)
        {
            if(book[j].name==' ')
            {
                book[j].name=key;
                book[j].number=n;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=0;j<i;j++)
            {
                if(book[j].name=' ')
                {
                 book[j].name=key;
                book[j].number=n;
                flag=1;
                break;
                }
            }
        }
        if(flag==0)
        {
            cout<<"OVERFLOW!!!!";
        }
    }


}
void dir::display()
{

    for(int i=0;i<25;i++)
    {
            cout<<" \n"<<book[i].name<<"->"<<book[i].number;

    }
}

int main()
{
    int ch,tmp,m,i;
    char key;
    dir d;
    long n;
    while(1){
    cout<<"\n\t\tMENU\n1:create\n2:display\n3:search(0 for EXIT)\nEnter choice ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"how many ";
        cin>>m;
        for(int i=0;i<m;i++){
        cout<<"\nEnter name ";
        cin>>key;
        cout<<"\nEnter number ";
        cin>>n;
        tmp=n;
        tmp=n%25;
        d.create(tmp,key,n);
        }
        break;
    case 2:
        d.display();
        break;
    case 3:
        cout<<"\nEnter key to be search ";
        cin>>key;
        i=key;
        i=i%25;
        d.search1(key,i);
        break;
    case 0:
        cout<<"\n\n\nExited!!!!!\n";
         return 0;
       break;

    }
    }
}
