#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	int res=0;
	res+=min(5LL,n)*8000;
	n=max(0LL,n-5);
	res+=min(5LL,n)*10000;
	n=max(0LL,n-5);
	res+=min(5LL,n)*14000;
	n=max(0LL,n-5);
	res+=min(5LL,n)*20000;
	n=max(0LL,n-5);
	res+=n*30000;
	cout << res+res/10;
}