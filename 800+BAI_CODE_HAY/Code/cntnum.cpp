#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> f[100005];
int a[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		f[a[i]].push_back(i);
	}
	int x; 
	while (k--)
	{	
		cin >> x;
		int pos=lower_bound(f[a[x]].begin(),f[a[x]].end(),x)-f[a[x]].begin();
		cout << pos-0 << ' ' << f[a[x]].size()-pos-1 << '\n';
	}
}