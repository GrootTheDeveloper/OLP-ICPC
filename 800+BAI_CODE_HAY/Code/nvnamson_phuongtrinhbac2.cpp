#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, a[100005];

void sub1()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int z = 1; z <= n; z++)
				res += (a[i] - a[j] + a[z] == 0 && i != j && i != z && j != z);
	cout << res << ' ';
}
void sub2()
{
	int res = 0;
	unordered_map <int, int> f;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) f[a[i] + a[j]]++;
	for (int i = 1; i <= n; i++)
		if (f.find(a[i]) != f.end()) res += 2 * f[a[i]];
	cout << res << ' ';
}
void sub3()
{
	int res = 0;
	for (int i = 1; i <= n; i++) res += (i - 2 + (i&1));
	cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 300) sub1();
	else if (n <= 3000) sub2();
	else sub3();
}