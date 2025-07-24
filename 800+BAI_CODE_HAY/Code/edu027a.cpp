#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
int calc(int n)
{
	int sc=0,sl=0;
	string s=to_string(n);
	for (int i=0;i<s.size();i++)
		if (i&1) sc+=(s[i]-'0');else sl+=(s[i]-'0');
	int si=s.size();
	if (si&1)
	{
		int k=sl-1-sc;
		if (k>=0 && k<=9 && n*10+k>=a && n*10+k<=b) return 1;
	}
	else
	{
		int k=sc+1-sl;
		if (k>=0 && k<=9 && n*10+k>=a && n*10+k<=b) return 1; 
	}
	return 0;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("CHUAN1.inp","r",stdin);
	freopen("CHUAN1.OUT","w",stdout);
	cin >> a >> b;
	int res=0;
	for (int i=1;i<=min((int)1e7,b);i++)
		res+=calc(i);
	cout << res;

}