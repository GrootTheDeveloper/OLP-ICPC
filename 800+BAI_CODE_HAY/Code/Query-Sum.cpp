#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1111;
int bit1[MAX],bit2[MAX],n,q,diff[MAX],a[MAX],bit[MAX];


main()
{
    int q,v;
    cin >> n;

    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        diff[i]=a[i]-a[i-1];
        updatePoint(bit1,i,diff[i]);
        updatePoint(bit2,i,diff[i]);
    }
    cout << rangesum(1,3);

}




