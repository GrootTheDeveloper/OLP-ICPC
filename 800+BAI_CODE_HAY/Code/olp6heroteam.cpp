#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 998244353;
int a[3000], b[3000];
int n;

int S(int x)
{
	return (x > 0) - (x < 0);
}
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}	

void sub1()
{
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
	for (int z = j + 1; z <= n; z++)
	{
		if (a[i] + a[j] <= a[z] || a[i] + a[z] <= a[j] || a[j] + a[z] <= a[i])
			continue;
		ans = (ans + power(a[i] + a[j] + a[z], 1 + abs(S(b[i] - b[j])) + abs(S(b[i] * b[j] - b[i] * b[z] + b[z] * b[z] - b[j] * b[z])))) % mode;
	}
	cout << ans;
}

namespace sub2
{
	#define ii pair<int,int>
	#define fi first
	#define se second

	int v[3000], pre[3000];

	bool check()
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += (b[i] == b[1]);
		return (cnt == n);
	}
	void work()
	{
		
		for (int i = 1; i <= n; i++)
			v[i] = a[i];
		sort(v + 1, v + n + 1);
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + v[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int pos = lower_bound(v + j, v + n + 1, v[i] + v[j]) - v - 1;
			int sum = pre[pos] - pre[j];
			int num = pos - j;
			ans = (ans + (v[i] + v[j]) * num + sum) % mode;
		}
		cout << ans;
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	if (n <= 200)
		sub1();
	else if (sub2::check()) sub2::work();

	//if (sub2::check()) sub2::work();


}