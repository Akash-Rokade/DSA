#include<iostream>

using namespace std;

void accept(int a[], int n);
void display(int a[], int n);
void bsort(int a[],int n);
int bin_search(int a[],int i,int j,int key);
int main()
{
	int a[10],mid,i,n,j,key,result;

	cout<<"Enter no of students ";
	cin>>n;
         accept(a,n);
          display(a,n);
          bsort( a, n);
           cout<<"Enter the element to be searched";
        cin>>key;
       
      result=bin_search(a,0,n-1,key);
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
  cout<<"sorted array is\n";
for(i=0;i<n;i++)
{
  cout<<""<<a[i]<<"\n";
}
}
int bin_search(int a[],int i,int j,int key)
{
  int mid;
  if(i>j)
    return -1;
  mid=(i+j)/2;
  if(key>a[mid])
   bin_search(a,mid+1,j,key);
 else if(key<a[mid])
  bin_search(a,mid-1,i,key);
else
 return mid;
}

      




















