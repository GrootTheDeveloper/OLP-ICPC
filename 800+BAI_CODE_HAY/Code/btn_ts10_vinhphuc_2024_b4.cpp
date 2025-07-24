#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k,s; cin >> n >> k >> s;
	for (int i=1;i<=n;i++) cin >> a[i],a[i]+=a[i-1];
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int pos=lower_bound(a+i,a+n+1,a[i-1]+s)-a;
		if (pos<=n) res+=(n-i+1)/k-(pos-i)/k;
	}
	cout << res;
}