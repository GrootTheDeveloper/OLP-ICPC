#include<bits/stdc++.h>
using namespace std;
long long n,a,b,i;
int main()
{
    cin>>n;
   a=1;b=0;
    while(n>0)
    { for (i=2;i<=n;i+=2) cout<<a*i+b<<' ';
    	if (n%2==1)
        {
            cout<<a+b<<' ';
            b=b+a;
        }
    	else b=b-a;
    	a=a*2;n=n/2;
    }
}

