//radix sort using COUNTSORT for HEXADECIMAL numbers------- O(n*b) n=number of elements b=bytes of each element(8 in this case)
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
int cflag=0;//to cheack for inavlid hexa decimal number
int key(char n) //coversion to store it into count array
	{switch(n)
		{case '0': return 0;
					break;
		case '1': return 1;
				break;
		case '2': return 2;
				break;
		case '3': return 3;
				break;
		case '4': return 4;
				break;
		case '5': return 5;
				break;
		case '6': return 6;
				break;
		case '7': return 7;
				break;
		case '8': return 8;
				break;
		case '9': return 9;
				break;
		case 'A': return 10;
				break;
		case 'B': return 11;
				break;
		case 'C': return 12;
				break;
		case 'D': return 13;
				break;
		case 'E': return 14;
				break;
		case 'F': return 15;
				break;
		default : cout<<"error:HEXADECIMAL INVALID"<<endl;
				cflag=1;
				return '\0';
					break;
			}
	}
int main()
{struct timeval tv1, tv2;
int n,oldcount;
char fname[10],array[20][9],op[20][9], w[9],zerostr[10];
cout<<"enter the file name";
gets(fname);
gettimeofday(&tv1,NULL);
ifstream fob(fname);
	fob>>n;
for (int i=0;i<n;i++)//storing every number after converting to hexadecimal
	{fob>>w;
	switch (strlen(w))
		{case 1:strcpy(zerostr,"0000000");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		case 2:strcpy(zerostr,"000000");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		case 3:strcpy(zerostr,"00000");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		case 4:strcpy(zerostr,"0000");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		case 5:strcpy(zerostr,"000");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		case 6:strcpy(zerostr,"00");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		case 7:strcpy(zerostr,"0");
				strcpy(array[i],strcat(zerostr,w));
				array[i][8]='\0';
				break;
		default :strcpy(array[i],w);
				array[i][8]='\0';
				break;
		}
	}
//each bit from LSB is checked and stored into the array op
{for (int j=7;j>=0;j--)	
	{if (cflag==0)
		{int count[16]={0};
		for (int i=0;i<n;i++)
			count[key(array[i][j])]+=1;
		int total=0;
		for (int i=0;i<16;i++)
			{oldcount=count[i];
			count[i]=total;
			total +=oldcount;
			}
		for (int i=0;i<n;i++)
			{strcpy(op[count[key(array[i][j])]],array[i]);
			count[key(array[i][j])] +=1;
			}
		for (int i=0;i<n;i++)//for the next iteration array=previous op
			strcpy(array[i],op[i]);
	}
	}
}
if (cflag==0)
for (int i=0;i<n;i++)
		cout<<op[i]<< " "<<endl;
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;}
