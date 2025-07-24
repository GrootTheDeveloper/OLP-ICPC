#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	int n; cin >> n;
	set <int> s;
	int lim = sqrt(n);
	for (int i = 2; i <= lim; i++)
		while (n % i == 0) s.insert(i), n/=i;
	if (n != 1) s.insert(n);
	cout << s.size();
}