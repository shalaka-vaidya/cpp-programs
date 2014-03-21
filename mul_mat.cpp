#include <iostream>
using namespace std;
void val_matrix(int a[10][10],int m,int n)
{for (int i=0;i<m;i++)
	for (int j=0;j<n;j++)
		cin>>a[i][j];
}
void print_mat(int a[10][10],int m,int n)
{for (int i=0;i<m;i++)
	{for (int j=0;j<n;j++)
		cout<<a[i][j]<<" ";
	cout<<endl;
	}
}
int main()
{int a[10][10],b[10][10],c[10][10],m,n,p,q;
cout<<"enter the order of first matrix :"<<endl;
cin>>m>>n;
cout<<"enter the elements of first matrix :"<<endl;
val_matrix(a,m,n);
print_mat(a,m,n);
cout<<"enter the order of second matrix :"<<endl;
cin>>p>>q;
cout<<"enter the elements in second matrix :"<<endl;
val_matrix(b,p,q);
print_mat(b,p,q);
if(n == p)
	{for( int i=0;i<m;i++)
		for (int j=0;j<q;j++)
			{c[i][j]=0;
			for(int x=0;x<n;x++)
			c[i][j]+=(a[i][x]*b[x][j]);
			}
	print_mat(c,m,q);
	}
else cout<<"not possible"<<endl;
}
