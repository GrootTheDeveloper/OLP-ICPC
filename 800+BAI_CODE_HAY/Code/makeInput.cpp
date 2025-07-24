#include <bits/stdc++.h>
using namespace std;



int main()
{
    freopen("makeInput.inp", "w", stdout);
    srand(time(0));

    int n = 100000;
    long long p = 1 + rand() % 1000000000;
    cout << n << " " << p << "\n";
    for (int i = 1; i <= n; ++i) cout << 1 + rand() % 100000 << " ";

    return 0;
}