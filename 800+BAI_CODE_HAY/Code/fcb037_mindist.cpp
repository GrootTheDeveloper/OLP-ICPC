#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int res=INT_MAX;
	int n,ai; cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> ai;
		if (f[ai]) res=min(res,i-f[ai]);
		f[ai]=i;
	}
	if (res==INT_MAX) res=-1;
	cout << res;
}