#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct dta{
	int cnt=0,last=0;
}d[20];
int a[20];
void init()
{
	for (int i=1;i<=15;i++) a[i]=pow(10,i);
d[1].cnt=9;d[1].last=9;
d[2].cnt=18;d[2].last=9;
d[3].cnt=108;d[3].last=99;
d[4].cnt=198;d[4].last=99;
d[5].cnt=1098;d[5].last=999;
d[6].cnt=1998;d[6].last=999;
d[7].cnt=10998;d[7].last=9999;
d[8].cnt=19998;d[8].last=9999;
d[9].cnt=109998;d[9].last=99999;
d[10].cnt=199998;d[10].last=99999;
d[11].cnt=1099998;d[11].last=999999;
d[12].cnt=1999998;d[12].last=999999;
d[13].cnt=10999998;d[13].last=9999999;
d[14].cnt=19999998;d[14].last=9999999;
d[15].cnt=19999999;d[15].last=10000000;
}
int opmz(int fi, int &n, int lim)
{
	int res=0;
	//vector <int> v;
	for (int i=fi+1;true;i++)
	{
		int m1=i,m2=i;
		string s=to_string(i);
		m2=m2*10+s.back()-'0';
		for (int i=s.size()-2;i>=0;i--) m1=m1*10+s[i]-'0',m2=m2*10+s[i]-'0';
		if (m1>n) break;
		res+=(m1<=n && m1>lim)+(m2<=n && m2>lim);
		//if (m1<=n) v.push_back(m1);
		//if (m2<=n) v.push_back(m2);
	}
	//sort(v.begin(),v.end());
	//for (int c : v) cout << c << ' ';
	//cout << '\n';
	return res;
}
int calc(int n)
{
	int idx=upper_bound(a+1,a+16,n)-a-1;
	int res=d[idx].cnt;
	return res + opmz(d[idx].last/1000,n,a[idx]);
}
signed main()
{
	init();
	int a,b; cin >> a >> b;
	cout << calc(b)-calc(a-1);
}