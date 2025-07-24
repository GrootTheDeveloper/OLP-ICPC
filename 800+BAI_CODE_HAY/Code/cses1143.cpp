#include <bits/stdc++.h>
using namespace std;
#define int long long
const int SIZE = 2e5 + 5;
int n,m;
int a[SIZE],seg[SIZE*4];


void update(int id, int l, int r, int pos)
{
	if (pos>r || pos<l) return;
	if (l==r && pos==l) return seg[id]=a[l],void();
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (r<u || l>v) return 0;
	if (u<=l && r<=v) return seg[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i],update(1,1,n,i);
	while (m--)
	{
		int x; cin >> x;
		if (seg[1]<x)
		{
			cout << 0 << " ";
			continue;
		}
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (get(1,1,n,l,mid)>=x) r=mid-1;
			else l=mid+1;
		}
		while (get(1,1,n,1,l)<x) l++;
		while (get(1,1,n,1,l-1)>=x) l--;
		cout << l << ' ';
		a[l]-=x;
		update(1,1,n,l);
	}

}