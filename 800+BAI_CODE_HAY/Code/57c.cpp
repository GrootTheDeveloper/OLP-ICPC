#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,a[200005],pre[200005],cnt;

void sub1()
{
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l,r,x;
	while (k--)
	{
		cin >> l >> r >> x;
		int pos=upper_bound(pre+l,pre+r+1,pre[l-1]+x)-pre;
		cout << pos-l << '\n';
	}

}
int solve(int l, int r, int x)
{
	priority_queue <int,vector<int>,greater<int>> q;
	for (int i=l;i<=r;i++) q.push(a[i]);
	int res=0,k;
	while (q.size())
	{
		k=q.top();
		if (k<=x) res++,x-=k,q.pop();
		else break;

	}
	return res;
}
void sub2()
{
	int l,r,x;
	while (k--)
	{
		cin >> l >> r >> x;
		cout << solve(l,r,x) << '\n';
	}
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("TOYS.INP","r",stdin);
	freopen("TOYS.OUT","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i],cnt+=(a[i]<a[i-1]);
	if (cnt==0) sub1();
	else sub2();
}