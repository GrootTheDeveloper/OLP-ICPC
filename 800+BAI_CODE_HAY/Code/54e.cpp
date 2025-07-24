#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second

pair <int,int> query[100005];
int pre[100006],q,n,m,s[100005],c[100005];
void sub1()
{
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+c[i];
	for (int i=1;i<=q;i++)
		cout << pre[query[i].se]-pre[query[i].fi-1] <<'\n';
}
int ans[100005],f[1000006];
void sub2()
{
	int sum=0;
	for (int i=1;i<=n;i++) s[i]%=m,sum+=s[i];
	for (int i=1;i<=n;i++)
	{
		int res=0;
		for (int j=sum;j>=s[i];j--)
		{
			if (f[j-s[i]] || j-s[i]==0) f[j]=max(f[j],f[j-s[i]]+c[i]);
			if (j%m==0) res=max(res,f[j]);
		}
		ans[i]=max(res,ans[i-1]);
	}
	for (int i=1;i<=q;i++)
	{
		cout << ans[query[i].se] << '\n';
	}

}
int p[100005];
void sub3()
{
	for (int i=1;i<=n;i++) s[i]%=m,p[i]=p[i-1]+s[i],pre[i]=pre[i-1]+c[i];
	for (int i=1;i<=q;i++)
	{
		int x=query[i].fi,y=query[i].se;
		if ((p[y]-p[x-1])%2==0) 
		{
			cout << pre[y]-pre[x-1] <<'\n';
			continue;
		}
		int res=pre[y]-pre[x-1],k=INT_MAX;
		for (int j=query[i].fi;j<=query[i].se;j++) 
		if (s[j]) k=min(k,c[j]);
		cout << res-k << '\n';

	}	
}

void check( int sum,int l, int r)
{
	int res=0,f[sum+1];
	memset(f,0,sizeof(f));
	for (int i=l;i<=r;i++)
	{
		for (int j=sum;j>=s[i];j--)
		{
			if (f[j-s[i]] || j-s[i]==0) f[j]=max(f[j],f[j-s[i]]+c[i]);
			if (j%m==0) res=max(res,f[j]);
		}
	}
	cout << res << '\n';
}
void sub4()
{
	for (int i=1;i<=n;i++) s[i]%=m,pre[i]=pre[i-1]+s[i];
	for (int i=1;i<=q;i++)
	{
		int sum=pre[query[i].se]-pre[query[i].fi-1];
		check(sum,query[i].fi,query[i].se);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("LMONEY.INP","r",stdin);
	freopen("LMONEY.OUT","w",stdout);
	cin >> n >> m >> q;
	for (int i=1;i<=n;i++) cin >> s[i];
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=1;i<=q;i++) cin >> query[i].fi >> query[i].se;
	if (s[1]==0 && s[n]==0) sub1();
	else if (query[1].fi==1 && query[q].fi==1) sub2();
	else if (m==2) sub3();
	else sub4();


}