#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[100],cnt[100];

string pl(string &a, string &b)
{
	while (a.size()<b.size()) a="0"+a;
	while (b.size()<a.size()) b="0"+b;
	string res="";
	int nho=0;
	for (int pos=b.size()-1;pos>=0;pos--)
	{
		int k=(a[pos]-'0')+(b[pos]-'0')+nho;
		res=to_string(k%10)+res;
		nho=k/10;
	}
	if (nho) res=to_string(nho)+res;
	return res;
}
void calc()
{
	string res="1";
	for (int i=2;i<=99;i++)
	{
		while (f[i])
		{
			f[i]--;
			string k=res;
			for (int j=1;j<i;j++) res=pl(res,k);
		}
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s; cin >> s;
	int n=s.size();
	memset(f,0,sizeof(f));
	memset(cnt,0,sizeof(cnt));
	for (int i=2;i<=n;i++)
	{
		int m=i;
		for (int k=2;k<=i;k++)
			while (m%k==0) f[k]++,m/=k;
	}
	for (char c : s) cnt[c-'a']++;
	for (int i=0;i<=25;i++)
		for (int j=2;j<=cnt[i];j++)
		{
			int m=j;
			for (int k=2;k<=j;k++)
				while (m%k==0) f[k]--,m/=k;
		}
	
	calc();	
	
}