#include <bits/stdc++.h>
using namespace std;
mt19937_64 rd(time(NULL));
int n, a[1000005], cnt[22][1000005], p[22];


void load_input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void init()
{
	for (int i = 1; i <= n; i++){
		for (int mask = 0; mask <= 20; mask++)
			cnt[mask][i] = cnt[mask][i - 1] + (a[i] >> mask & 1);
	}
	p[0] = 1;
	for (int i = 1; i <= 20; i++)
		p[i] = p[i - 1] * 2;
}
long long calc_output()
{
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		for (int mask = 0; mask <= 20; mask++){
			if (cnt[mask][i] - cnt[mask][i - 1])	
				ans += 1ll * ((n - i) - (cnt[mask][n] - cnt[mask][i])) * p[mask];
			else
				ans += 1ll * (cnt[mask][n] - cnt[mask][i]) * p[mask];
		}
	}
	return ans;
}
long long test()
{
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		ans += (a[i] ^ a[j]);
	return ans;
}

int Rand(int L, int R)
{
	return L + rd() % (R - L + 1);
}
void gen()
{
	n = Rand(500, 1000);
	for (int i = 1; i <= n; i++)
		a[i] = Rand(1, 1000000);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	load_input();
	init();
	cout << calc_output();
	//test();
}