#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[3],a[1000005];
int n,k;

string solve()
{
	if (cnt[0]>=k) return "YES";
	if (k%3==0 && (cnt[1]>=k || cnt[2]>=k)) return "YES";
	return "NO";

}
bool f[20];
string ans;
void check()
{
	int sum=0,dem=0;
	for (int i=1;i<=n;i++) sum+=f[i]*a[i],dem+=(f[i]==1);
	if (sum%3==0 && dem==k) ans="YES";
}
void Try(int i)
{
	if (i>n) return check(),void();
	f[i]=1;Try(i+1);
	f[i]=0;Try(i+1);
}
string sub2()
{
	ans="NO";
	Try(1);
	return ans;
	
}
string sub3()
{
	if (cnt[0]>=k) return "YES";
	if (k%3==0 && (cnt[1]>=k || cnt[2]>=k)) return "YES";
	int m=min(cnt[1],cnt[2]);
	if (k%2==0 && m*2>=k) return "YES";
	k=max(0LL,k-m*2);
	cnt[1]-=m;cnt[2]-=m;
	m=max(cnt[1],cnt[2]);
	k-=min(k/3,m/3)*3;
	return ((cnt[0]>=k)? "YES":"NO");
	
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("bai2.inp","r",stdin);
	freopen("bai2.out","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		memset(cnt,0,sizeof(cnt));
		cin >> n >> k;
		for (int i=1;i<=n;i++) cin >> a[i],cnt[a[i]%3]++;
		if (a[1]==a[n]) cout << solve();
		else if (n<=20) cout << sub2();
		else cout << sub3();
		cout << '\n';
		
	}
}