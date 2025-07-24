#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[100005],ai,res;
int s;
deque <int> q;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,t; cin >> n >> t;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		s+=ai;
		q.push_back(ai);
		while (s>t)
		{
			s-=q.front();
			q.pop_front();
		}
		res=max(res,(int)q.size());
		/*f[i]=f[i-1]+ai;
		if (f[i]<=t) res=i;
		else
			res=max(res,i-(lower_bound(f+1,f+i+1,f[i]-t)-f));*/


	}
	cout << res;
}