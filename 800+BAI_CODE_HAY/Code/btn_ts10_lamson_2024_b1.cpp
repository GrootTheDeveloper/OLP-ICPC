#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int l,r; cin >> l >> r;
	while (l&1) l++;
	while (r&1) r--;
	if (r<l) return cout << 0,0;
	cout << ((r-l)/2+1)*(l+r)/2;
}