#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e3+5;
int a[N],t[N*4],cnt,f[N],n;


void up(int id, int l, int r, int pos, int val)
{
	if (pos>r || pos<l) return;
	if (l==r && l==pos) return t[id]=val,void();
	int mid=(l+r)/2;
	up(id*2,l,mid,pos,val);
	up(id*2+1,mid+1,r,pos,val);
	t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return 0;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int pin(int val)
{
	int l=1,r=n,sum;
	while (l<r) 
	{
		int mid=(l+r)/2;
		sum=get(1,1,n,1,mid);
		if (sum<val) l=mid+1;
		else r=mid-1;
	}
	while (get(1,1,n,1,l-1)==val) l--;
	while (get(1,1,n,1,l)<val) l++;
	return l;
}
void sub1()
{
	for (int i=1;i<=n;i++)
	{
		int res=1;
		res+=min(i-1,n-i);
		if (i<=n/2) res+=i;
		else res+=n-i;
		cout << res << ' ';
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("MEDIAN.INP","r",stdin);
	freopen("MEDIAN.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],cnt+=(a[i]<a[i-1]);
	if (cnt==0) return sub1(),0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			up(1,1,n,a[j],1);
			int x=(j-i+1);
			f[pin((x+1)/2)]++;
		}
		for (int j=i;j<=n;j++) up(1,1,n,a[j],0);
	}
	for (int i=1;i<=n;i++) cout << f[a[i]] << ' ';
}