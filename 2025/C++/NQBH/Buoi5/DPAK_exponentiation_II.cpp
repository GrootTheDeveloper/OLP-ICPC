#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int quick_mod(int a, int n, int MOD = mod) {
	
	if (n == 0) return 1;
 
	int x = quick_mod(a, n / 2);
	x = x * x % MOD;
 
	if (n % 2 == 1) x = x * a % MOD;
	
	return x;
}
 
signed main() {
	int n; cin >> n;
	while (n--) {
		int a, b, c; cin >> a >> b >> c;
		int n = quick_mod(b,c) / mod + quick_mod(b,c); 
        int ans = quick_mod(a,n);
		ans %= mod;
        cout << ans << endl;
	}
	
}