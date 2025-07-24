#include <bits/stdc++.h>
using namespace std;
#define int long long

bool prime[1000006];
void sie()
{
	prime[1]=true;
	for (int i=2;i<=1000;i++) if (!prime[i])
	for (int j=i*i;j<=1e6;j+=i) prime[j]=true;
}
int dn(int n)
{
	int res=0;
	while (n) res=res*10+n%10,n/=10;
	return res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	sie();
	int res=0;
	for (int i=2;i<=n;i++) res+=(!prime[dn(i)]);
	cout << res;
}