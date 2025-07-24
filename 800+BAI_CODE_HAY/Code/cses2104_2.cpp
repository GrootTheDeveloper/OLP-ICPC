#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e9+7,base=31;
int power[100005],hashT[100005],n;
vector <int> f[30];
string s,st;


int gethash(int l, int r)
{
	return (hashT[r]-hashT[l-1]*power[r-l+1]+mode*mode)%mode;
}

void solve()
{
	cin >> st;
	int k=(int)st.size(),hp=0;
	for (int i=0;i<k;i++) hp=(hp*base+st[i]-'a')%mode;
	int t=st[0]-'a'+1;
	for (int pos : f[t])
	{
		if (pos+k-1<=n)
		{
			if (gethash(pos,pos+k-1)==hp) return cout << pos << '\n',void();
		}
	}
	cout << -1 << '\n';
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	n=(int)s.size();
	s=' '+s;
	for (int i=1;i<=n;i++)
		f[s[i]-'a'+1].push_back(i);
	power[0]=1;
	for (int i=1;i<=n;i++)
	{
		power[i]=(power[i-1]*base)%mode;
		hashT[i]=(hashT[i-1]*base +(s[i]-'a'))%mode;
	}
	int q;
	cin >> q;
	while (q--)
	{
		solve();
	}
}