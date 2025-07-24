#include <bits/stdc++.h>
using namespace std;
#define int long long
int d[2222],c[2222];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q; cin >> n >> m >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type==1)
        {
            int r, x; cin >> r >> x;
            d[r]+=x;
        }
        else if (type==2)
        {
            int id, x; cin >> id >> x;
            c[id]+=x;
        }
        else
        {
            int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            int md=0,mc=0;
            for (int i=x1;i<=x2;i++) md=max(md,d[i]);
            for (int i=y1;i<=y2;i++) mc=max(mc,c[i]);
            cout << md+mc << endl;
        }
    }
}
