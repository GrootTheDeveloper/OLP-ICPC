#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,x;
struct dta{int val,id;};
dta a[200005];
bool cmp(dta a, dta b) {return a.val<b.val;};
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> x;
	for (int i=1;i<=n;i++) cin >> a[i].val, a[i].id=i;
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while (l<r)
	{
		int k=a[l].val+a[r].val;
		if (k==x) {cout << a[l].id << ' ' << a[r].id;exit(0);}
		if (k>x) r--;
		else l++;
	}
	cout << "IMPOSSIBLE";
}
