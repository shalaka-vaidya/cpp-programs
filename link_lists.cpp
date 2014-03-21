#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
	struct node1
		{int key;
		node1 *next;
		};
	struct node
		{int key;
		node *next;
		node *prev;
		};
	node *head=NULL;
	node *last=NULL;
	node1 *head1=NULL;
	node1 *last1=NULL;
	void push(int element)
		{node *ptr=new node;
		if (ptr==NULL)
			cout<<"ALLOCATION ERROR"<<endl;
		else
			{if (head==NULL)
				{head=ptr;
				last=ptr;
				head->prev=NULL;
				}
			else
				{last->next= ptr;
				ptr->prev=last;
				last=ptr;
				}
			last->next=NULL;
			ptr->key=element;
			}
		}
	void push1(int element)
		{node1 *ptr=new node1;
		if (ptr==NULL)
			cout<<"ALLOCATION ERROR"<<endl;
		else
			{if (head1==NULL)
				{head1=ptr;
				last1=ptr;
				}
			else
				{last1->next= ptr;
				last1=ptr;
				}
			last1->next=NULL;
			ptr->key=element;
			}
		}
	void show()
		{node *ptr=new node;
		ptr=head;
		if (ptr==NULL)
			cout<<"EMPTY\n";
		else
			{
			while(ptr!=NULL)
			{cout<<ptr->prev<<" ";
				cout<<ptr->key<<" ";
				cout<<ptr->next<<" ";
				ptr=ptr->next;
				cout<<endl;
				}
			}
		}
	void show1()
		{node1 *ptr=new node1;
		ptr=head1;
		if (ptr==NULL)
			cout<<"EMPTY\n";
		else
			{
			while(ptr!=NULL)
			{	cout<<ptr->key<<" ";
				cout<<ptr->next<<" ";
				ptr=ptr->next;
				cout<<endl;
				}
			}
		}
	void delete_node(int n)
		{//cout<<n<<endl;
		if (n%2==0)
			{node *ptr=new node;
			ptr=head;
			while ((ptr->next)->next!=NULL)
				{node *temp=new node;
				temp= ptr->next;
				ptr->next=temp->next;
				(temp->next)->prev=ptr;
				ptr=ptr->next;
				//cout<<ptr->key<<endl;
				delete temp;
				}
			ptr->next=NULL;
			}
		else
			{node *ptr=new node;
			ptr=head;
			while ((ptr->next)!=NULL)
				{node *temp=new node;
				temp= ptr->next;
				ptr->next=temp->next;
				(temp->next)->prev=ptr;
				ptr=ptr->next;
				//cout<<(ptr->key)<<endl;
				delete temp;
				}
			//ptr->next=NULL;
			}
		}
	void search1()
		{int count=0;
		node1 *ptr=new node1;
		ptr=head1;
		while(ptr!=NULL)
			{if (ptr->key > 10)
				count++;
			ptr=ptr->next;
			}
		cout<<"COUNT= "<<count<<endl;
		}
	int main()
		{int j,n,i;
		char fname1[20];
		cout<<"enter the file name";
		gets(fname1);
		ifstream fob(fname1);
		fob>>n;
		i=n;
		do
			{fob>>j;
			push1(j);
			push(j);
			n--;
			}while (n!=0);
		cout<<"SINGLY LINKED LIST"<<endl;
		//show1();
		search1();
		show1();
		cout<<"DOUBLY LINKED LIST"<<endl;
		//show();
		delete_node(i);
		show();
		}
