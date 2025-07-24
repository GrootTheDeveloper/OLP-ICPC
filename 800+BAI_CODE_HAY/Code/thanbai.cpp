#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[200005];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	int res=0,MIN=n;
	for (int i=1;i<=k;i++)
	{
		int ai; cin >> ai;
		f[ai]=1; 
		res+=ai;
		MIN=min(MIN,ai);
	}
	int MAX=0;for (int i=n;i>=1;i--) if (f[i]==0) {MAX=i;break;}
	cout << res-MIN+MAX;
}