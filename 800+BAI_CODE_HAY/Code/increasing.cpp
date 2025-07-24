#include <bits/stdc++.h>
using namespace std;
void xuli()
{
    int n,ai,d=0;
    cin >> n;
    map <int,int> f;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        f[ai]+=1;
        if (f[ai]>1)
        d+=1;
    }
    if (d!=0) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        xuli();
    return 0;
}
