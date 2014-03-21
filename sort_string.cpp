//program to sort LIST OF STRING using selection sort----O(n sqaue)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include <string.h>
using namespace std;
//selection sort algorithm
void selection_sort(char a[100000][20], int n)
	{int loc;
	char temp[20];
	for (int i=0;i<n-1;i++)
		{loc=i;
		for (int j=i+1;j<n;j++)
			if (strcmp(a[loc],a[j]) >0)
				loc=j;
			strcpy(temp, a[i]);
			strcpy(a[i], a[loc]);
			strcpy(a[loc], temp);
		}
	}		
int main()
{struct timeval tv1, tv2;
char fname[20];
int n,cflag=0;
char array[100000][20];
cout<<"enter the file name";
gets(fname);
gettimeofday(&tv1,NULL);
fstream fob(fname);
fob>>n;
for (int i=0;i<n;i++)
	{fob>>array[i];
	for (int j=0;j<strlen(array[i]);j++)
			if (isupper(array[i][j]) || (!isalpha(array[i][j])))
				{cout<<"ERROR: THE STRING IS NOT IN THE PRESCRIBED FORMAT"<<endl; //error checking
				cflag=1;
				break;
				}
	}
if(cflag==0)
{selection_sort(array, n);
for (int i=0;i<n;i++)
	cout<<array[i]<<" "<<endl;}
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;
}
