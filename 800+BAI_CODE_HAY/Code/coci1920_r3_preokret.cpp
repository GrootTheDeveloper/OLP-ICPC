#include <bits/stdc++.h>
using namespace std;
int f1[300],f2[300],his1[300],his2[300];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int fair=1;
    for (int i=1;i<=n;i++)
    {
        int x; cin >> x;
        if (x==1) f1[i]=f1[i-1]+1,his1[i]=his1[i-1]+1,his2[i]=his2[i-1];
        else f2[i]=f2[i-1]+1,his2[i]=his2[i-1]+1,his1[i]=his1[i-1];
        fair+=(his1[i]==his2[i]);
    }
    cout << his1[n] << ' ' << his2[n] << endl;
    cout << fair << endl;
    int res=0;
    for (int i=1;i<=n;i++)
    {
        if (f1[i]>0 && his1[i-f1[i]]<his2[i-f1[i]]) res=max(res,f1[i]);
        if (f2[i]>0 && his2[i-f2[i]]<his1[i-f2[i]]) res=max(res,f2[i]);
    }
    cout << res;
}
