#include <bits/stdc++.h>
using namespace std;
#define int long long 

priority_queue <int,vector<int>,greater<int>> q;
int a[500005],cnt[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
		q.push(a[i]);
		if (i>=k)
		{
			while (!cnt[q.top()]) q.pop();
			cout << q.top() << '\n';
			cnt[a[i-k+1]]--;
		}
	}


}