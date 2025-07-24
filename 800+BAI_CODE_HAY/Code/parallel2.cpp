#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q; cin >> q;
    while (q--)
    {
        int a; int b;
        cin >> a >> b;
        cout << (a!=3 && b!=3 && a+b<=3 ? "Yes" : "No") << '\n';
    }
    return 0;
}
