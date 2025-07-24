#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k; cin >> k;
    int n=0;
    for (int i=1;i<=k;i++)
    {
        n=(n*10+1) % k;
        if (n==0)
        {
            return cout << i,0;
        }
    }
    cout << -1;

}
