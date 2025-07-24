#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[33],f[2222];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,v; cin >> n >> v;
	for (int i=1;i<=n;i++) cin >> a[i];
	f[0]=1;
	for (int i=1;i<=n;i++)
		for (int j=v;j>=a[i];j--) f[j]=(f[j]||f[j-a[i]]);
	while (!f[v]) v--;
	cout << v;
}