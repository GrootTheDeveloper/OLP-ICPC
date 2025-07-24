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
void ReadText()
{
	freopen("CAYCANH.INP","r",stdin);
	freopen("CAYCANH.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) if (a[i]!=a[i-1]) cout << a[i] << ' ';
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