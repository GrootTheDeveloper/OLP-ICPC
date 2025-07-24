#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define cost first
#define cnt second 

ii a[100005];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, val; cin >> n >> val;
	for (int i = 1; i <= n; i++)
		cin >> a[i].cost >> a[i].cnt;
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int b = min(val / a[i].cost, a[i].cnt);
		res += b;
		val -= b * a[i].cost;
	}
	cout << res;
}