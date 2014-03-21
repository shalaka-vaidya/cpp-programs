#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int stack[100] , c;
	void push(int &stk,int element)
		{if (stk==(c-1))
			cout<<"OVERFLOW"<<endl;
		else
			{stack[++stk]=element;
			}
		}
	void pop(int &stk)
		{if (stk==-1)
			cout<<"UNDERFLOW"<<endl;
		else
			{cout<<stack[stk]<<endl;
			--stk;
			}
		}
	void peek(int &stk)
		{if (stk==-1)
			cout<<"EMPTY!"<<endl;
		else
			cout<<stack[stk]<<endl;
		}
	void show(int &stk)
		{if (stk==-1)
			cout<<"EMPTY!"<<endl;
		else
			{for (int i=stk;i>=0;i--)
				cout<<stack[i]<<" ";
			cout<<endl;
			}
		}
	int main()
		{int j,stk;
		char fname[20];
		stk=-1;
		cout<<"enter the file name";
		gets(fname);
		ifstream fob(fname);
		fob>>c;
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
