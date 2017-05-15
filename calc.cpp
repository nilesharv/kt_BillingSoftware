#include<bits/stdc++.h>
#include<string.h>
#define debug printf("test")

#define ctod(a) (a-'0')
#define dtoc(b) (b+'0')

using namespace std;

void strrev(char *x)
{
int i=0;
char ch;
int j=strlen(x)-1;
while(i<j)
{
ch=x[i];
x[i]=x[j];
x[j]=ch;
i++;
j--;
}
}


int lessThan(char *a,char *b,int n1,int n2)
{
	printf("less than\n");
	if(n2>n1)
		return 1;
	else
		if(n1>n2)
			return 0;

	for(int i=0;i<n1;i++)
	{
		if(a[i]<b[i])
			return 1;
		else
			if(b[i]<a[i])
				return 0;
	}

return -1;
}



char *multipication(char *a,char *b,int an,int bn)
{
int res[an+bn];
memset(res,0,sizeof(res));
a[an]='\0';
b[bn]='\0';
strrev(a);
strrev(b);
int k=0;
for(int i=0;i<an;i++)
{

for(int j=0;j<bn;j++)
{
res[j+k]+=(a[i]-'0')*(b[j]-'0')	;
}
k++;
}
int c=0;
int i=0;
for(i=0;i<bn+k;i++)
{
c=c+res[i];
res[i]=c%10+'0';
c/=10;
}

while(c>0)
{
res[i]=c%10+'0';	
c/=10;
i++;
}
while(res[i-1]=='0')
i--;
char *t=new char[an+bn];
for(int j=0;j<i;j++)
t[j]=(char)res[j];
t[i]='\0';
strrev(t);
return t;
}

char* subtract(char *a,char *b,int n1,int n2)
	{

	if(n2>n1)
	{
	swap(n1,n2);
	swap(a,b);
	}	
strrev(a);
strrev(b);
char *res=new char[n1];		
for(int i=0;i<n1;i++)
a[i]=a[i]-'0';
for(int i=0;i<n2;i++)
b[i]=b[i]-'0';
int i=0;
for(i=0;i<n1&&n2;i++)
{
int t=a[i]-b[i];
if(t<0)
{t+=10;
a[i+1]-=1;
}
res[i]=t;
//cout<<t<<' ';
}	

while(i<n1)
{
if(a[i]<0)
{a[i+1]-=1;
a[i]+=10;

}
res[i]=a[i];
i++;
}		

while(res[n1-1]==0)
   n1--;

for(i=0;i<n1;i++)
{
res[i]+='0';
}
res[n1]='\0';
strrev(res);
	return res;
	}


char *divide(char *a,int n,int x)
{

int t=0;
int k=0;
int *res=new int[n+10];
for(int i=0;i<n;i++)
a[i]-='0';

for(int i=0;i<n;i++)
{
t=t*10+a[i];
//cout<<t<<' ';
if(t>=x)
{
res[k]=t/x;
t%=x;
k++;
}

}
res[k]=-1;
k++;
int j=0;
while(t>0&&j<5)
{
t=t*10;
res[k]=t/x;
k++;
j++;
t%=x;
}

char *result=new char[k+1];
for(int i=0;i<k;i++)
if(res[i]==-1)
result[i]='.';
else
result[i]=res[i]+'0';
result[k]='\0';
return result;
}



int main()
{
char a[]="455667";
char b[]="12345";

//char *i=subtract(a,b,strlen(a),strlen(b));
//cout<<i<<'\n';
char *d=divide(a,6,101);
cout<<d;
return 0;
}
