#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
	struct node
		{int key;
		node *next;
		};
	void push(node* &stk,int element)
		{node *ptr=new node;
		if (ptr==NULL)
			cout<<"ALLOCATION ERROR"<<endl;
		else
			{if (stk==NULL)
				ptr->next=NULL;
			else
				ptr->next= stk;
			stk=ptr;
			ptr->key=element;
			}
		}
	void pop(node *&stk)
		{if (stk==NULL)
			cout<<"EMPTY"<<endl;
		else
			{node *ptr=new node;
			ptr=stk;
			stk=stk->next;
			cout<<ptr->key<<endl;
			delete ptr;
			}
		}
	void peek(node *&stk)
		{if (stk!=NULL)
			cout<<stk->key<<endl;
		else
			cout<<"EMPTY!"<<endl;
		}
	void show(node *&stk)
		{node *ptr=new node;
		ptr=stk;
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
		node *stk=new node;
		stk=NULL;
		cout<<"enter the file name";
		gets(fname);
		ifstream fob(fname);
		fob>>j;
		do
			{switch (j)
				{case 1: fob>>j;
						push(stk,j);
						break;
				case 2: pop(stk);
						break;
				case 3: peek(stk);
						break;
				case 4: show(stk);
						break;
				}
		fob>>j;
		}while (j!=0);
		}
		
		
