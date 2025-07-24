#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct dta{
	int pi,hi;
}a[200005];
bool cmp(dta a, dta b)
{
	return a.pi<b.pi;
}
int pos[200005],pre[200005],f[200005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i].pi;
	for (int i=1;i<=n;i++) cin >> a[i].hi;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i].hi;
	vector <int> v;
	a[0].hi=1000000000;
	a[0].pi=-1;
	f[0]=1;
	v.push_back(0);
	for (int i=1;i<=n;i++)
	{
		while (a[v.back()].hi<a[i].hi) v.pop_back();
		pos[i]=v.back();
		v.push_back(i);
	}
	for (int i=1;i<=n;i++)
		f[i]=f[pos[i]]+a[i].hi*(a[i].pi-a[pos[i]].pi-1)-(pre[i-1]-pre[pos[i]]);
	int m; cin >> m;
	while (m--)
	{
		int x; cin >> x;
		cout << upper_bound(f+1,f+n+1,x)-f-1 << '\n';
	}


}