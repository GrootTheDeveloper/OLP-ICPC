#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[7000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int lim = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		if (ai <= n + 1) a[++lim] = ai;
	}
	int res = 0;
	sort(a + 1, a + lim + 1);
	for (int i = 1; i <= lim; i++)
		if (a[i] <= i + 1) res = i;
	cout << res + 1;		

}