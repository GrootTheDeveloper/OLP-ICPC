#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int a,b; cin >> a >> b;
	int x=(a+b)/2;
	int y=a-x;
	cout << x << ' ' << y;
}