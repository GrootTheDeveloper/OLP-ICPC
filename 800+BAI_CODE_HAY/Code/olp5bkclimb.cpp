#include <bits/stdc++.h>
using namespace std;
#define int long long
int m[500005],a[500005],b[500005],pre[500005],bug[500005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i],pre[i]=pre[i-1]+a[i];
	for (int i=1;i<=n;i++) cin >> b[i],bug[i]=bug[i-1]-b[i];
	for (int i=1;i<=n;i++) m[i]=max(m[i-1],a[i]-bug[i-1]);
	int x;
	while (k--)
	{
		cin >> x;
		int pos=upper_bound(m+1,m+n+1,x)-m-1;
		cout << pre[pos] << '\n';
	}

}