#include <bits/stdc++.h>
using namespace std;
long long a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
		a[i] += a[i - 1] + 10;
	cout << a[n];
}