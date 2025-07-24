#include <bits/stdc++.h>
using namespace std;
#define int long long 

priority_queue <int,vector<int>,greater<int>> q;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	int ai;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		q.push(ai);
		if ((int)q.size()>k) q.pop();
		if (i>=k)
			cout << q.top() << '\n';
	}
}