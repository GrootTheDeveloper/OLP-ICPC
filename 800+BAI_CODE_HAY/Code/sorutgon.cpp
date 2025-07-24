#include <bits/stdc++.h>
using namespace std;
#define int long long


int g(int x)
{
	int k=x%9;
	return 45*(x/9)+k*(k+1)/2;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a,b; cin >> a >> b;
	cout << g(b)-g(a-1);
}