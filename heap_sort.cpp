//heapsort n integers-----O(nlogn) space complexity=THEETHA(1)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
using namespace std;
int parent(int i)
{return i/2;}
int left(int i)
{return (2*i);}
int right (int i)
{return (2*i+1);}
//converts the array to heap
void heapify(int array[], int i, int n)
	{int l=left(i);
	int r=right(i);
	int largest,temp;
	if (l<n && array[l]>array[i])
		largest=l;
	else
		largest=i;
	if (r<n && array[r]>array[largest])
		largest=r;
	if (largest !=i)
		{temp=array[i];
		array[i]=array[largest];
		array[largest]=temp;
		heapify(array,largest,n);
		}
	}
//converts given array to heap
void build(int array[], int n)
{for (int i=n/2;i>=0;i--)
	heapify(array,i,n);
}
//heap sort algorithm
void heap_sort(int array[],int n)
{int temp;
build(array, n);
for (int i=n-1;i>=1;i--)
	{temp=array[0];
	array[0]=array[i];
	array[i]=temp;
	n--;
	heapify(array, 0, n);
	}
}
int main()
{struct timeval tv1, tv2;
char fname[20];
int n,array[50];
cout<<"enter the file name"<<endl;
gets(fname);
gettimeofday(&tv1,NULL);
ifstream fob(fname);
fob>>n;
for (int i=0;i<n;i++)
	{fob>>array[i];
	}
heap_sort(array,n);
for (int i=0;i<n;i++)
	{cout<<array[i]<<endl;
	}
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;}
