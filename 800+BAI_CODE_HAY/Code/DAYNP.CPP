#include <bits/stdc++.h>
using namespace std;
#define int long long

int rot(int pos, int step)
{
	if (pos == 1 && step == 0) return 1;
	return (pos & 1? rot(pos / 2 + 1, step - 1) : (1 ^ rot(pos / 2, step - 1)));
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	cout << rot(k, n);
}