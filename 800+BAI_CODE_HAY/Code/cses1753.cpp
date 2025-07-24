#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[1000006];
string s,st;

bool check(int x, int y)
{
	int l=x,r=y;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (s[mid]!=st[mid-x]) return 0;
		r=mid-1;
	}
	l=x,r=y;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (s[mid]!=st[mid-x]) return 0;
		l=mid+1;
	}
	return true;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> s;
	cin >> st;
	for (int i=1;i<=s.size();i++) f[i]=f[i-1]+(int)s[i-1];
	int sum=0,n=st.size()-1,res=0;
	for (char c:st) sum+=(int)c;
	char first=st[0],last=st.back();
	for (int i=0;i<s.size()-n;i++)
		if (s[i]==first && s[i+n]==last && f[i+n+1]-f[i]==sum) res+=check(i,i+n);
	cout << res;
}