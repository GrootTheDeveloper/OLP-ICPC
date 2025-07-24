#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct dta{
	vector <int> lef,mid,rig;
};
vector <int> oo;
string to(int a) {return to_string(a);}
int a[200005],n;
int calc(vector<int> v)
{
	int sum=v.size();
	sort(v.begin(),v.end());
	int cnt=1,res=0;
	for (int i=1;i<v.size();i++)
	{
		if (v[i]==v[i-1]) cnt++;
		else
		{
			res+=cnt*(sum-cnt);
			sum-=cnt;
			cnt=1;
		}
	}
	return res;
}

void solve()
{
	unordered_map <string,dta> f;
	for (int i=1;i<=n-2;i++)
	{
		f[to(a[i])+' '+to(a[i+1])].rig.push_back(a[i+2]);
		f[to(a[i])+' '+to(a[i+2])].mid.push_back(a[i+1]);
		f[to(a[i+1])+' '+to(a[i+2])].lef.push_back(a[i]);
	}
	int res=0;
	for (int i=1;i<=n-2;i++)
	{
		res+=calc(f[to(a[i])+' '+to(a[i+1])].rig)
			+calc(f[to(a[i])+' '+to(a[i+2])].mid)
			+calc(f[to(a[i+1])+' '+to(a[i+2])].lef);
		f[to(a[i])+' '+to(a[i+1])].rig=f[to(a[i])+' '+to(a[i+2])].mid=f[to(a[i+1])+' '+to(a[i+2])].lef=oo;
	}
	cout << res << '\n';
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=1;i<=n;i++) cin >> a[i];
		solve();
	}
}

////
#include<bits/stdc++.h>
using namespace std;
 
int n;
vector<int> a;
map<tuple<int, int, int>, long long> cnt;
 
void process() {
    cin >> n;
    a.resize(n);
    cnt.clear();
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long res = 0;
    for(int i = 0; i < n - 2; i++) {
        int x = a[i];
        int y = a[i+1];
        int z = a[i+2];
        res += cnt[make_tuple(x, y, 0)];
        res += cnt[make_tuple(x, 0, z)];
        res += cnt[make_tuple(0, y, z)];
        cnt[make_tuple(x, y, 0)]++;
        cnt[make_tuple(x, 0, z)]++;
        cnt[make_tuple(0, y, z)]++;
        res -= 3 * cnt[make_tuple(x, y, z)];
        cnt[make_tuple(x, y, z)]++;
    }
    cout << res << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        process();
    }
}