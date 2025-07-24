#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct Dta{
	int x,y,my;
};
struct dta{
	int fi,se;
};
bool cmp(dta a, dta b)
{
	return a.se<b.se;
}
dta a[200005];
vector <Dta> v;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=m;i++) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+m+1,cmp);
	Dta node;
	node.x=a[1].fi;node.y=node.my=a[1].se;
	v.push_back(node);
	for (int i=2;i<=m;i++)
	{
		if (a[i].fi>v.back().y)
		{
			if (a[i].se<=v.back().my) return cout << -1,0;
			else
			{
				node.x=max(a[i].fi,v.back().my+1);
				node.y=node.my=a[i].se;
				v.push_back(node);
			}
		}
		else
		{
			node.x=max(v.back().x,a[i].fi);
			node.y=min(v.back().y,a[i].se);
			node.my=max(v.back().my,a[i].se);
			v.pop_back();
			v.push_back(node);
		}
	}
	cout << (int)v.size();




}