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
	int k; cin >> n >> k;
	cout << k/__gcd(n,k);
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