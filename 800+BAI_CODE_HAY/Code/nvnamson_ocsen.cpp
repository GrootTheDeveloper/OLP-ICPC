#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	int a,b,v; cin >> a >> b >> v;
	int k = a - b;
	cout << (v - b) / k + ((v - b) % k != 0);
	
}