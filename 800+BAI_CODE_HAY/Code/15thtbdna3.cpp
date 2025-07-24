#include <bits/stdc++.h>
using namespace std;
#define int long long 
int t1,t2,a[1000001];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		t2+=a[i];
	}
	int res=1,min_=1e9;
	for (int i=1;i<=n-1;i++)
	{
		t1+=a[i];
		t2-=a[i];
		if (abs(t1-t2)<min_) min_=abs(t1-t2),res=i;

	}
	cout << res;
}