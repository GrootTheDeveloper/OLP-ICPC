#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define val first
#define id second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
int f[100005];

priority_queue <ii> q;
void ReadText()
{
	cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i].val;
		a[i].id=i;
	}	
}
void solve()
{
	int mi,ma;
	f[0]=1;
	vector <dta> a;
	for (int i=1;i<=n;i++)
	{

	}
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}