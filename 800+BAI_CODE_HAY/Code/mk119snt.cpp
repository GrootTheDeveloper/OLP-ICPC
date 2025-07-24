#include <bits/stdc++.h>
using namespace std;
#define int long long 
int             l,r;
int      f[1000006];
bool prime[1000006];
void o_o()
{
	for (int i=2;i<=1000;i++)
		if (!prime[i]) 
			for (int j=i*i;j<=1e6;j+=i) 
				prime[j]=true;
	for (int i=2;i<=1e6;i++) 
		f[i]=f[i-1]+(!prime[i]);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	o_o();
	while (t--)
	{
		cin >> l >> r;
		cout << f[r]-f[l-1] << '\n';
	}
}  