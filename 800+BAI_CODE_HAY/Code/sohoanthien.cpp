#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int cnt=0;
	int ai;
	for (int i=1;i<=n;i++) cin >> ai,cnt+=(ai==4);
	cout << n + cnt;
}