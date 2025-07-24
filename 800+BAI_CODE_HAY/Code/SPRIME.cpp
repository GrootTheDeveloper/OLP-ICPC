#include <iostream>
#include <math.h>
using namespace std;

bool nt(int c)
{
    if (c<2)
    {
        return 0;
    }
    for (int i=2; i<=sqrt(c); i++)
    {
        if (c % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

bool snt(int n){
    if (!nt(n)){
        return 0;
    }
    while (n>9){
        n/=10;
        if (!nt(n)){
            return 0;
        }
    }
    return 1;
}


int main()
{
    int a,b;
    freopen("sprime.inp", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> a >> b;
    for (int i=a; i<=b; i++)
    {
        if (snt(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}
