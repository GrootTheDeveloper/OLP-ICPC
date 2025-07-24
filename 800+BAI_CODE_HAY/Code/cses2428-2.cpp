#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> f;
int cnt,a[200005];
void push(int val) {f[val]++;cnt+=(f[val]==1);}
void pop (int val) {f[val]--;cnt-=(f[val]==0);}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=1,res=0;
    for (int i=1;i<=n;i++)
    {
        push(a[i]);
        while (cnt>k) pop(a[l]),l++;
        res+=i-l+1;
    }
    cout << res;
}
