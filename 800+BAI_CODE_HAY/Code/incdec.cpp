#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	int a, b, c; cin >> a >> b >> c;
	cout << max({a * b, b * c, a * c});
}