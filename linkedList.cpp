#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct node
{int info;
struct node *next;
}*start, *temp;

void insert_beg(int);
void insert_end(int);
void insert_spe(int,int);
void delete_beg();
void delete_end();
void delete_spe(int);
void display();

int main()
{//clrscr();
 start=NULL;
 int item,choice,location,element,position;
 cout<<endl<<"Insert & Delete operation in linked list by-Tarun Rawat\n";
 again:
 cout<<"\n1.Insert at beg of linked list\t";
 cout<<"2.Insert at end of linked list\n";
 cout<<"3.Insert at specific location\t";
 cout<<"4.Delete from beginning of List \n5.delete from end of the list \t6.Delete from specific location of List\n7.Display linked list\t8.Exit\n";
 cout<<"Enter choice : ";
 cin>>choice;
 switch(choice)
 {case 1:cout<<"Enter item to insert : ";
       cin>>item;
       insert_beg(item);
       goto again;
 case 2:cout<<"Enter item to insert : ";
       cin>>item;
       insert_end(item);
       goto again;
 case 3:cout<<"Enter location to insert : ";
       cin>>location;
       cout<<"Enter item to insert : ";
       cin>>item;
       insert_spe(item,location);
       goto again;
 case 4:delete_beg();
       goto again;
 case 5:delete_end();
       goto again;
 case 6:cout<<"Enter the location to delete : ";
       cin>>location;
       delete_spe(location);
       goto again;
 case 7:cout<<"\nInserted item = ";
       display();
       goto again;
 case 8 :cout<<"\nTHANK YOU";
 default:break;
 }
 getch();
}

void insert_beg(int item)
{temp=(node*)malloc(sizeof(node));
temp->info=item;
temp->next=start;
start=temp;
}

void insert_end(int item)
{temp=(node*)malloc(sizeof(node));
temp->info=item;
temp->next=NULL;
node* current=start;
while(current->next!=NULL)
    {current=current->next;
    }
current->next=temp;
}

void insert_spe(int item,int location)
{temp=(node*)malloc(sizeof(node));
temp->info=item;
node* current=start;
int count=1;
while (count <location-1)
    {current=current->next;
     count=count+1;
    }
temp->next=current->next;
current->next=temp;
}

void delete_beg()
{temp=start;
start=start->next;
free(temp);
}

void delete_end()
{temp=start;
node* current;
while(temp->next!=NULL)
{
current=temp;
temp=temp->next;
}
current->next=NULL;
free(temp);
}

void delete_spe(int location)
{node* current;
temp=start;
int count=1;
while(count<=location-1)
{current=temp;
temp=temp->next;
count=count+1;
}
current->next=temp->next;
free(temp);
}

void display()
{temp=start;
while(temp!=NULL)
{cout<<temp->info<<" ";
temp=temp->next;
}
cout<<"\n";

}
