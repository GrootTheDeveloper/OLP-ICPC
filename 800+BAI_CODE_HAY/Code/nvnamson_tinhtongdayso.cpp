#include <bits/stdc++.h>
using namespace std;
#define int long long 

int calc(int l, int r)
{
	if (l > r) return 0;
	return r * (r + 1) / 2 - l * (l - 1) / 2; 
}

signed main()
{
	int n,m; cin >> n >> m;
	int mid = m/2;
	cout << calc(1, mid + (m&1)) + calc(n - mid + 1, n);
}