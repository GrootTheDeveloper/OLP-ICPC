#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
void sub1()
{
	int n=stoi(s);
	int m=n;
	while (m!=0)
	{
		if (m%10==9 || m%10==6) m/=10;
		else break;
	}
	if (m) return cout << -1,void();
	int res=0;
	for (int i=1;i<n;i++) 
	{
		int x=i;
		while (x!=0) 
		{
			int t=x%10;
			if (t==9 || t==6) x/=10;
			else break;
		}
		res+=(x==0);
	}
	cout << res;
}
const int mode=24022007;
int f[100005];
void sub2()
{
	int n=s.size(),pos=-1,sum=0;
	f[0]=1;
	for (int i=1;i<=n;i++) 
	{
		f[i]=(f[i-1]*2)%mode;
		if (i<n) sum=(sum+f[i])%mode;
	}
	for (int i=0;i<n;i++) 
		if (s[i]!='6' && s[i]!='9') return cout << -1,void();
	int res=0;
	for (int i=n;i>=1;i--)
	{
		if (s[i-1]=='9') res=(res+f[n-i])%mode;
	}
	res=(res+sum)%mode;
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("BEAUTY.INP","r",stdin);
	freopen("BEAUTY.OUT","w",stdout);
	cin >> s;
	if (s.size()<=6) sub1();
	else sub2();
	
}