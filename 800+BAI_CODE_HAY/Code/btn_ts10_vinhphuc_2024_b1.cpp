#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	int n,a; cin >> a >> n;
	int m=n/a + (n%a!=0);
	int k= ((n%a==0)? a:n%a);
	if (m==1) cout << k << ' ' << 0;
	if (m==2) cout << a << ' ' << k;
	if (m==3) cout << a-k << ' ' << a;
	if (m==4) cout << 0 << ' ' << a-k;
}