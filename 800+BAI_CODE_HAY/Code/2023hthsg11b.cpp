#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[100005],x,t,cnt,temp;
unordered_map <int,int> f;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		if (f[a[i]]==0) f[a[i]]=i;
	}
	cin >> t;
	temp=t;
	while (t--)
	{
		cin >> x;
		if (f[x]==0) cout << -1 << '\n';
		else cout << f[x] << '\n',cnt++;
	}
	int k=temp-cnt;
	if (k==cnt) cout << 0;
	else if (k>cnt) cout << -1;
	else cout << 1;
}