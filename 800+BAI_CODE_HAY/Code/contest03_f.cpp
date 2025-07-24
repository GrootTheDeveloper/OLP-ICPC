#include <bits/stdc++.h>
using namespace std;
#define int long long  

int a[5];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int x = n;
	for (int i = 1; i <= 4; i++)
	{
		a[i] = (int)sqrt(n);
		n -= a[i] * a[i];
	}

	int A = a[1], B = a[2], C = a[3], D = a[4];
	for (int i = max(0ll, a[1] - 1); i <= a[1] + 1; i++)
	for (int j = max(0ll, a[2] - 1); j <= a[2] + 1; j++)
	for (int s = max(0ll, a[3] - 1); s <= a[3] + 1; s++)
	for (int t = max(0ll, a[4] - 1); t <= a[4] + 1; t++)
	if (abs(x - (i * i + j * j + s * s + t * t)) <= abs(x - (A * A + B * B + C * C + D * D)))
		A = i, B = j, C = s, D = t;
	cout << A << ' ' << B << ' ' << C << ' ' << D;
}