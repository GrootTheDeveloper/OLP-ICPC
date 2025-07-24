#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	priority_queue <int> q1,q2;
	int res=0;
	for (int i=1,ai;i<=n;++i) 
	{
		cin >> ai;
		if (ai % 3 == 0) res+=ai;
		if (ai % 3 == 1) 
		{
			if (q2.size()) res+=ai+q2.top(),q2.pop();
			else q1.push(ai);
		}
		if (ai % 3 == 2) 
		{
			if (q1.size()) res+=ai+q1.top(),q1.pop();
			else q2.push(ai);
		}

	}
	while (q1.size()>=3)
		for (int i=1;i<=3;i++) res+=q1.top(),q1.pop();
	while (q2.size()>=3) 
		for (int i=1;i<=3;i++) res+=q2.top(),q2.pop();
	cout << res / 3;
}