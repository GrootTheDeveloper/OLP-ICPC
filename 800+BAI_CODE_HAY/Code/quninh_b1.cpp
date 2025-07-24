#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b[100005];
const int o=INT_MAX,oo=INT_MIN;
void solve()
{
	unordered_map <int,bool> f;
	int n; cin >> n;
	int mxa=oo,mia=o,mxb=oo,mib=o;
	for (int i=1;i<=n;i++) cin >> a[i],mxa=max(mxa,a[i]),mia=min(mia,a[i]),f[a[i]]=true;
	for (int i=1;i<n;i++)  cin >> b[i],mxb=max(mxb,b[i]),mib=min(mib,b[i]);

	if (mxb-mxa==mib-mia) return cout << mxb-mxa << '\n',void();
	int k=mxb-mxa,h=mib-mia;
	if (k<=0) return cout << h,void();
	if (h<=0) return cout << k,void();
	for (int i=1;i<=n;i++)
	{
		if (f[b[i]-k]==false && f[b[i]-h]==true) return cout << h << '\n',void();
		if (f[b[i]-h]==false && f[b[i]-k]==true) return cout << k << '\n',void();
	}
	cout << k << '\n';
}



main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();

}