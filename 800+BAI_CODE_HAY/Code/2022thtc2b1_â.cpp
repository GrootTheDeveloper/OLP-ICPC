#include <bits/stdc++.h>
using namespace std;
#define int long long 

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("THAPPHAN.INP","r",stdin);
	freopen("THAPPHAN.OUT","w",stdout);
	double n; cin >> n;
	if (round(n)-0.5==n) cout << round(n)-1; 
	else cout << round(n);
}