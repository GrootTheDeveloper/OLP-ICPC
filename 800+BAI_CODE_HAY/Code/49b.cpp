#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[200005],b[200005],c[200005],n,m;
void sub1()
{
	int fi=a[1]-b[1],se=a[1]+b[1];
	for (int i=1;i<=m;i++) cout << ((fi<=c[i] && c[i]<=se)? 1:0) << ' ';
}
void sub2()
{
	int res=0,k=c[1];
	for (int i=1;i<=n;i++) res+=(k>=a[i]-b[i] && k<=a[i]+b[i]);
	cout << res;
}

int pos[10000];
void sub4()
{
	for (int i=1;i<=n;i++)
		for (int j=max(a[i]-b[i],0LL);j<=a[i]+b[i];j++) pos[j]++;
	for (int i=1;i<=m;i++) cout << pos[c[i]] << ' ';
	
}
const int N=2e5+3;
int t[N*4],lazy[N*4];
void pull(int id, int l, int r)
{
	int mid=(l+r)/2;
	if (lazy[id])
	{
		t[id*2]+=lazy[id]*(mid-l+1);
		t[id*2+1]+=lazy[id]*(r-mid);
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}
void up(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return;
	if (u<=l && r<=v) 
	{
		lazy[id]+=1;
		t[id]+=r-l+1;
		return;
	}
	pull(id,l,r);
	int mid=(l+r)/2;
	up(id*2,l,mid,u,v);
	up(id*2+1,mid+1,r,u,v);
	t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int pos)
{
	if (pos<l || r<pos) return 0;
	if (l==r && l==pos) return t[id];
	pull(id,l,r);
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,pos),get(id*2+1,mid+1,r,pos));
}
void sub3()
{
	for (int i=1;i<=n;i++)
	{
		int fi=a[i]-b[i],se=a[i]+b[i];
		int t1=lower_bound(c+1,c+m+1,fi)-c;
		int t2=upper_bound(c+1,c+m+1,se)-c-1;
		if (t2-t1>=0) up(1,1,m,t1,t2);
	}
	for (int i=1;i<=m;i++) cout << get(1,1,m,i) << ' ';
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("LIGHT.INP","r",stdin);
	freopen("LIGHT.OUT","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	for (int i=1;i<=m;i++) cin >> c[i];
	if (n==1) sub1();
	else if (m==1) sub2();
	else if (n<=5000) sub4();
	else sub3();

}