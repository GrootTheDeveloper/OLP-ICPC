#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,q,a[200005];

void sub1()
{
	int l,r;
	while (q--)
	{
		cin >> l >> r;
		int tmp=0;
		for (int j=l+1;j<=r;j++) if (a[l]!=a[j])
		{
			cout << l << ' ' << j << '\n';
			tmp=1;
			break;
		}
		if (!tmp) cout << "-1 -1" << '\n';
	}
}
vector <int> d[11];
void call(int l, int r)
{
	for (int i=1;i<=10;i++)
	for (int j=1;j<=10;j++)
	if (i!=j && (int)d[i].size() && (int)d[j].size())
	{
		auto it1=lower_bound(d[i].begin(),d[i].end(),l);
		if (*it1<=r)
		{
			auto it2=upper_bound(d[j].begin(),d[j].end(),(int)*it1);
			if (*it2<=r) return cout << *it1 << ' ' << *it2 << '\n',void();
		}
	}
	cout << "-1 -1" << '\n';
}
void sub2()
{
	for (int i=1;i<=n;i++) d[a[i]].push_back(i);
	int l,r;
	while (q--)
	{
		cin >> l >> r;
		call(l,r);
	}
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("bai3.inp","r",stdin);
	freopen("bai3.out","w",stdout);
	cin >> n >> q;
	int mx=0;
	for (int i=1;i<=n;i++) cin >> a[i],mx=max(mx,a[i]);
	if (mx<=10) sub2();
	else sub1();
	

}