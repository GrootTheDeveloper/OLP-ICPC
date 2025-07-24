#include <bits/stdc++.h>
using namespace std;
#define int long long 

int f[1000006];

void init()
{
	for (int i = 1; i <= 1000006; i++)
		f[i] = f[i-1] + i * (i + 2);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	init();
	for (int n; t; t--) cin >> n, cout << f[n] << '\n';
}