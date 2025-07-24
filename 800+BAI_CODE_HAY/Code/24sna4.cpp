#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,d; cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int res=0;
	for (int r=n;r>=1;r--)
		if (abs(a[r]-a[r-1])<=d && r-1>=1) res++,r-=1;
	cout << res;
}