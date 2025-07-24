#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define int long long
map <int,int> f;
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int q=n;
    while (q--)
    {
        int x,y;
        cin >> x >> y;
        f[y]=n-x+1;
    }
    for (int i=1; i<=n; i++)
        cout << i << " " << f[i] << endl;

}
