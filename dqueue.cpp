#include<iostream>
using namespace std;
#define size 5
class dequeue
{
  int a[10],front,rear;
   public:
    dequeue();
   void add_at_beg(int);
    void add_at_end(int);
    void delete_from_front();
   void delete_from_rear();
   void display();
};
 dequeue::dequeue()
 {
   front=-1;
   rear=-1;
}
void dequeue::add_at_end(int item)
{
  if(rear>=size-1)
  {
    cout<<"\n insertion is not possible,overflow!";
   }
  else
   {
      if(front==-1)
     {
           front++;
           rear++;
      }
    else
    {
      rear=rear+1;
       }
   a[rear]=item;
   cout<<"\n inserted item is"<<a[rear];
    }
}
void dequeue::add_at_beg(int item)
{
  if(front==-1)
   {
     front=0;
     a[++rear]=item;
     cout<<"\n inserted element is"<<item;
    }
   else if(front!=0)
    {
      a[--front]=item;
     cout<<"\n inserted element is"<<item;
    }
    else
    {
       cout<<"\n insertion is not possible,overflow!!";
     }
}
void dequeue::display()
{
   if(front==-1)
    {
       cout<<"dequeue is empty";
     }
    else
    {
      for(int i=front;i<=rear;i++)
     {
        cout<<a[i]<<"";
      }
    }
}
void dequeue::delete_from_front()
{
   if(front==-1)
   {
       cout<<"deletion is not possible,dequeue is empty";
       return;
    }
   else
   {
     cout<<"the deleted element is"<<a[front];
     if(front=rear)
     {
        front=rear=-1;
        return;
       }
      else
        front=front+1;
      }
}
void dequeue:: delete_from_rear()
{
   if(front==-1)
   {
       cout<<"deletion is not possible,dequeue is empty";
       return;
    }
   else
    {
       cout<<"the deleted element is"<<a[rear];
        if(front==rear)
      {
        front=rear=-1;
       }
       else
        rear=rear-1;
}
}
int main()
{
  int c,item;
   dequeue d1;
do
{
  cout<<"\n dequeue operation";
  cout<<"\n 1.insert at beginning";
  cout<<"\n 2.insert at end";
  cout<<"\n 3.display";
  cout<<"\n 4.deletion from front";
  cout<<"\n 5.deletion from rear";
  cout<<"\n 6.exit";
  cout<<"\n enter your choice";
  cin>>c;
  switch(c)
  {
    case 1:
           cout<<"enter the element to be inserted";
             cin>>item;
             d1.add_at_beg(item);
             break;
   
    case 2:
           cout<<"enter the element to be inserted";
             cin>>item;
             d1.add_at_end(item);
             break;
    case 3:
             d1.display();
             break;
    case 4:
            d1.delete_from_front();
             break;
    case 5:
            d1.delete_from_rear();
             break;
     
    default:
            cout<<"invalid choice";
                    break;
  }
} 
while(c!=7);
}































