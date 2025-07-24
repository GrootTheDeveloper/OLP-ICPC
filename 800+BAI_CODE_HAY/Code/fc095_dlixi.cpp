#include <bits/stdc++.h>
using namespace std;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, c; cin >> a >> b >> c;
	int ans = 0;
	for (int i = a; i <= b; i++) ans += (i % c == 0);
	cout << ans;
}