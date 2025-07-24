#include <bits/stdc++.h>
using namespace std;
#define int long long 
priority_queue <int> q;
int f[200005],n,k,ai;
void sub1()
{
	cout << n - (max(f[1],f[2])-min(f[1],f[2]));
}
void sub2()
{
	if (f[1]==f[2]==f[3]) return cout << n,void();
	int t=max({f[1],f[2],f[3]});
	cout << n - (max(n-t,t) - min(n-t,t)); 
}
void sub3()
{
	for (int i=1;i<=k;i++) if (f[i]) q.push(f[i]);
	while (q.size()!=1)
	{
		int l=q.top();
		q.pop();
		int r=q.top();
		q.pop();
		q.push(l-r);
	}
	cout << n-q.top();
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("chonbong.inp","r",stdin);
	//freopen("chonbong.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> ai, f[ai]++;
	if (k==2) sub1();
	else if(k==3) sub2();
	else sub3();
	
}