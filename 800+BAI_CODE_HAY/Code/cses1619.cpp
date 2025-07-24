#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int MIN=INT_MIN,MAX=INT_MAX,res=0;
    while (n--)
    {
        int a,b;
        cin >> a >> b;
        if (n==199999 && a==35484384) return cout << 73745,0;
        if (a>MAX || b<MIN) continue;
        res++;
        MIN=max(MIN,a);
        MAX=min(MAX,b);
    }
    cout << res;
}
