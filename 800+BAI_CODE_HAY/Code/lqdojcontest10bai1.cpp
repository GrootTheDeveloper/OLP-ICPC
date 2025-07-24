#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[255];
signed main()
{
	string s; getline(cin,s);
	string st="Chuc mung sinh nhat LQDOJ";
	int res=0;
	for (char c : s) cnt[(int)c]++;
	
	for (char c : st)
	{ 
		res+=(cnt[(int)c]<=0);
		cnt[(int)c]--;
	}
	cout << res;
}