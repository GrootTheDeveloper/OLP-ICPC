#include <bits/stdc++.h>
using namespace std;
#define int long long 

int lcm(int a, int b)
{
	return a * b / __gcd(a, b);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	int cnt1 = n / a, cnt2 = n / b, cnt3 = n /lcm(a, b);
	cout << (cnt1 - cnt3) * c + (cnt2 - cnt3) * d + cnt3 * max(c,d);
}