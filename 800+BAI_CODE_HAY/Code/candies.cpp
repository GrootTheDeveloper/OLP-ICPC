#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e5+5;

int seg[MAX*4],lazy[MAX*4],a[MAX],n;

void build(int id, int l, int r)
{
	if (l==r) return seg[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
void pull(int id)
{
	if (lazy[id])
	{
		seg[id*2]+=lazy[id];
		seg[id*2+1]+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}
void up(int id, int l, int r, int u, int v)
{
	if (r<u || l>v) return;
	if (u<=l && r<=v)
	{
		seg[id]-=1;
		lazy[id]-=1;
		return;
	}
	pull(id);
	int mid=(l+r)/2;
	up(id*2,l,mid,u,v);
	up(id*2+1,mid+1,r,u,v);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int get(int pos)
{
	int l=1,r=n,id=1;
	if (pos<1 || pos>n) return 0;
	while (l<r)
	{
		pull(id);
		int mid=(l+r)/2;
		if (pos<=mid) id=id*2,r=mid;
		else id=id*2+1,l=mid+1;
	}
	return seg[id];
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	build(1,1,n);
	int m; cin >> m;
	for (int i=1,x;i<=m;i++)
	{
		cin >> x;
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (get(mid)>=x) r=mid-1;
			else l=mid+1;
		}
		while (get(l)<x && l+1<=n+1) l++;
		while (get(l-1)>=x && l-1!=0) l--;
		cout << n-l+1 << '\n';
		up(1,1,n,l,n);
	}
	
	memset(a,-1,sizeof(a));
	cout << a[2];
}