#include <bits/stdc++.h>
using namespace std;
#define int long long 
int res=0,n;
bool f[111];
string s1,s2;

bool dx(string s)
{
	int l=0,r=s.size()-1;
	while (l<r)
	{
		if (s[l]!=s[r]) return false;
		l++;r--;
	}
	return true;
}
void check()
{
	string st;
	for (int i=0;i<s1.size();i++)
		if (f[i]) st.push_back(s1[i]);
	if (st.size()==0) return;
	int l=0,r=0;
	while (l!=st.size())
	{
		while (s2[r]!=st[l] && r!=s2.size()) r++;
		if (r==s2.size()) break;
		else l++;
	}
	if (l==st.size()) 
	{
		if (dx(st)) res=max(res,(int)st.size());
	}
	
}
 void Try(int i)
 {
 	if (i==n) return check(),void();
 	f[i]=1;
 	Try(i+1);
 	f[i]=0;
 	Try(i+1);
 }


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("lcps.inp","r",stdin);
	freopen("lcps.out","w",stdout);
	cin >> s1 >> s2;
	n=s1.size();
	Try(0);
	cout << res;
}