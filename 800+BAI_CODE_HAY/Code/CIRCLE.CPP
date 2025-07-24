#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 21) + 35;

int dp[N][21];
bool prime[50];

void init(){
	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= 40; i++)
	if (!prime[i]) for (int j = i * i; j <= 40; j += i)
		prime[j] = true;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	n <<= 1;
	init();
	int MASK = (1 << (n + 1)) - 2;
	dp[1 << 1][1] = 1;
	for (int mask = 2; mask <= MASK; mask++){
		if (!(mask >> 1 & 1) || (mask >> 0 & 1)) continue;
		for (int p = 1; p <= n; p++){
			if (mask != 2 && p == 1) continue;
			for (int q = 2; q <= n; q++){
				if (mask >> q & 1) continue;
				if (!prime[p + q]){
					int new_mask = mask | (1 << q);
					dp[new_mask][q] += dp[mask][p];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++)
		if (!prime[i + 1]) ans += dp[MASK][i];
	cout << ans;
}