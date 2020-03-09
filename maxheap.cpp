#include<iostream>
using namespace std;
#define max1 20
class stud
{
int mks[max1];
public:
stud()
{
for(int i=0;i<max1;i++)
{mks[i]=0;}
}
void insert1(int);
void display();
void min1(int);
void maximum();
};
void stud::insert1(int tot)
{

    for(int i=1;i<=tot;i++)
    {
        cout<<"Enter marks ";
        cin>>mks[i];
        int j=i;
        int par=j/2;
        while(mks[j]>mks[par]&&par!=0)
        {
            int tmp=mks[j];
            mks[j]=mks[par];
            mks[par]=tmp;
            j=par;
            par=j/2;

        }
    }
}
void stud::min1(int tot)
{
    int min2=mks[1];
    for(int i=2;i<=tot;i++)
    {
        if(min2>mks[i])
        {
            min2=mks[i];
        }
    }
    cout<<"\nMinimum marks is "<<min2;

}
void stud::maximum()
{
cout<<"maximum marks is "<<mks[1];
}
int main()
{
    stud s;
    int tot,ch;
    while(1){
    cout<<"\n menu\n1.insert\n2.show min\n3:max marks\nEnter your choice ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"\nHow many ";
    cin>>tot;
        cout<<"\n";
        s.insert1(tot);
        break;
    case 2:

        s.min1(tot);
        break;
    case 3:
        s.maximum();
        break;
    case 0:
        cout<<"Exited\n";
        return 0;
        break;

    }
}
}
