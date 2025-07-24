#include <iostream>
using namespace std;

int main()
{
    freopen("BZERO.INP","r",stdin);
    freopen("BZERO.OUT","w",stdout);
    int n;
    cin >> n;
    int k=1;
    int d=0;
    while (k*5 < n)
    {
        k*=5;
        d+= n/k;
    }
    cout << d;
    return 0;
}
