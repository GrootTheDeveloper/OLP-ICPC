#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;

bool prime[5555];
vector <int> p;
void SIUUUUU(int lim)
{
	for (int i = 2; i <= lim; i++)
		if (!prime[i])
		{
			p.push_back(i);
			for (int j = i * i; j <= lim; j += i) prime[j] = true;
		}
}
int dp[5555];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("ADDPRIME.INP","r",stdin);
	freopen("ADDPRIME.OUT","w",stdout);
	int n; cin >> n;
	SIUUUUU(n);
	dp[0] = 1;
	for (int x : p)
		for (int i = x; i <= n; i++) 
		{
			dp[i] += dp[i - x];
			dp[i] %= mode;
		}
	cout << dp[n];
}