#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,a[20],f[20][150];

int calc(int pos, bool lim, int sum)
{
	if (pos<1) return sum;
	if (lim==false && f[pos][sum]>=0) return f[pos][sum];
	int res=0;
	int mx=(lim? a[pos]:9);
	for (int c=0;c<=mx;c++)
		res+=calc(pos-1,lim && c==mx,sum+c);
	if (!lim) f[pos][sum]=res;
	return res;
}

int g(int x)
{
	n=0;
	while (x)
	{
		a[++n]=x%10;
		x/=10;
	}
	return calc(n,true,0);
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	memset(f,-1,sizeof(f));
	int l,r;
	while (t--)
	{
		cin >> l >> r;
		cout << g(r)-g(l-1) << '\n';
	}
}