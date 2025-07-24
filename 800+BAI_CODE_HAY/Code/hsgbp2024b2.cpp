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
	freopen("DEMSO.INP","r",stdin);
	freopen("DEMSO.OUT","w",stdout);
	string s; cin >> s;
	int res=0;
	for (char c : s) res+=(c>='0' && c<='9');
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