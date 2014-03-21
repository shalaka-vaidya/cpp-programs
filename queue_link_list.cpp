#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
	struct node
		{int key;
		node *next;
		};
void push(node* &rear,node *&front,int element)
		{node *ptr=new node;
		if (ptr==NULL)
			cout<<"ALLOCATION ERROR"<<endl;
		else
			{if (rear==NULL)
				front=ptr;
			else
				rear->next= ptr;
			ptr->key=element;
			ptr->next=NULL;
			rear=ptr;
			}
		}
	void pop(node *&front)
		{if (front==NULL)
			cout<<"EMPTY"<<endl;
		else
			{node *ptr=new node;
			ptr=front;
			front=front->next;
			cout<<ptr->key<<endl;
			delete ptr;
			}
		}
	void peek(node *&front)
		{if (front!=NULL)
			cout<<front->key<<endl;
		else
			cout<<"EMPTY!"<<endl;
		}
	void show(node *&front, node *&rear)
		{node *ptr=new node;
		ptr=front;
		if (ptr==NULL)
			cout<<"EMPTY STACK\n";
		else
			{
			do {
				cout<<ptr->key<<" ";
				ptr=ptr->next;
				}while(ptr!=NULL);
			cout<<endl;
			}
		}
	int main()
		{int j;
		char fname[20];
		node *front=new node;
		front=NULL;
		node *rear=new node;
		rear=NULL;
		cout<<"enter the file name";
		gets(fname);
		ifstream fob(fname);
		fob>>j;
		do
			{switch (j)
				{case 1: fob>>j;
						push(rear,front,j);
						break;
				case 2: pop(front);
						break;
				case 3: peek(front);
						break;
				case 4: show(front, rear);
						break;
				}
		fob>>j;
		}while (j!=0);
		}
