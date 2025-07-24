#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool prime[10000002];
void sie()
{
	prime[1]=prime[0]=true;
	int lim=trunc(sqrt(10000000));
	for (int i=2;i<=lim;i++)
	if (!prime[i]) for (int j=i*i;j<=1e7;j+=i) prime[j]=true;	
}
bool cnt[11];
void solve(int n)
{
	vector <int> v;
	if (!prime[n]) cout << "YES";else cout << "NO"; 
	cout << ' ';
	string s=to_string(n);
	for (char c : s)
	{
		int x=c-'0';
		if (!prime[x]) if (!cnt[x]) v.push_back(x),cnt[x]=true;
	}
	if (v.size()==0) cout << 0;
	else for (int c : v) cout << c << ' ',cnt[c]=false;
	cout << '\n';
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	sie();
	int x;
	while(t--)
	{
		cin >> x;
		solve(x);
	}

}