#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[555];
bool f[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	int s=0;
	for (int i=1;i<=n;i++) cin >> a[i],s+=a[i];

	sort(a+1,a+n+1);
	f[0]=true;
	for (int i=1;i<=n;i++)
	for (int j=s;j>=a[i];j--) f[j]=(f[j]||f[j-a[i]]);
	int res=0;
	for (int i=1;i<=s;i++)
		
}