#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { if (b==0) return a; return gcd(b,a%b);}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    while (q--)
    {
        int n; cin >> n;
        if (n==1)
        {
            cout << "Lihwy" << endl;
            continue;
        }
        if (gcd(n,n-2)==1) cout << "Lihwy" << endl;
        else cout << "FireGhost" << endl;
    }
    return 0;
}
