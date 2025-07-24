#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l,r;
int divs[1000006],f[1000006];
void sieDivs()
{
	for (int i=1;i<=1e6;i++)
	{
		for (int j=i;j<=1e6;j+=i) divs[j]++;
		f[i]=f[i-1]+divs[i];
	}
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	sieDivs();
	while (t--)
	{
		cin >> l >> r;
		cout << f[r]-f[l-1] << '\n';
	}
}