#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	int n,m; cin >> n >> m;
	cout << m * (n / m + (n % m != 0)) - n;
}