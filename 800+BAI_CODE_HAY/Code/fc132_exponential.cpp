#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	int n; cin >> n;
	int res=1;
	for (int i=2;i<=n;i++)
	{
		int k=1,cnt=0;
		while (k*i<=n) cnt++,k*=i;
		if (cnt>=2) res=max(res,k);
	}
	cout << res;
}