//https://lqdoj.edu.vn/problem/cses1661
#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
#define ll long long
ll f[maxn],n,ans=0,ai,k;
int main()
{
	map<ll, ll> b;
	cin >> n >> k;
	f[0]=0;
	for (int i=1; i<=n;i++)
	{
		cin >> ai;
		f[i]=f[i-1]+ai;

	}
	if (k==0) b[0]=0;
	else b[0]=1;
	for (int i=1; i<=n; i++)
	{
		b[f[i]]+=1;
		if (b[f[i]-k]!=0) ans+=b[f[i]-k];
	}
	cout << ans;
	return 0;


}
