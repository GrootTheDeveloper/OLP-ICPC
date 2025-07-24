#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct DATA{
	int fi,se;
};
bool cmp(DATA a, DATA b)
{
	return a.fi<b.fi;
}
DATA a[200005];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+n+1,cmp);
	int k=0,res=0;
	for (int i=1;i<=n;i++)
	{
		k+=a[i].fi;
		res+=a[i].se-k;
	}
	cout << res;
}