#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("bai1.inp","r",stdin);
	freopen("bai1.out","w",stdout);
	int a,b,k; cin >> a >> b >> k;
	if (k%2==0  && (b/k-(a-1)/k)%2==0) cout << "YES";
	else cout << "NO";
}