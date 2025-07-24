#include <bits/stdc++.h>
using namespace std;
vector <int> vi;
int a[100005],f[1000006];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        f[a[i]]=i;
    }
    vi.push_back(a[n]);
    for (int i=n-1;i>=1;i--)
    {
        vi.push_back((vi.back()<a[i])?a[i]:vi.back());
    }
    int res=0;
    for (int i=1;i<=n;i++)
    {
        auto it=upper_bound(vi.begin(),vi.begin()+n-i,a[i]);
        res=max(res,f[*it]-i);
    }
    if (res==0) res=-1;
    return cout << res,0;

}
