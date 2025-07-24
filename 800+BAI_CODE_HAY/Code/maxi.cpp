#include <bits/stdc++.h>
using namespace std;
#define int long long 


int n,m,res,ans;
string s1,s2;
vector <int> f[100];

void Try(int i,int pos)
{
	if (i==s2.size()) return res=max(res,ans),void();
	int k=upper_bound(f[s2[i]-'a'].begin(),f[s2[i]-'a'].end(),pos)-f[s2[i]-'a'].begin();
	if (k==f[s2[i]-'a'].size()) return;
	for (int j=k;j<f[s2[i]-'a'].size();j++)
	{
		ans=max(ans,f[s2[i]-'a'][j]-pos);
		Try(i+1,f[s2[i]-'a'][j]);
	}
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	cin >> s1 >> s2;
	for (int i=0;i<s1.size();i++) f[s1[i]-'a'].push_back(i);
	for (int i : f[s2[0]-'a'])
	{
		ans=0;
		Try(1,i);
	}
	cout << res;
}