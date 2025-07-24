#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("bai3.inp","r",stdin);
	freopen("bai3.out","w",stdout);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+2,a+n+1);
	int cnt=n-1-k;
	int res=a[1];
	for (int i=2;i<=n;i++)
	{
		if (cnt) res-=a[i];
		else res+=a[i];
		if (cnt) cnt--;
	}
	cout << res;
}