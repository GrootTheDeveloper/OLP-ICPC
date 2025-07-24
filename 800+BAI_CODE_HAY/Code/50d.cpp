#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
int res;
const int mode=998244353;
bool check()
{
	for (int i=0;i<(int)s.size()-2;i++) if (s[i]==s[i+2]) return 1;
	return 0;
}
void Try(int i)
{
	if (i==(int)s.size()) return res+=check(),void();
	if (s[i]!='?') Try(i+1);
	else for (char c='a';c<='z';c++) s[i]=c,Try(i+1);
}
void sub2()
{
	Try(0);
	cout << res;
}

void sub1()
{
	if (check()) return cout << 26,void();
	if (s[0]=='?' || s.back()=='?') return cout << 1,void();
	cout << 2;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("PALIN.INP","r",stdin);
	freopen("PALIN.OUT","w",stdout);
	cin >> s;
	int cnt=0;
	for (char c : s) cnt+=(c=='?');
	if (cnt==0) return cout << 0,0;
	if (cnt==1) sub1();
	else if (s.size()<=20) sub2();
	
}