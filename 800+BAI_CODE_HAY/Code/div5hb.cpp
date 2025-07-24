#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[10],a[100005];
void solve()
{
	memset(cnt,0,sizeof(cnt));
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],cnt[a[i]%5]++;
	int res=0;
	res+=cnt[0];
	int dic;
	dic=min(cnt[1],cnt[4]);
	res+=dic;
	cnt[1]-=dic;cnt[4]-=dic;
	dic=min(cnt[3],cnt[2]);
	res+=dic;
	cnt[3]-=dic;cnt[2]-=dic;
	dic=min(cnt[1],cnt[2]/2);
	res+=dic;
	cnt[1]-=dic;cnt[2]-=2*dic;
	dic=min(cnt[1]/2,cnt[3]);
	res+=dic;
	cnt[1]-=dic*2;cnt[3]-=dic;
	dic=min(cnt[4]/2,cnt[2]);
	res+=dic;
	cnt[4]-=dic*2;cnt[2]-=dic;
	dic=min(cnt[4],cnt[3]/2);
	res+=dic;
	cnt[4]-=dic;cnt[3]-=dic*2;
	dic=min(cnt[3]/2,cnt[1]);
	res+=dic;
	cnt[3]-=dic*3;cnt[1]-=dic;
	dic=min(cnt[1]/3,cnt[2]);
	res+=dic;
	cnt[1]-=dic*3;cnt[2]-=dic;
	dic=min(cnt[2]/3,cnt[4]);
	res+=dic;
	cnt[2]-=dic*3;cnt[4]-=dic;
	dic=min(cnt[2]/3,cnt[1]/4);
	res+=dic;
	cnt[2]-=dic*3;cnt[1]-=dic*4;
	res+=cnt[1]/5+cnt[2]/5;
	cout << res << '\n';

}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int q; cin >> q;
	while (q--) solve();
}