#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[500005];
void o_o(int lim)
{
	for (int i=2;i<=lim;i++)
		for (int j=i*2;j<=lim;j+=i) f[j]+=i;
}
main()
{
	int l,r; cin >> l >> r;
	o_o(r);
	int res=0;
	for (int i=l;i<=r;i++) res+=(f[i]+1>i);
	cout << res;
}