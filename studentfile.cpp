#include<iostream>
#include<fstream>

using namespace std;
class stud{
struct student{
char name[30];
int rno;
char div;
char address[20];
}rec,record;

public:
    void create(char f[]);
    void display(char f[]);
    void update(char f[]);
    void delete1(char f);
    void append(char f[]);
    void search1(char f[]);


};
void stud::create(char f[])
{
    char ch='y';
    fstream seqfile;
    seqfile.open(f,ios::in|ios::out|ios::binary);
    do{
        cout<<"\nEnter name ";
        cin>>record.name;
        cout<<"\nEnter roll number ";
        cin>>record.rno;
        cout<<"\nEnter division ";
        cin>>record.div;
        cout<<"Enter address ";
        cin>>record.address;

        seqfile.write((char*)&record,sizeof(record));
        cout<<"Do you want to add more records(y for yes)!!!!\n";
        cin>>ch;
    }
    while(ch=='y');
    seqfile.close();

}
void stud::display(char f[])
                      {
                          fstream seqfile;
                          int n,m,i;
                          seqfile.open(f,ios::in|ios::out|ios::binary);
                          seqfile.seekg(0,ios::beg);
                          cout<<"The content of file are \n";
                          while(seqfile.read((char*)&record,sizeof(record)));
                          {

                              if(record.rno!=-1)
                              {
                                  cout<<"\nName "<<record.name;
                                  cout<<"\n Roll number "<<record.rno;
                                  cout<<"\nDivision "<<record.div;
                                  cout<<"\nAddress "<<record.address;
                              }
                          }
                      }

int main()
{
    stud s;
    char ans='y';
    int ch,key;
    char filename[20];
    cout<<"\nplease enter file name ";
    cin>>filename;
    do{
        cout<<"\nMenu\n1.create\n2.display\n3.update\n4.delete\n5.append\n6.search\n(0 for exit)\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            s.create(filename);
            break;
            case 2:
                s.display(filename);
                break;
        case 0:
            return 0;
        }

    }
while(ans=='y');
}
