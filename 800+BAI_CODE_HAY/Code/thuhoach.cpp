#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[22],f[50005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,c; cin >> n >> c;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	f[0]=true;
	for (int i=1;i<=n;i++)
	for (int j=c;j>=a[i];j--) f[j]=(f[j]||f[j-a[i]]);
	while (!f[c]) c--;
	cout << c;
}