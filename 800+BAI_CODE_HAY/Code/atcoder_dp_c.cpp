#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+5;
int a[N],b[N],c[N],da[N],db[N],dc[N];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
	for (int i=1;i<=n;i++)
	{
		da[i]=max(dc[i-1],db[i-1])+a[i];
		db[i]=max(da[i-1],dc[i-1])+b[i];
		dc[i]=max(da[i-1],db[i-1])+c[i];
	}
	cout << max({da[n],db[n],dc[n]});
}