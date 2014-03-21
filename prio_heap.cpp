//heapsort n integers-----O(nlogn) space complexity=THEETHA(1)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
using namespace std;
int size=0;
struct element
{int ele;
int priority;
};
int parent(int i)
{return i/2;}
int left(int i)
{return (2*i);}
int right (int i)
{return (2*i+1);}
//converts the array to heap
void heapify(element array[], int i)
	{int l=left(i);
	int r=right(i);
	int largest;
	element temp;
	if (l<size && array[l].priority<array[i].priority)
		largest=l;
	else
		largest=i;
	if (r<size && array[r].priority<array[largest].priority)
		largest=r;
	if (largest !=i)
		{temp=array[i];
		array[i]=array[largest];
		array[largest]=temp;
		heapify(array,largest);
		}
	}
//converts given array to heap
void build(element array[])
{for (int i=size/2;i>=0;i--)
	heapify(array,i);
}
void heap_insert(element array[],element ele)
	{array[size++]=ele;
	build(array);
	}
void heap_remove(element array[])
	{if (size==0)
		cout<<"empty";
	else
		{cout<<array[0].ele<<" ("<<array[0].priority<<" )"<<endl;
		array[0]=array[size-1];
		size--;
		heapify(array, 0);
		}
	}
void heap_peek(element array[])
	{if (size==0)
		cout<<"empty"<<endl;
	else
		{build(array);
		cout<<array[0].ele<<" ("<<array[0].priority<<" )"<<endl;
		}
	}
void heap_increase_priority (element array[], int data , int newpwr)
	{
		for (int i=0;i<size;i++)
			if (array[i].ele==data)
				{if (array[i].priority<newpwr)
					cout<<"new priority is less than original priority"<<endl;
				else
					{array[i].priority=newpwr;
					break;
					}
				}
		build(array);
	}
int main()
{int op,key,prio;
element temp;
char fname[20];
element array[1000];
cout<<"enter the file name"<<endl;
gets(fname);
ifstream fob(fname);
fob>>op;
//cout<<"enter op"<<endl;
//cin>>op;
	while (op!=0)
		{switch(op)
			{case 1: fob>>key;
					 fob>>prio;
					 //cout<<"enter key and priority"<<endl;
					 //cin>>key>>prio;
					 temp.ele=key;
					 temp.priority=prio;
					 heap_insert(array, temp);
					 break;
			case 2: heap_remove(array);
					break;
			case 3: heap_peek(array);
					break;
			case 4: fob>>key;
					fob>>prio;
					//cout<<"enter key and priority"<<endl;
					 //cin>>key>>prio;
					heap_increase_priority(array, key, prio);
					break;
			}
		fob>>op;
	//	cout<<"enter op"<<endl;
		//cin>>op;
		}
}
					 
					 

