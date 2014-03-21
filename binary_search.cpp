//the program to find the number using binary search -----O(logn)
#include <iostream>
#include <fstream>
#include <time.h>
#include <sys/time.h>
using namespace std;
//binary search algorithm
int bin_search(int a[] , int n, int no)
	{int mid, flag=-1, start=0, final=n-1;
		while (start<=final && flag==-1)
			{mid=(final+start)/2;
			if (a[mid]==no)
				{flag=mid;
				}
			else if(a[mid]<no)
				{start=mid+1;
				}
			else
				{final=mid-1;
				}
			}
		return flag;
	}
int main()
{struct timeval tv1, tv2;
char fname[20];
int n, *array, no,ans;
cout<<"enter the file name"<<endl;
gets(fname);
gettimeofday(&tv1,NULL);
fstream fob(fname);
fob>>n;
array=new int[n];
for (int i=0;i<n;i++)
	{fob>>array[i];
	}
fob>>no;
ans=bin_search(array, n, no);
cout<<ans<<endl;
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;
}
