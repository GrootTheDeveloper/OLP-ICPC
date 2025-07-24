#include <bits/stdc++.h>
using namespace std;
#define int long long 
int pre[5][100005], cnt[100005], d[6];
int P(int a, int b)
{
	int res = 1;
	for (int i = 1; i <= b; i++) res = res * a;
	return res;
}

void init()
{
	d[1] = 1e5, d[2] = 1e4, d[3] = 1e3, d[4] = 5e2;
	for (int i = 1; i < 5; i++)
	for (int j = 1; j <= d[i]; j++)
		pre[i][j] = pre[i][j - 1] + P(j, i);
}

void Set(int n, int k, int id)
{
	
	int pos = id;
	while ((pre[k][pos] - n) % 2 == 1) pos--;
	cnt[1]++, cnt[pos + 1]--;
	cout << pre[k][pos] << ' ' << n << '\n';
	if (pre[k][pos] != n)
		Set((pre[k][pos] - n) / 2, k, pos - 1);

}
void solve()
{
	int n, k; cin >> n >> k;
	memset(cnt, 0, sizeof(cnt));
	Set(n, k, d[k]);
	// for (int i = 1; i <= d[k]; i++)
	// 	cnt[i] += cnt[i - 1];
	// for (int i = 1; cnt[i] > 0; i++)
	// 	cout << (cnt[i] & 1? '+' : '-');
	// cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	int t; cin >> t;
	while (t--) solve();
	//for (int i = 1; i <= 10; i++) cout << pre[2][i] << ' ';
}