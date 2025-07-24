#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
int a[1000006],f[1000006];
unordered_map <int,int> cnt;
void ReadText()
{
	cin >> n;
	cnt[0]=1;
	int res=0;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		f[i]=f[i-1]+a[i];
		if (f[i]%n>=0) res+=cnt[f[i]%n]+cnt[-(n-f[i]%n)];
		else res+=cnt[f[i]%n]+cnt[-(n+f[i]%n)];
		cnt[f[i]%n]++;
	}
	cout << res;
}
void solve()
{
	
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}