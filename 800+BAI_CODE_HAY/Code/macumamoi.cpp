#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9;

struct dta{
	int val=0,id=0,sumcnt=0;
}a[100005],t[400005],oo;
bool cmp(dta a, dta b)
{
	return a.val>b.val;
}
dta merge(dta a, dta b)
{
	dta res;
	res.val=a.val+b.val;
	res.sumcnt=a.sumcnt+b.sumcnt;
	return res;
}
void up(int id, int l, int r, int pos, int val)
{
	if (pos>r || pos<l) return;
	if (l==r && l==pos)
	{
		t[id].val=val;
		t[id].sumcnt=1;
		return;
	}
	int mid=(l+r)/2;
	up(id*2,l,mid,pos,val);
	up(id*2+1,mid+1,r,pos,val);
	t[id].val=t[id*2].val+t[id*2+1].val;
	t[id].sumcnt=t[id*2].sumcnt+t[id*2+1].sumcnt;
}
dta get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return oo;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	int res=0;
	for (int i=1;i<=n;i++)
	{
		dta k=get(1,1,n,1,a[i].id);
		res+=k.val-a[i].val*k.sumcnt;
		if (res>=(int)1e18) res-=(int)1e18;
		up(1,1,n,a[i].id,a[i].val);
	}
	cout << res%mode;
}