#include <bits/stdc++.h>
using namespace std;
#define int long long 

string v,h;
int cnt[11];


bool check()
{
	for (int i=0;i<=9;i++)
	for (int j=0;j<=9;j++)
	for (int z=0;z<=9;z++)
	{
		if ((i+j+z)%4==0)
		{
			cnt[i]--;cnt[j]--;cnt[z]--;
			if (cnt[i]>=0 && cnt[j]>=0 && cnt[z]>=0)
			{
				cnt[i]++;cnt[j]++;cnt[z]++;
				return true;
			}
			cnt[i]++;cnt[j]++;cnt[z]++;
		}
	}
	return false;
}
void sub()
{
	memset(cnt,0,sizeof(cnt));
	for (char c : v) cnt[(int)(c-'0')]++;
	if (check()) cout << 0 <<'\n';
	cout << 1 << '\n';
}
bool kt(int n)
{

	memset(cnt,0,sizeof(cnt));
	while(n!=0) cnt[n%10]++,n/=10;
	if (check()) return 0;
	return 1;

}
int f[1000006];
void o_o()
{
	for (int i=1;i<=1e6;i++)
		f[i]=f[i-1]+kt(i);
}
void sub2()
{
	int l=stoll(v),r=stoll(h);
	cout << f[r]-f[l-1] << '\n';
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("numero.inp","r",stdin);
	freopen("numero.out","w",stdout);
	int p; cin >> p;
	o_o();
	while (p--)
	{
		cin >> v >> h;
		if ((int)v.size()<=6ll) sub2();
		else sub();
	}

}