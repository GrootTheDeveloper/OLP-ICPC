#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int f[1000006];
struct dta{
	int val,id;
}a[200005];
bool cmp(dta a, dta b)
{
	return a.val==b.val? a.id<b.id : a.val<b.val;
}

void up(int id, int l, int r, int pos,int val)
{
	if (pos>r || pos<l) return;
	if (l==r && pos==l) return f[id]=val,void();
	int mid=(l+r)/2;
	up(id*2,l,mid,pos,val);
	up(id*2+1,mid+1,r,pos,val);
	f[id]=f[id*2]+f[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return 0;
	if (u<=l && r<=v) return f[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
unordered_map <int,int> d;

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i].val,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int cnt=get(1,1,n,1,a[i].id)+1-d[a[i].val];
		res=(res+cnt)%mode;
		d[a[i].val]+=cnt;
		up(1,1,n,a[i].id,cnt);
	}
	cout << res;
}