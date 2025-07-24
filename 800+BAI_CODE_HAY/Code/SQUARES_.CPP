#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int power(int a, int b)
{
	int res = 1;
	while (b){
		if (b & 1) res = 1ll * res * a % mode;
		a = 1ll * a * a % mode;
		b >>= 1;
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l; cin >> n >> l;
	l = (l * l) % mode;
	cout << 1ll * (1ll * l * (power(4, n + 1) - 1) % mode) * power(3, mode - 2) % mode; 
}