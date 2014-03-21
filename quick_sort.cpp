//quick sort algorithm to sort N integers---- O(nlogn)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
using namespace std;
//partitioning over a random pivot x
int Partion(int array[],int p,int r)
{int x,i,j,a,temp;
srand(time(NULL));
a=random() % (r-p+2);
x=array[a];
//x=array[r];
i=p-1;
for (j=p;j<=r-1;j++)
	if(array[j]<=x)
		{i++;
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
		}
	temp=array[i+1];
	array[i+1]=array[r];
	array[r]=temp;
	return i+1;
}
//quick_sort algorithm
void Quick_sort(int array[], int p, int r)
	{int q;
	if (p<r)
		{q=Partion(array, p, r);
		Quick_sort(array, p, q-1);
		Quick_sort(array, q+1, r);
		}
	}
int main()
{struct timeval tv1, tv2;
char fname[20];
int n, *array;
cout<<"enter the file name"<<endl;
gets(fname);
gettimeofday(&tv1,NULL);
fstream fob(fname);
fob>>n;
array=new int[n];
for (int i=0;i<n;i++)
	{fob>>array[i];
	}
Quick_sort(array, 0, n-1);
for (int i=0;i<n;i++)
	cout<<array[i]<<endl;
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;}
