#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e11;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,lm;; cin >> n >> lm;
    vector <int> f(100001,MAX);
    f[0]=0;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        int w,v; cin >> w >> v;
        sum+=v;
        for (int j=sum;j>=v;j--)
            f[j]=min(f[j],f[j-v]+w);

    }
    for (int val=sum;val>0;val--)
        if (f[val]<=lm)
        {
            cout << val;
            exit(0);
        }

}
