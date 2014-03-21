//find lexicographically smallest string from list of string ,program works with THEETHA N time
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sys/time.h>
#include <ctype.h>
#include <time.h>
#include <cstdlib>
//#include <usr/include/c++/stdlib>
using namespace std;
int Partion(char los[][7],int p,int r)
{int i,j,a;
char x[7],temp[7];
srand(time(NULL));
a=random() % (r-p+1);
strcpy(x,los[a]);
strcpy(x,los[r]);
i=p-1;
for (j=p;j<=r-1;j++)
	if (strcmp(los[j],x)<=0)
		{i++;
		strcpy(temp,los[i]);
		strcpy(los[i],los[j]);
		strcpy(los[j],temp);
		}
	strcpy(temp,los[i+1]);
	strcpy(los[i+1],los[r]);
	strcpy(los[r],temp);
	return i+1;
}
char* selecti(char los[][7],int p, int r, int i)
	{int q,k;
	if (p==r)
		return los[p];
	q= Partion(los, p, r);
	k= q-p+1;
	if (i==k)
		return los[q];
	else if (i<k)
		selecti (los, p, q-1, i);
	else
		selecti (los, q+1, r, i-k);
	}
/*void Quick_sort(char los[][7], int p, int r)
	{int q;
	if (p<r)
		{q=Partion(los, p, r);
		Quick_sort(los, p, q-1);
		Quick_sort(los, q+1, r);
		}
	}
	*/

int main()
{int k=0,cflag=0,selectno;
struct timeval tv1, tv2;
char los[100000][7],w[20],fname[20];
string smallest;
cout<<"enter the file name"<<endl;
gets(fname);
gettimeofday(&tv1,NULL);
ifstream fob(fname);
fob>>selectno;
while (!fob.eof() && cflag==0)		//THETHA N time
	{fob>>w;
	if(strlen(w)>7)
		{cout<<"ERROR:LENGTH EXCEEDED"<<endl;
		cflag=1;
		break;}
	else
		{for (int j=0;j<strlen(w);j++)
			if (isupper(w[j]) || (!isalpha(w[j])))
				{cout<<"ERROR: THE STRING IS NOT IN THE PRESCRIBED FORMAT"<<endl;
				cflag=1;
				break;
				}
		if(cflag==0)
		strcpy(los[k++],w);
		}
	}
if(cflag==0)
cout<<selecti(los,0,k-1,selectno)<<endl;
//cout<<smallest<<endl;
//Quick_sort(los,0, k-2);
//for (int i=0;i<k;i++)
	//cout<<los[i]<<endl;
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;
}
