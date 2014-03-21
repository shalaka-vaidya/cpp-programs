//find the median of n integers-----0(n)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include <math.h>
using namespace std;
void inser_sort(int a[], int beg, int end)
	{int n=end-beg;
		int loc=-1; 
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
//partitioning the array from p to r-----O(n)
int Partion(int array[],int p,int r,int part)
{int x,i,j,a,temp;
//srand(time(NULL));
//a=random() % (r-p+1);
x=part;
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
//selects ith element from the list------O(n/2)
/*int selecti(int array[],int p, int r, int i)
	{int q,k;
	if (p==r)
		return array[p];
	q= Partion(array, p, r);
	k= q-p+1;
	if (i==k)
		return array[q];
	else if (i<k)
		selecti (array, p, q-1, i);
	else
		selecti (array, q+1, r, i-k);
	}
	*/
int selection(int tempArray[],int beg, int end){
	    int length = end-beg+1;
	    if(length < 26){                     //as long as there are 5 groups of 5, will continue to divide and conquer
	        inser_sort(tempArray,beg,end);   //insert sort small groups as suggested by Cormen et al.
        return ((length/2)+beg);
	    }
	    else{
	        int g = length/5,i;                 //1. obtain number of sub groups
	        for(i=0;i<g;i++)
	            inser_sort(tempArray, (beg + (i*5)), (beg + (i*5) + 4)); //2. insert sort each group of 5 O(1)
	        int arrayOfMedians[g];
	        for(i=0;i<g;i++)
	            arrayOfMedians[i] = tempArray[(beg + (i*5) + 2)]; //create an array of Medians from each group of 5
	        int median;
	        median = selection(arrayOfMedians,0,g); //3. recursive find the median of medians
	        return median;
	    }
	}

int specSelect(int tempArray[], int beg, int end, int kthElement){
	printf("beg: %i  end: %i\n",beg,end);  
	    if (end-beg <14){
	        inser_sort(tempArray,beg,end);
	        return tempArray[kthElement];
	    }
	    int currentMedian = selection(tempArray,beg,end);
	    printf("currentMedian %i\n",currentMedian);
	    printf("before select partition:\n");
	    int i;
	    for(i=0;i<100; i++);
			cout<<tempArray[i]<<" ";//print randomized array
	    cout<<"\n";
	     
	    currentMedian = Partion(tempArray,beg,end,currentMedian); //4. partition around median of medians.
	     
		cout<<"currentMedian2: "<<currentMedian<<endl;
	    cout<<"after select partition:\n";
	    for (i=0;i<100;i++)
			cout<<tempArray[i];//print randomized array
	    cout<<"\n";
	     
	    if(kthElement == currentMedian) return tempArray[currentMedian];
	    else if(kthElement < currentMedian) return specSelect(tempArray,beg,currentMedian+1,kthElement);
	    else return specSelect(tempArray,currentMedian,end,kthElement);
	     
}
//gets the n/2 and n/2+1 element and averages it and displayes it
void median(int array[], int n)
{int p, q;
float median;
if (n%2==0)
	{p=specSelect(array, 0, n-1, n/2);
	q=specSelect(array, 0, n-1, (n/2+1));
	median=((float) p+(float)q )/2;
	}
else
	{q=specSelect(array, 0, 1, n/2);
	median=q;
	}
cout<<"MEDIAN: "<< median<<endl;
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
median(array,n);
//cout<<selecti(array, 0, n-1, 3)<<endl;
/*for (int i=0;i<n;i++)
	cout<<array[i]<<" ";
	*/
gettimeofday(&tv2,NULL);
cout<<"Running Time = "<<((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec))<<endl;}
