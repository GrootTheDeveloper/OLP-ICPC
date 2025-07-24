#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int gt[100005];
int power(int a, int b)
{
	int res = 1;
	while (b){
		if (b & 1) res = res * a % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}
int C(int n, int k)
{
	int a = 1, b = 1;
	for (int i = n - k + 1; i <= n; i++)
		a = a * i % mode;
	for (int i = 1; i <= k; i++)
		b = b * i % mode;
	return a * power(b, mode - 2) % mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	for (int i = 1; i <= n; i++){
		int ai; cin >> ai;
		m -= ai;
	}
	if (m < 0) return cout << 0, 0;
	cout << C(m + n - 1, n - 1);
}