#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,idx;
string s;
void add(int a, int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=(res*a);
		a=a*a;
		b/=2;
		if (res+idx>=k)
		{
			idx=k;
			return;
		}
	}
	idx+=res;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> s;
	cin >> n >> k;
	for (char c : s)
	{
		add((int)(c-'0'),n);
		if (idx==k) return cout << c,0;
	}
}