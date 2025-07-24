#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int a[N],t[N*4],lazy[N*4],type,u,v,val;

void push(int id)
{
	if (lazy[id])
	{
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		t[id*2]+=lazy[id];
		t[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}


void up(int id, int l, int r, int u, int v, int val)
{
	if (u>r || v<l) return;
	if (u<=l && r<=v) 
	{
		t[id]+=val;
		lazy[id]+=val;
		return;
	}
	push(id);
	int mid=(l+r)/2;
	up(id*2,l,mid,u,v,val);
	up(id*2+1,mid+1,r,u,v,val);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return INT_MIN;
	if (u<=l && r<=v) return t[id];
	push(id);
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	while (m--)
	{
		cin >> type;
		if (type==0)
		{
			cin >> u >> v >> val;
			up(1,1,n,u,v,val);
		}
		else
		{
			cin >> u >> v;
			cout << get(1,1,n,u,v) << ' ';
		}
	}
}