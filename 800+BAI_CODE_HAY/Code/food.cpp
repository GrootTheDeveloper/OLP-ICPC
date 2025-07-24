#include <bits/stdc++.h>
using namespace std;
#define int long long 

int flag[1000005],c[100005],d[100005];
priority_queue <int,vector<int>,greater<int>> q;
int getmin()
{
	while (!flag[q.top()]) q.pop();
	return q.top();
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=1;i<=n;i++)
	{
		q.push(c[i]);
		flag[c[i]]++;
		d[i]=d[i-1] + 2*getmin();
		if (i>=k) flag[c[i-k+1]]--;
	}
	cout << d[n];
}