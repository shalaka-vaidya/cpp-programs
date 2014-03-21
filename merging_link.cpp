#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
struct node
{int key;
node *link;
};

void inserting(int number , node* (&sentinel), node* (&last))
	{if (sentinel==NULL)
		{node *ptr= new node;
		ptr->key=number;
		ptr->link=NULL;
		sentinel=ptr;
		last=ptr;
		}
	else
		{node *ptr= new node;
		ptr->key=number;
		ptr->link=NULL;
		last->link=ptr;
		last=ptr;
		}
	}
node* q1_adv(char fname[])
{int k;
node *sentinel=NULL;
node *last=NULL;
ifstream nob(fname, ios::binary);
	while(nob.read ((char*)&k, sizeof(k)))
		{
		inserting(k, sentinel, last);
		}
	last->link=sentinel;
	nob.close();
	return sentinel;
}
node* merging(node *(&sentinel), node *(&sentinel1))
	{node *ptr= new node;
	node *ptr1= new node;
	node *temp=new node;
	node *temp1=new node;
	int flag=0;
	ptr=NULL;
	ptr1=NULL;
	ptr=sentinel;
	ptr1=sentinel1;
	if (sentinel != NULL and sentinel1 != NULL)
	{do
		{temp=ptr->link;
		temp1=ptr1->link;
		ptr->link=ptr1;
		if (temp!=sentinel)
			{ptr1->link=temp;
			ptr1=temp1;
			}
		else
			{ptr1->link=temp1;
		}
		ptr=temp;
		//cout<<ptr<<"\t"<<ptr->key<<"\t"<<ptr->link<<endl;
		//cout<<ptr1<<"\t"<<ptr1->key<<"\t"<<ptr1->link<<endl;
		flag=1;
		}while (ptr!= sentinel and ptr1!= sentinel1);
	}
	if (ptr!=sentinel)
		{flag=1;
		do
			{//cout<<ptr<<"\t"<<ptr->key<<"\t"<<ptr->link<<endl;
			ptr=ptr->link;
			}while(ptr!=sentinel);
		}
	else if(ptr1!=sentinel1)
		{node *hi=new node;
		flag=0;
		do
			{//cout<<ptr1<<"\t"<<ptr1->key<<"\t"<<ptr1->link<<endl;
			hi=ptr1;
			ptr1=ptr1->link;
			}while(ptr1!=sentinel1);
		hi->link=sentinel;
		}
if (flag==1)
	return (sentinel);
else
	return (sentinel1);
}
void q3_adv (char fname1[], node* (&sentinel))
{int k;
ofstream nob(fname1, ios::binary);
node *ptr=new node;
ptr=sentinel;
if (sentinel !=NULL)
	{do
		{//cout<<ptr<<"\t"<<ptr->key<<"\t"<<ptr->link<<endl;
		k=ptr->key;
		nob.write ((char*)&k, sizeof (k));
		ptr=ptr->link;
		}while(ptr!=sentinel);
	nob.close();
	}
else 
	cout<<"empty"<<endl;
}
void q4_adv(char fname[], char fname1[])
{int k;
ifstream fob(fname, ios::binary);
ofstream nob(fname1);
	while(fob.read ((char*)&k, sizeof(k)))
		{
		nob<<k<<endl;
		}

 
	fob.close();
	nob.close();
}
void q5_adv()
{char fname[20], fname1[20], fname2[20];
node *pointer1=new node;
pointer1=NULL;
node *pointer2=new node;
pointer2=NULL;
node *merged=new node;
merged=NULL;
cout<<"enter the two filenames(binary format)";
gets(fname);
gets(fname1);
cout<<"enter the filename(textformat)(merged)";
gets(fname2);
pointer1=q1_adv(fname);
pointer2=q1_adv(fname1);
merged=merging(pointer1, pointer2);
q3_adv("thirdstring.temp", merged);
q4_adv("thirdstring.temp", fname2);
}







int main()
{q5_adv();
}
