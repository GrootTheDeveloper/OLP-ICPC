#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[100005],cnt[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,ai; cin >> n;
	for (int i=1;i<=n;i++) cin >> ai,cnt[ai]++;
	for (int i=1;i<=100000;i++) f[i]=f[i-1]+cnt[i];
	int m; cin >> m;
	while (m--)
	{
		int x,y; cin >> x >> y;
		cout << f[y]-f[x-1] << '\n';
	}

}