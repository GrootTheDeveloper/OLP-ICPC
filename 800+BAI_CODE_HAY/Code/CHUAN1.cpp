#include <bits/stdc++.h>
using namespace std;
#define int long long 

bool check(int n)
{
	int sl=0,sc=0;
	string s=to_string(n);
	for (int i=0;i<s.size();i++) 
		if (i&1) sc+=(s[i]-'0');
		else sl+=(s[i]-'0');
	return (sl-sc==1);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("CHUAN1.INP","r",stdin);
	//freopen("CHUAN1.OUT","w",stdout);
	int a,b; cin >> a >> b;
	int res=0;
	for (int i=a;i<=b;i++) res+=check(i);
	cout << res;
}