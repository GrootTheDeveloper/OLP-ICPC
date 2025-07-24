#include <bits/stdc++.h>
using namespace std;
#define int long long 

int divs[1000006],f[1000006];
bool prime[3003];
void sie()
{
	for (int i=2;i<=1e6;i++) for (int j=i;j<=1e6;j+=i) divs[j]++;
	prime[1]=true;
	for (int i=2;i<=sqrt(3000);i++) 
		if (!prime[i]) for (int j=i*i;j<=3000;j+=i) prime[j]=true;
	for (int i=1;i<=1e6;i++)
		f[i]=f[i-1]+(!prime[divs[i]+1]);
}



signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	sie();
	while (t--)
	{
		int l,r; cin >> l >> r;
		cout << f[r]-f[l-1] << '\n';
	}	
}