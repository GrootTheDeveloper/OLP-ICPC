#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int m,n,p; cin >> m >> n >> p;
	int res=0;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++)
		if ((i+j)*2>=p) res+=(m-i+1)*(n-j+1);
	cout << res;
}