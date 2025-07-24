#include <bits/stdc++.h>
using namespace std;
#define int long long
const int lim=1e18;
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int cnt=0;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		cnt+=(a[i]==0);
	}
	if (cnt) return cout << 0,0;
	int s=1;
	for (int i=1;i<=n;i++)
	{
		if (lim/a[i]>=s) s*=a[i];
		else
		{
			s=-1;
			break;
		}
	}
	cout << s;
}