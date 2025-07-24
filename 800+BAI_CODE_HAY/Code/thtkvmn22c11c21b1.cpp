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
int a1,a2,a3,b1,b2,b3; 
int calc()
{
	int res=0;
	for (int i=a1;i<=b1;i++) for (int j=a2;j<=b2;j++) res+=(i*j>=a3 && i*j<=b3);
	return res;
}
void ReadText()
{	
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	int res=0;
	for (int i=a1;i<=b1;i++)
	{
		int l=a3/i+(a3%i!=0),r=b3/i;
		if (r<a2) break;
		if (l>b2) continue;
		res+=min(b2,r)-max(l,a2)+1;
//		cout << i << ' ' << l << ' ' << r << '\n';
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