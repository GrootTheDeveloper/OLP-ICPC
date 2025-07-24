#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, q;
int a[200005][2];
void sub1()
{
	while (q--)
	{
		int c; cin >> c;
		for (int i = 1; i <= n; i++)
			if (a[i][0] <= c) swap(a[i][0], a[i][1]);
	}
	for (int i = 1; i <= n; i++) cout << a[i][0] << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
	if (n <= 5000 && q <= 5000) sub1();
}