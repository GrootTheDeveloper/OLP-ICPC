#include <bits/stdc++.h>
using namespace std;
#define int long long 
int divs[10000007],
	   f[10000007];
const int mode=1e9+7;
int n,pos,k,mx,ai;

void sie()
{
	int lim=trunc(sqrt(1e7));
	for (int i=2;i<=lim;i++)
		if (divs[i]==0) for (int j=i*i;j<=1e7;j+=i) divs[j]=i;
	divs[2]=2;
	for (int i=3;i<=1e7;i+=2) if (divs[i]==0) divs[i]=i;
}
void pt(int n)
{
	int cnt,k;
	while (n!=1)
	{
		cnt=0;k=divs[n];
		while (n%k==0)
		{
			cnt++;
			n/=k;
		}
		f[k]=max(f[k],cnt);
	}
}
void xu(int n)
{
	while (n!=1)
	{
		f[divs[n]]--;
		n/=divs[n];
	}
}
int power(int a, int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sie();
	/*for (int i=2;i<=10;i++) cout << divs[i] << ' ';
	*/
	cin >> n >> pos;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		if (i==pos) k=ai;
		//pt(ai);
		mx=max(mx,ai);
	}
	/*xu(k);
	int res=1;
	for (int i=2;i<=mx;i++)
	{	
		if (f[i]&1)	f[i]--;
		res=res*power(i,f[i]);
		if (res>=mode*mode) res-=mode*mode;
	}
	cout << res;
	*/
	cout << mx;
}