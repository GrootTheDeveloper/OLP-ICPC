#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
unordered_map <int,int> cnt;
set <int> s;
int a[1000006], gt[1000006];
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (res * a) % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s.insert(a[i]), cnt[a[i]]++;
	gt[0] = 1; for (int i = 1; i <= n; i++) gt[i] = gt[i - 1] * i % mode;
	int res = 1;
	for (int i = 1; i <= n; i++) res = (res * i) % mode;
	int m = 1;
	for (int x : s) m = (m * gt[cnt[x]]) % mode;
	cout << res * power(m, mode - 2) % mode;

}