#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cnt[30];
char a[40];
void solve(string s)
{
	memset(cnt,false,sizeof(cnt));
	for (char c : s) cnt[c-'a']=true;
	int k=0;
	for (int i=0;i<=25;i++) 
		if (cnt[i]) k++,a[k]=(char)(i+'a');
	unordered_map <char,char> f;
	int l=1,r=k;
	while (l<=r)
	{
		f[a[l]]=a[r];
		f[a[r]]=a[l];
		r--;l++;
	}
	for (char c : s) cout << f[c];
	cout << '\n';
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	string s;
	int n;
	while (t--)
	{
		cin >> n;
		cin >> s;
		solve(s);
	}
}