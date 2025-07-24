#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> f;
int a[1000];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("TASK.INP","r",stdin);
	//freopen("TASK.OUT","w",stdout);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],f[a[i]]++;
	sort(a+1,a+n+1);
	int res=0;
	for (int i=1;i<=n;i++)
	if (f[a[i]]>f[res]) res=a[i];
	cout << res << ' ' << f[res];
}