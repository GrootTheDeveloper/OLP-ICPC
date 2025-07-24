#include <bits/stdc++.h>
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	long long ans = 0;
	for (long long i = 5; i <= n; i *= 5)
		ans += n / i;
	cout << ans;
}