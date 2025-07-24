#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector <int> f[20];
int n,a[100005];


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("SAME.INP","r",stdin);
	freopen("SAME.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],f[a[i]].push_back(i);
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int t=upper_bound(f[a[i]].begin(),f[a[i]].end(),i)-f[a[i]].begin();
		for (int h=t;h<f[a[i]].size();h++)
		{
			int l=i,k=f[a[i]][h],r=k,cnt=0;
			while (a[l]==a[r] && l<k && r<=n) cnt++,l++,r++,res=max(res,cnt);
		}
	}
	cout << res;
}