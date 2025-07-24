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
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cout << ((n%2==0 || n%3==0 || n==1 || n%5==0)? "first":"second")<< '\n';
	}
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