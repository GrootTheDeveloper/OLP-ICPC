#include <bits/stdc++.h>
using namespace std;
#define int long long 
int s,n,a[200005];
main()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int s=a[(n/2)+1],res=0;
	for (int i=1;i<=n;i++) res+=abs(s-a[i]);
	cout << res;
}