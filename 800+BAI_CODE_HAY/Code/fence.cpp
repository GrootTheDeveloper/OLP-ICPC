#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = 0, a[100005], cnt[100005];
int calc(int n) { return n * (n - 1) / 2;}
void add(int val)
{
	ans -= calc(cnt[val]);
	ans += calc(++cnt[val]);
}
int func(int val)
{
	return ans - calc(cnt[val]) + calc(cnt[val] - 1);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], add(a[i]);
	for (int i = 1; i <= n; i++) cout << func(a[i]) << '\n';
}