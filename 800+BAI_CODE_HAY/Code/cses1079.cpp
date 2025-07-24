#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1,MODE=1e9+7;
int gt[N],inv[N];

int power( int a, int b)
{
    int res=1;
    while (b>0)
    {
        if (b&1)
            res=(res*a)%MODE;
        a=(a*a)%MODE;
        b>>=1;
    }
    return res;
}
void init()
{
    gt[0]=inv[0]=1;
    for (int i=1;i<=N;i++)
    {
        gt[i]=i*gt[i-1]%MODE;
        inv[i]=power(gt[i],MODE-2);
    }
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int n; cin >> n;
    while (n--)
    {
        int a,b;
        cin >> a >> b;
        cout << gt[a]*inv[b]%MODE*inv[a-b]%MODE << endl;
    }
}
