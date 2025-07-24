#include <bits/stdc++.h>
using namespace std;
#define int long long 

int pos[200005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1,ai;i<=n;i++)
	{
		cin >> ai;
		pos[ai]=i;
	}
	int res=0;
	pos[0]=n;
	for (int i=1;i<=n;i++) if (pos[i]<pos[i-1]) res++;
	cout << res;
}