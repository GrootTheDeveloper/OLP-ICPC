#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int mask = 5;
    for (int i = 1; i <= 5; i++)
        cout << (mask|(1<<i)) << ' ';
}
