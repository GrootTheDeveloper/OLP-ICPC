#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1000006];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int res=0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]>a[i-1]) res+=a[i]-a[i-1];
	}
	cout << res;
}