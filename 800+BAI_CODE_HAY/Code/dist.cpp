#include <bits/stdc++.h>
using namespace std;
map<int , int> x;

int main()
{
    int n,ai,res=0; cin >> n;
    while (n--)
    {
        cin >> ai;
        x[ai]++;
        if(x[ai]==1) res++;
    }
    return cout << res,0;
}
