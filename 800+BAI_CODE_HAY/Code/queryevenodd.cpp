#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,c,sum,type,x;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;

    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        sum+=ai;
        if (ai&1) l++;
        else c++;
    }
    while (q--)
    {
        cin >> type >> x;
        if (type==1)
        {
            sum+=c*x;
            if (x&1) l+=c,c=0;
            cout << sum << endl;
        }
        else
        {
            sum+=l*x;
            if (x&1) c+=l,l=0;
            cout << sum << endl;
        }
    }
}
