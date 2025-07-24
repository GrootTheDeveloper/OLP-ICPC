#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int base = 311;
const int mode = 1e9 + 7;
const int MODE = 1e15 + 37;
string s,st;
unordered_map <int,bool> f;
int dp[5555];



int val_hash()
{
	int val=0;
	for (int c : st) val=(val*base + (c - 'a') +1)%MODE; 
	return val;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	int n=s.size();
	s="#"+s;
	int k; cin >> k;
	for (int i=1;i<=k;i++)
	{
		cin >> st;
		f.insert({val_hash(),true});
		//cout << val_hash() << ' ';
	}
	//cout << '\n';
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{	
		int hash=0;	
		for (int j=i;j<=n;j++)
		{
			hash=(hash*base + (s[j]-'a')+1)%MODE;
			//cout << hash << ' ';
			if (f.find(hash)!=f.end()) dp[j]=(dp[j]+dp[i-1])%mode;
		}
	}
		
	
	cout << dp[n];
	//cout << gethash(1,2) << ' ' << gethash(1,4);

}