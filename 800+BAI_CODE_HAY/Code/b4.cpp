#include <bits/stdc++.h>
using namespace std;
#define int long long
bool prime[1000006];
void sie(int lim)
{
	prime[1] = true;
	for (int i = 2; i * i <= lim; i++)
		if (!prime[i]) for (int j = i * i; j <= lim; j += i)
			prime[j] = true;
}

signed main()
{
	int n; cin >> n;
	sie(n);
	int res = 0;
	for (int i = 2; i <= n / 2; i++) res += (!prime[i] && !prime[n - i]);
	cout << res;
}