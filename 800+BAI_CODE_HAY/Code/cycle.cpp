#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int pos=upper_bound(a+1,a+n+1,k-a[i])-a-1;
		if (pos>i) res+=pos-i;
	}
	cout << res;
}