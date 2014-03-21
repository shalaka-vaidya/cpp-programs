#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
#include </usr/include/ctype.h>

int main()
{char ms[100],dep[10],rep[10];
int flag=0;
cout<<"enter the main string";
gets(ms);
cout<<"enter the delete word";
gets(dep);
cout<<"enter replace word";
gets(rep);

for (int i=0;i<strlen(ms);i++)
	{if (ms[i]==dep[0] && isspace(ms[i-1]))
		{for (int j=1;j<strlen(dep);j++)
			{if(ms[i+j]!=dep[j])
				{flag==0;
				break;
				}
			 else
				{
				flag=1;
				}
			if (flag==1)
				{flag=0;
				if (strlen(dep)==strlen(rep))
					{cout<<"hi"<<endl;
					for (int k=0;k<strlen(dep);k++)
						ms[i+k]=rep[k];
					}
				else if (strlen(dep)>strlen(rep))
					{cout<<"hi"<<endl;
					int d=strlen(dep)-strlen(rep);
					for (int k=0;k<strlen(rep);k++)	
						ms[i+k]=rep[k];
					for (int l=i+strlen(rep);l<strlen(ms);l++)
						{ms[l]=ms[l+d];
						}
					}
				else if (strlen(rep)> strlen(dep))
					{int d=strlen(rep)-strlen(dep);
					char st[1000];
					for (int k=0;k<i;k++)
						st[k]=ms[k];
					for (int l=0;l<strlen(rep);l++)
						st[i+l]=rep[l];
					for (int m=i+strlen(dep);m<strlen(ms);m++)
						st[d+m]=ms[m];
					cout<<st;
					}
				}
			}
		}
	}
cout<<"main string is"<<ms<<endl;
}
				
