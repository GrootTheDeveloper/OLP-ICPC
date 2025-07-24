#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	int a,b,c; cin >> a >> b >> c;
	if (a<b) swap(a,b);
	if (a<c) swap(a,c);
	if (b<c) swap(b,c);
	cout << a << b << c;
}