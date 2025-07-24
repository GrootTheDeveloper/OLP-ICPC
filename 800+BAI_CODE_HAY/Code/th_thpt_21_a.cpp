#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("bai1.inp","r",stdin);
	freopen("bai1.out","w",stdout);
	int n,a,b; cin >> n >> a >> b;
	if (b<=a)  cout << a-b << ' ' << a;
	else cout << 0 << ' ' << a; 
}