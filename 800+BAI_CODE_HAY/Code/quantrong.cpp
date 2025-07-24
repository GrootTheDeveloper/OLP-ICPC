#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[1111];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int sum=0,x,res=0;
	memset(f,-1,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		cin >> x;
		if (f[x]==-1) f[x]=sum;
		else res=max(res,sum+x-f[x]);
		sum+=x;
	}
	cout << res;
}