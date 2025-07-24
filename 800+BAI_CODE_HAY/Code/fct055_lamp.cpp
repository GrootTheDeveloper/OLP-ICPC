#include <bits/stdc++.h>
using namespace std;
int n,q,x,y;
bool bit[100005];
main()
{
    cin >> n >> q;
    while (q--)
    {
        cin >> x >> y;
        for (int i=x;i<=y;i++) bit[i]=(!bit[i]);

    }
    for (int i=1;i<=n;i++) cout << bit[i] << ' ';
}
