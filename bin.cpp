#include<iostream>
using namespace std;

void accept(int a[], int n);
void display(int a[], int n);
void bsort(int a[],int n);
int bin_search(int a[],int n,int key);
int main()
{
	int a[20],n,choice,i,j,key,result,index;
	cout<<"Enter no of students ";
	cin>>n;
         accept(a,n);
          display(a,n);
          bsort( a, n);
          cout<<"enter the element to be searched";
          cin>>key;
       
       
      result=bin_search(a,n,key);
       if(result==-1)
	cout<<"element not found";
	else
		cout<<"element is found at position"<<result;

}
void accept(int a[], int n)
{
	cout<<"enter percentage of students";
    for(int i=0;i<n;i++)
{
  cin>>a[i];
}
	
}

void display(int a[], int n)
{
  	cout<<"enter percentage of students";
    for(int i=0;i<n;i++)
{
  cout<<a[i]<<"\n";
} 
   
}

void bsort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
{
  
for(j=0;j<n-i;j++)
{
  if(a[j]>a[j+1])
   {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
   }
}
}
  cout<<"sorted array \n";
for(i=0;i<n;i++)
{
  cout<<""<<a[i]<<"\n";
}
}
int bin_search(int a[],int n,int key)
{
  int i=0, j=n-1, mid;
	while(i<=j)
	{
		mid = (i+j)/2;
		if(key>a[mid])
			i = mid+1;	
		else if(key<a[mid])
			j = mid-1;		
		else
			return mid;
	}
	return -1;
}
      





















