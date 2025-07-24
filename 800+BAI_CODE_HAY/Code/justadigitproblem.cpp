#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1234567891;
int T, l[100005], r[100005], x[100005];
int n, a[20];
int dp[20][11][20];

int calc(int pos, int k, bool lim, int cnt)
{
	if (pos < 1) return cnt;

	if (!lim && dp[pos][k][cnt] != -1) return dp[pos][k][cnt];
	int res = 0;
	int mx = (lim? a[pos] : 9);
	for (int i = 0; i <= mx; i++)
		res = (res + calc(pos - 1, k, lim && i == mx, cnt + (i == k))) % mode;
	if (!lim) dp[pos][k][cnt] = res;
	return res;
}
int p[20];
int G(int k, int x)
{
	n = 0;
	while (x) a[++n] = x % 10, x /= 10;
	int ans = calc(n, k, true, 0);
	if (k != 0) return ans;
	
	for (int i = 1; i < n; i++)
		ans = (ans - i * 9 * p[n - i] + mode * mode) % mode;
	ans = (ans - n + mode) % mode;
	return ans;
}
void sub2()
{
	p[1] = 1;
	for (int i = 2; i <= 18; i++) p[i] = p[i - 1] * 10;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= T; i++)
		cout << (G(x[i], r[i]) - G(x[i], l[i] - 1) + mode * mode) % mode << ' ';
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i = 1; i <= T; i++)
		cin >> l[i] >> r[i] >> x[i];
	sub2();

}