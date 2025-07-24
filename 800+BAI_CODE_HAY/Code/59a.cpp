#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[2333];
int divs[20000007],cnt[20000004];

void sie(int n)
{
	for (int i=1;i<=n;i++) divs[i]=i;
		int lim=(int)sqrt(n);
	for (int i=2;i<=lim;i++)
	if (!divs[i]) for (int j=i;j<=n;j+=i) divs[j]=i;	
}

void solve(int n)
{
	vector <int> v;
	for (int i=1;i<=n/2+1;i++)
	{
		int k=n/i;
		while (k!=1)
		{
			if (!cnt[divs[k]]) v.push_back(divs[k]);
			cnt[divs[k]]++;
			k/=divs[k];
		}
	}
	int res=1;
	for (int c : v)
	{	
		res=res*(cnt[c]+1)%998244353;
		cnt[c]=0;
	}
	cout << res << '\n';
}
int n;
void sub1()
{
	for (int i=1;i<=n;i++) 
		solve(a[i]);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("FLOOR.INP","r",stdin);
	freopen("FLOOR.OUT","w",stdout);
	cin >> n;
	int mx=0;
	for (int i=1;i<=n;i++) cin >> a[i],mx=max(mx,a[i]);
	sie(mx);
	sub1();
}