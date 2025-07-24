#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,s=0; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],s+=a[i];
	int sum=INT_MAX,x=0;
	for (int i=1;i<=n;i++)
		if (sum>abs(a[i]*n-s)) sum=abs(a[i]*n-s),x=a[i];
	int res=0;
	for (int i=1;i<=n;i++) res+=pow(abs(x-a[i]),2);
	cout << res; 
}