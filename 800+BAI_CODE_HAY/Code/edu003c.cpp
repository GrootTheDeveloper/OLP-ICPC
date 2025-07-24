#include <bits/stdc++.h>
using namespace std;
#define int long long 
int x;
bool prime[1000006];

void sang(int n)
{
	int lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++)
	if (!prime[i])
		for (int j=i*i;j<=n;j+=i) prime[j]=true;
}
bool dx(int n)
{
	int k=n,temp=0;
	while(k) temp=temp*10+k%10,k/=10;
	return temp==n;
}
void sub1()
{
	sang(x);
	int res=0;
	for (int i=11;i<x;i++) res+=(dx(i) && !prime[i]);
	cout << res << ' ';
}
int n,a[111],res,si;
bool nt(int n)
{
	if (n<2) return false;
	int lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++) if (n%i==0) return false;
	return true;

}
bool check()
{
	int s=0;
	for (int i=1;i<=si;i++) s=s*10+a[i];
	if (s<x) return nt(s);
	else return false;
}
void Try(int l, int r)
{
	if (l>r) return res+=check(),void();
	if (l==1)
	{
		for (int i=1;i<=9;i+=2) 
		{	
			a[l]=a[r]=i;
			Try(l+1,r-1);
		}
	}
	else
	{
		for (int i=0;i<=9;i++)  
		{
			a[l]=a[r]=i;
			Try(l+1,r-1);
		}
	}
}

void sub2()
{
	string s=to_string(x);
	n=s.size();
	for (int i=7;i<=n;i++)  
	{
		si=i;
		Try(1,i);
	}
	cout << res+109;
}
main()
{
	freopen("NTDX.INP","r",stdin);
	freopen("NTDX.OUT","w",stdout);
	cin >> x;
	if (x<=1e6) sub1();
	else sub2();
	
	

}