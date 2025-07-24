#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int,int>
#define fi first
#define se second
const int mode=1e15+9,N=1e6+7,base=311;
void fastIO(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int n,m;
string a[1000006];
unordered_map <int,int> f;

int hashing(string s)
{
	int res=0;
	for (int i=0;i<s.size();i++)
		res=(res*base + s[i] -'a'+1)%mode;
	return res;
}
void ReadText()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],f[hashing(a[i])]++;
}

void solve()
{
	int res=0;
	for (int l=1;l<=n;l++)
	{
		int hash=0;
		for (int i=0;i<(int)a[l].size()-1;i++) 
		{
			hash=(hash*base + a[l][i] - 'a' +1)%mode;
			res+=f[hash];
		}
	}
	cout << res;
}

signed main()
{
	fastIO();
	ReadText();
	solve();
}