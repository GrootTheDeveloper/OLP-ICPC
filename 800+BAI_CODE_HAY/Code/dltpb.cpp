#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1e15+7;
map <string,bool> f;
int cnt[100];
string calc(int a, int b)
{
	memset(cnt,0,sizeof(cnt));
	for (int i=2;i<=a;i++)
		while (a%i==0) cnt[i]++,a/=i;
	string s="";
	for (int i=2;i<=97;i++) s=s+" "+to_string(cnt[i]*b);
	return s;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a,b;
	cin >> a >> b;
	int res=0;
	for (int x=2;x<=a;x++)
		for (int y=2;y<=b;y++)
		{
			string k=calc(x,y);
			if (f.find(k)==f.end()) res++,f.insert({k,true});
		}
	cout << res;
}