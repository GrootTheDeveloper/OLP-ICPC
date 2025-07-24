#include <bits/stdc++.h>
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int L, int R)
{
	return L + rd() % (R - L + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(NULL);
	int n = Rand(300, 1000);
	for (int i = 1; i <= n; i++)
	{
		int x = Rand(0, 25);
		cout << (char)('a' + x);
	}
}
