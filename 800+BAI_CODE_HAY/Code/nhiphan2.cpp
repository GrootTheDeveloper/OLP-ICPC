#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[20],cnt;

void out()
{
	for (int i=n;i>=1;i--) cout << a[i];
	cout << endl;
}
void Try(int i)
{
	if (i==n+1) return cnt++,cout << cnt << ' ',out(),void();
	a[i]=0;
	Try(i+1);
	a[i]=1;
	Try(i+1);
}



main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	Try(1);
}