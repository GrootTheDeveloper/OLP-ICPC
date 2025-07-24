#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> f;
int cnt,a[200005];
void add(int val) { f[val]++, cnt+=(f[val]==2);}
void del(int val) { f[val]--, cnt-=(f[val]==1);}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    int l=1,res=-1;
    for (int i=1;i<=n;i++)
    {
        add(a[i]);
        while (cnt)
            del(a[l++]);
        res=max(res,i-l+1);
    }
    cout << res;

}
