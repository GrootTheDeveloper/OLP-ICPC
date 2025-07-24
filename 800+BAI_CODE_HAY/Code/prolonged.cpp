#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a,b,n;
void solve()
{
	int x=-1;
	for (int i=0;i<=9;i++)
	{
		if ((a*10+i)%b==0) {x=a*10+i;break;}
	}
	if (x==-1LL) return cout << x,void();
	cout << x;
	for (int i=1;i<=n-1;i++) cout << '0';
}
signed main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);
	cin >> a >> b >> n;
	solve();


} 