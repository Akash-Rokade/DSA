#include<iostream>
#include<cstring>
using namespace std;
	int main()
{
        char s1[50],s2[50];
        int temp=0,  i,j=0;  

 cout<<"enter string=";
   cin.getline(s1,50);
cout << "s1 = "<< s1 << endl;

	
	i=0;
 	j=strlen(s1)-1;
 	 while(i<j)
   {
   	temp=s1[i];
   	s1[i]=s1[j];
   	s1[j]=temp;
   	i++;	
  	 j--;
   }
 	cout<<"\nReverse string is: "<<s1;

	strcpy(s2,s1);
	 cout << "\n s1 = " << s1 << endl;
	cout<<"\n s2="<<s2;
strcmp(s1,s2);

	if(s1[i]==s2[j])

	cout<<"\nstring s1 and s2 are palindrome:";
	
		
	else
	
	cout<<"\n string s1 and s2 are not palindrome:";
	cout<<"\n Enter the string(Enter the first name)in uppercase:";
	cin.getline(s1,20);

	for(i=0;i<=strlen(s1);i++)
{
	if(s1[i]>=65 && s1[i]<=92)
		{
			s1[i]=s1[i]+32;
		}
}
	cout<<"\n The string in lowercase="<<s1;
return 0;
}


