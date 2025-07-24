#include <bits/stdc++.h>
using namespace std;
unordered_map <int,int> f;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	s='0'+s;
	int sum=0,res=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='0') sum--;
		else sum++;
		if ( sum==0) res=max(res,i);
		else
		{
			if (f[sum]==0) f[sum]=i;
			else res=max(res,i-f[sum]);
		}
	}
	cout << res;
}
