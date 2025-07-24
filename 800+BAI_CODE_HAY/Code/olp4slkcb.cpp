#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(int a, int b, int type)
{
    if (type==1) a=a*10+1;
    else a*=2;
    if (a==b) return true;
    if (a>b) return false;
    bool m=ck(a,b,1);
    bool n=ck(a,b,2);
    return (m||n);

}

main()
{
    int q; cin >> q;
    while (q--)
    {
        int a,b; cin >> a >> b;
        bool m=ck(a,b,1);
        bool n=ck(a,b,2);
        if (m||n) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
