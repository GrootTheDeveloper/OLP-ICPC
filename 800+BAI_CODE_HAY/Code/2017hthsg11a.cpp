#include <bits//stdc++.h>
using namespace std;
int a[100];
int sol(int s)
{
    int n=0;
    while (s) n++,a[n]=s%10,s/=10;
    if (n==1) return 1;
    int l=1,r=n;
    while (l<r) if (a[l++]!=a[r--]) return 0;
    return 1;
}

int main()
{
    freopen("PALIND.INP","r",stdin);
    freopen("PALIND.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int x,y;
    while (n--)
    {
        cin >> x >> y;
        cout << sol(x+y) << '\n';
    }


}
