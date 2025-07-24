#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;


bool prime[1000006];
void sie()
{
	prime[1] = true;
	for (int i = 2; i <= 1e3; i++)
	if (!prime[i]) for (int j = i * i; j <= 1e6; j += i)
		prime[j] = true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int t; cin >> t;
	sie();
	while (t--)
	{
		int l, r; cin >> l >> r;
		
	}
}