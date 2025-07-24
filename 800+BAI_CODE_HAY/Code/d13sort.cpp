#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ss(int a, int b)
{
	return to_string(a)>to_string(b);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a,b; cin >> a >> b;
	vector <int> v;
	v.push_back(0);
	int res=0;
	for (int i=a;i<=b;i++)
	{
		if (ss(v.back(),i))
		{
			res++;
			while (ss(v.back(),i)) v.pop_back();
		}
		v.push_back(i);
	}
	cout << res;
}