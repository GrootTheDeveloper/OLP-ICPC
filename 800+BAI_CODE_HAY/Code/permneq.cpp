#include <bits/stdc++.h>
using namespace std;
#define int long long 

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 	int n; cin >> n;
 	for (int i=2*(n/2);i>0;i-=2) cout << i << ' ';
 	for (int i=1;i<=n;i+=2) cout << i << ' ';
}