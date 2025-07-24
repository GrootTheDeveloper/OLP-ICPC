#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,a[100005];


void sub1()
{
	bool f[25];
	int res=0;
	while (true)
	{
		memset(f,false,sizeof(f));
		int cnt=0;
		for (int i=1;i<=n;i++) 
		if (a[i]!=0 && !f[a[i]] && cnt<k) f[a[i]]=true,a[i]=0,cnt++;
		if (cnt==k) res++;
		else break;
	}
	cout << res;
}
void sub2()
{
	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++) cnt1+=(a[i]==1),cnt2+=(a[i]==2);
	cout << min(cnt1,cnt2);
}
int f[100005];
vector <int> vi,oo;
void sub3()
{
	priority_queue <int> q;
	int res=0;
	for (int i=1;i<=n;i++) f[a[i]]++;
	for (int i=1;i<=n;i++) if (f[a[i]]) q.push(f[a[i]]),f[a[i]]=0;
	while ((int)q.size()>=k)
	{
		vi=(oo);
		int m=INT_MAX;
		for (int i=1;i<=k;i++) 
		{
			vi.push_back(q.top());
			m=min(m,vi.back());
			q.pop();
		}
		res+=m;
		for (int c : vi) if (c-m!=0) q.push(c-m); 
	}
	cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("REMOVE.INP","r",stdin);
	freopen("REMOVE.OUT","w",stdout);
	cin >> n >> k;
	int mx=0;
	for (int i=1;i<=n;i++) cin >> a[i],mx=max(mx,a[i]);
	if (k==1) return cout << n,0;
	if (n<=20) sub1();
	else if (mx<=2 && k==2) sub2();
	else sub3();
	
}