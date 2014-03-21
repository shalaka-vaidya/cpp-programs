#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int stack[100] , c;
	void push(int &front, int &rear,int element)
		{if ((rear==(c-1) and front==0) or rear==front-1)
			cout<<"OVERFLOW"<<endl;
		else
			{if (front==-1 && rear==-1)
				front=rear=0;
			else
				rear=(rear+1)%c;
			stack[rear]=element;
			}
		}
	void pop(int &front,int &rear)
		{if (front==-1)
			cout<<"UNDERFLOW"<<endl;
		else
			{cout<<stack[front]<<endl;
			if (front==rear)
				front=rear=-1;
			else
				front=(front+1)%c;
			}
		}
	void peek(int &front)
		{if (front==-1)
			cout<<"EMPTY!"<<endl;
		else
			cout<<stack[front]<<endl;
		}
	void show(int &front,int &rear)
		{if (front==-1)
			cout<<"EMPTY!"<<endl;
		else
			{int p;
			p=front;
			while (p!=(rear+1)%c)
			{cout<<stack[p]<<" ";
			p=(p+1)%c;
			}
			//for (int i=front;i<=rear;i++)
			//	cout<<stack[i]<<" ";
			cout<<endl;
			}
		}
	int main()
		{int j,front, rear;
		char fname[20];
		front=-1;
		rear=-1;
		cout<<"enter the file name";
		gets(fname);
		ifstream fob(fname);
		fob>>c;
		fob>>j;
		do
			{switch (j)
				{case 1: fob>>j;
						push(front,rear,j);
						break;
				case 2: pop(front,rear);
						break;
				case 3: peek(front);
						break;
				case 4: show(front, rear);
						break;
				}
		fob>>j;
		}while (j!=0);
		}
