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
	while (true)
	{
		for (int i=1;i<=12;i++) cin >> a[i];
		sort(a+1,a+13);
		if (a[1]==a[12] && a[1]==0) return;
		cout << ((a[1]==a[4] && a[5]==a[8] && a[9]==a[12])? "yes":"no");
		cout << '\n';
	}
}
void solve()
{
	
}

signed main()
{
	fastIO();
	ReadText();
	//solve();
}