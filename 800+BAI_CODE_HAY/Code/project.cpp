#include <bits/stdc++.h>
using namespace std;
#define int long long 
int c[00033],
	p[00033];
int f[30003];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,s; cin >> n >> s;
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=1;i<=n;i++) cin >> p[i];
	for (int i=1;i<=s;i++) f[i]=INT_MIN;
	
	for (int i=1;i<=n;i++) 
		for (int j=s;j>=c[i];j--)
			if (f[j-c[i]]!=INT_MIN)
				f[j]=max(f[j],f[j-c[i]]+p[i]);
	int res=0;
	for (int i=1;i<=s;i++) res=max(res,f[i]);
	cout << res;
}