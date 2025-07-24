#include <bits/stdc++.h>
using namespace std;
#define int long long

int check(int n)
{
	int sum=n;
	while (n) sum+=n%10,n/=10;
	return sum;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n; cin >> m >> n;
	int last=m+n;
	int res=n+1;
	for (int i=max(m,last-10000);i<=last;i++) res-=(check(i)>last);
	cout << res;
}
