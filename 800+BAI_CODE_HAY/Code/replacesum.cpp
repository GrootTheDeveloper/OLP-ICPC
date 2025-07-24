#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[2000005];


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	priority_queue <int, vector<int>,greater<int>> q;
	int n,sum=0; cin >> n;	
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
		q.push(a[i]);
	}
	cout << sum << ' ';
	int res=0;
	while (q.size()!=1)
	{
		int t=q.top();
		q.pop();
		t+=q.top();
		q.pop();
		q.push(t);
		res+=t;

	}
	cout << res;
	
}