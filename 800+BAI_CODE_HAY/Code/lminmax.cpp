#include <bits/stdc++.h>
using namespace std;
#define int long long 

priority_queue <int> qmax;
priority_queue <int,vector<int>,greater<int>> qmin;
int a[1000006];
unordered_map <int,int> f; 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,delta; cin >> n >> delta;
	for (int i=1;i<=n;i++) cin >> a[i];
	int l=1,ans=0;
	for (int i=1;i<=n;i++)
	{
		qmax.push(a[i]);
		qmin.push(a[i]);
		f[a[i]]++;
		while (true)
		{
			while (f[qmin.top()]==0) qmin.pop();
			while (f[qmax.top()]==0) qmax.pop();
			if (qmax.top()-qmin.top() > delta) f[a[l++]]--;
			else break;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
}