#include <bits/stdc++.h>
using namespace std;
#define int long long 

int su[1000006];
void sang()
{
	for (int i=2;i<=1e6;i++)
	for (int j=i;j<=1e6;j+=i) su[j]++;
}
int calc(int n)
{
	return n*(su[n]+1);
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	sang();
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int ai; cin >> ai;
		res+=calc(ai);
	}
	cout << res;
}