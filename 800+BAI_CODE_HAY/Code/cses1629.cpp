#include <bits/stdc++.h>
using namespace std;

struct dt{
    int bg,ed;
};

dt h[200005];
bool cmp (dt a, dt b)
{
    return a.ed<b.ed;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> h[i].bg >> h[i].ed;
    }
    sort(h+1,h+n+1,cmp);
    int res=0,i=0;
    for (int j=1;j<=n;j++)
    {
        if (h[j].bg>=h[i].ed) res++,i=j;
    }
    cout << res;
    return 0;

}
