#include <iostream>
using namespace std;

int main()
{
    freopen("BMARKET.INP","r",stdin);
    freopen("BMARKET.OUT","w",stdout);
    int y,k,n;
    int d=0;
    cin >> y >> k >> n;
    for (int x=1; x<=n-y; x++)
    {
        if ((x+y) % k ==0)
        {
            cout << x << " ";
            d+=1;
        }
    }
    if (d==0)
    {
        cout << -1;
    }
    return 0;
}
