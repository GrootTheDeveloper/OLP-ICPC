#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e9+7,N=1e6+7;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
int a[1000006];
string s;
int w;

int dec(int id, int k)
{
	int cnt=0,couts=0,res=0;
	while (cnt<k && id>=1)
	{
		if (s[id]=='X') couts++;
		else cnt++,res+=couts;
		id--;
	}
	if (cnt==k) return res;
	return (int)1e9;
}
int asc(int id, int k)
{
	int cnt=0,couts=0,res=0;
	while (cnt<k && id<=n)
	{
		if (s[id]=='X') couts++;
		else cnt++,res+=couts;
		id++;
	}
	if (cnt==k) return res;
	return (int)1e9;

}
void solve()
{
	s="O"+s;
	//cout << s << ' ';
	n=s.size()-1;
	int res=1e9;
	w--;
	for (int i=1;i<=n;i++)
		if (s[i]=='.')
			for (int k1=1;k1<=w;k1++)
				res=min(res,dec(i-1,k1)+asc(i+1,w-k1));
	if (res==1e9) res=0;
	cout << res << '\n';
	
	
}
void ReadText()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> s >> w;
		solve();
	}
}
signed main()
{
	fastIO();
	ReadText();
	//solve();
}