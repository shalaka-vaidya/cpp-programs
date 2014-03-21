//program to merge sort n integers------- O(nlogn)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
using namespace std;
//int a[50];
//merge algorithm
void merge(int a[],int low,int mid,int high)
{int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;
 while((h<=mid)&&(j<=high))
 {if(a[h]<=a[j])
  {b[i]=a[h];
   h++;
  }
  else
  {b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {for(k=j;k<=high;k++)
  {b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}
//merge_sort algorithm
void merge_sort(int a[],int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(a,low,mid);
  merge_sort(a,mid+1,high);
  merge(a,low,mid,high);
 }
}
int main()
{struct timeval tv1, tv2;
char fname[20];
int n, *a;
cout<<"enter the file name";
gets(fname);
gettimeofday(&tv1,NULL);
ifstream fob(fname);
fob>>n;
a=new int [n];
for (int i=0;i<n;i++)
	{fob>>a[i];
	}
merge_sort(a,0,n-1);
for (int i=0;i<n;i++)
	{cout<<a[i]<<endl;
	}
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;}
