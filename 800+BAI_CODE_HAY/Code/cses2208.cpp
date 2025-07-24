#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int ai,n,d=0;
        cin >> n;
        while (n--)
        {
            cin >> ai;
            if (ai%2!=0 && d==0)
            {
                cout << "first" << endl;
                d=1;
            }
        }
        if (d==0) cout << "second" << endl;

    }
    return 0;
}
