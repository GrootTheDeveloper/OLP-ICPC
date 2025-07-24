#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[200005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	cout << max(abs(a[1]+a[2]),abs(a[n]+a[n-1]));
}