#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
struct node
	{int key;
	int priority;
	node *next;
	node *prev;
	};
node *head=NULL;
node *last=NULL;
void queue_insert(int k, int prio)
{node *temp=new node;
if (head==NULL and last==NULL)
	{head=temp;
	last=temp;
	temp->prev=NULL;
	temp->next=NULL;
	}
else
	{node *ptr=new node;
	ptr=head;
	do
		{if ((ptr->priority) > prio)
			{//cout<<"out"<<endl;
			break;
			}
		else
			ptr=ptr->next;
		}while (ptr!=NULL);
	if (ptr==NULL)
		{//cout<<"haha";
		last->next=temp;
		temp->prev=last;
		last=temp;
		}
	else if(ptr==head)
		{temp->next=head;
		head->prev=temp;
		head=temp;
		}
	else
	{temp->prev=ptr->prev;
	temp->next=ptr;
	(temp->prev)->next=temp;
	ptr->prev=temp;
	}
}
temp->key=k;
temp->priority=prio;
	}
	
void show()
		{node *ptr=new node;
		ptr=head;
		if (ptr==NULL)
			cout<<"EMPTY\n";
		else
			{//cout<<"show"<<endl;
			while(ptr!=NULL)
			{cout<<ptr->prev<<" ";
				cout<<ptr->key<<" ";
				cout<<ptr->priority<<" ";
				cout<<ptr->next<<" ";
				ptr=ptr->next;
				cout<<endl;
				}
			}
		}
		
void queue_remove()
	{node *ptr=head;
	head=ptr->next;
	if (head==NULL)
		cout<<"EMPTY\n";
	else
		{head->prev=NULL;
		cout<<ptr->key<<" ("<<ptr->priority<<") ";
		cout<<endl;
		delete ptr;
		}
	}
void queue_peek()
	{node *ptr=head;
	if (head==NULL)
		cout<<"EMPTY\n";
	else
		{cout<<ptr->key<<" ("<<ptr->priority<<") ";
		cout<<endl;
		}
	}
	
void queue_increase_priority(int k, int prio)
{node *ptr=new node;
//node *temp=new node;
ptr=head;
do
{if (ptr->key==k)
	break;
else
	ptr=ptr->next;
}while (ptr!=NULL);
if (ptr==NULL)
	cout<<"not found"<<endl;
else
	{if (ptr->priority < prio)
		cout<<"Higher priority"<<endl;
	else
		{if ((ptr==head) and (ptr==last))
			{head=NULL;
			last=NULL;
			}
		else if (ptr==head)
			{head=ptr->next;
			}
		else if (ptr==last)
			{last=ptr->prev;
			}
		else
			{(ptr->prev)->next=ptr->next;
			(ptr->next)->prev=ptr->prev;
			}
		queue_insert(k, prio);
		}	
	}
}

int main()
{int op,k,prio;
//node *temp=NULL;
char fname[20];
cout<<"enter the file name"<<endl;
gets(fname);
ifstream fob(fname);
fob>>op;
//cout<<"enter op"<<endl;
//cin>>op;
	while (op!=0)
		{switch(op)
			{case 1: //cout<<"enter key and priority"<<endl;
					 //cin>>k>>prio;
					 fob>>k;
					 fob>>prio;
					 queue_insert(k, prio);
					 //show();
					 break;
			case 2: queue_remove();
					//show();
					break;
			case 3:queue_peek();
					break;
			case 4: fob>>k;
					fob>>prio;
					//cout<<"enter key and priority"<<endl;
					//cin>>k>>prio;
					queue_increase_priority(k, prio);
					break;
			}
		fob>>op;
		//cout<<"enter op"<<endl;
		//cin>>op;
		}
}
