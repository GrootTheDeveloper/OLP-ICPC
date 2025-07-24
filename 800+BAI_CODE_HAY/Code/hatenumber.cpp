#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[1111];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t; cin >> t;
	int k=0;
	for (int i=1;k<1000;i++)
		if (i%3!=0 && i%10!=3) a[++k]=i;
	for (int i=1,x;i<=t;i++) cin >> x,cout << a[x] << '\n';
}