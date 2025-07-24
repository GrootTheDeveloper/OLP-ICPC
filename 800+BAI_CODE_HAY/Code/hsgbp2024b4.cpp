#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
int a[1000006];
bool prime[2000006];
void sie()
{
	prime[1]=1;
	for (int i=2; i<=sqrt(2e6); i++)
		if (!prime[i]) for (int j=i*i;j<=2e6;j+=i) prime[j]=true;
}
void ReadText()
{
	cin >> n;
	int res=0;
	sie();
	for (int i=1;i<=n;i++) cin >> a[i],res+=(!prime[a[i]]);
	cout << res;
}
void solve()
{
	
}

signed main()
{
	fastIO();
	freopen("HOPQUA.INP","r",stdin);
	freopen("HOPQUA.OUT","w",stdout);
	ReadText();
	solve();
}