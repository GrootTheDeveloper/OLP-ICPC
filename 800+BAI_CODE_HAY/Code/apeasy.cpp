#include <bits/stdc++.h>
using namespace std;
#define int long long 

string s;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("APEASY.INP","r",stdin);
	freopen("APEASY.OUT","w",stdout);
	cin >> s;
	int cnt=0;
	int n=0,m=0;
	for (char c : s) cnt+=(c=='-');
	int idx=0;
	while (s[idx]!='+' && s[idx]!='-') n=n*10+(s[idx]-'0'),idx++;
	
	idx=s.size()-1;
	int pos=1;
	while (s[idx]!='+' && s[idx]!='-')
	{
		m=(s[idx]-'0')*pos+m;
		pos*=10;
		idx--;
	}
	if (cnt&1) cout << n-m;
	else cout << n+m;
	return 0;

}