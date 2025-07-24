#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int t[N*4];

void up(int id, int l, int r, int pos, int k)
{
	if (pos>r || pos<l) return;
	if (l==r && l==pos) return t[id]=k,void();
	int mid=(l+r)/2;
	up(id*2,l,mid,pos,k);
	up(id*2+1,mid+1,r,pos,k);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return -1e9;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	char type;
	int pos,k;
	while (m--)
	{
		cin >> type >> pos >> k;
		if (type=='S') 	up(1,1,n,pos,k);
		else cout << get(1,1,n,pos,k) << '\n';
	}	
}