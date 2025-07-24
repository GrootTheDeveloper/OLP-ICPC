#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool nt (int n)
{
	if (n<2) return 0;
	int lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++) if (n%i==0) return 0;
	return 1;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int q; cin >> q;
	while (q--)
	{
		int a; cin >> a;
		if (a==1) {cout << 0 << '\n';continue;}
		cout << (nt(3*a*a-3*a+1)? 1:0) << '\n';
	}
}