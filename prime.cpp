#include <iostream>
using namespace std;
int main()
{int n,flag=0;
cout<<"enter the number";
cin>>n;
cout<<endl;
for (int i=2;i<=n/2;i++)
	if (n%i ==0)
		{flag=1;
		break;}
if(flag==0)
	cout<<"is prime";
else cout<<"is not prime";
}
