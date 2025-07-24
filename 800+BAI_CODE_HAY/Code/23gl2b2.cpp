#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7;
int a[200005];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int s=0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		s+=a[i];
	}
	int res=0;
	for (int i=1;i<=n;i++)
	{
		s-=a[i];
		res=(res+(a[i]%mode)*(s%mode))%mode;
	}
	cout << res;
}