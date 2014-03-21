//sorting a REAL number array using insertion sort---- O(n square)
#include <iostream>
#include <fstream>
#include <time.h>
#include <sys/time.h>
using namespace std;
//insertion sort algorithm
void inser_sort(float a[], int n)
	{int loc=-1; 
	float temp;
	for (int i=0;i<n;i++)
		{temp=a[i];
		loc=i-1;
		while (a[loc]>temp && loc>=0)
			{a[loc+1]=a[loc];
			loc--;
			}
		a[loc+1]=temp;
		}
	}
int main()
{struct timeval tv1, tv2;
char fname[20];
int n, no;
float  *array;
cout<<"enter the file name"<<endl;
gets(fname);
gettimeofday(&tv1,NULL);
fstream fob(fname);
fob>>n;
array=new float[n];
for (int i=0;i<n;i++)
	{fob>>array[i];
	}
fob>>no;
inser_sort(array, n);
for (int i=0;i<n;i++)
	cout<<array[i]<<endl;
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;
}
