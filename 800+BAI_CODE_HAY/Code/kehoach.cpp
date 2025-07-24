#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005],b[100005],f[100005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	for (int i=1;i<=n;i++)
	{
		int pos=upper_bound(a+1,a+n+1,a[i]-k)-a-1;
		f[i]=max(f[i-1],f[pos]+b[i]);
	}
	cout << f[n];
}