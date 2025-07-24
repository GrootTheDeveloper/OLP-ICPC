#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a1,b1,a2,b2; cin >> a1 >> b1 >> a2 >> b2;
	if (a1>b1) swap(a1,b1);
	if (a2>b2) swap(a2,b2);
	int m=max({b1,b2,a1+a2});
	cout << m*m;
}
