#include <iostream>
using namespace std;
#include </usr/include/stdio.h>
#include </usr/include/string.h>
int main()
{int flag=0;
char a[20];
cout<<"enter the string :";
gets(a);
for(int i=0,j=strlen(a)-1;i<strlen(a)/2;i++,j--)
	if(a[i] != a[j])
		{flag=1;
		break;}
if (flag==0)
	cout<<"its a palindrome"<<endl;
else
	cout<<"its not a palindrome"<<endl;
}
