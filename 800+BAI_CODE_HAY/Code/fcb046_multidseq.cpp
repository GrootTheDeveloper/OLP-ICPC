#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+1, K=55, mode=1e9+7;
int f[N][K];
vector<int> divs[N];
main(int argc, char *argv[])
{
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j+=i)
        divs[j].push_back(i);
    for (int i=1;i<=n;i++) f[i][1]=1;
    for (int i=1;i<=k;i++) f[1][i]=1;
    int res=1;
    for (int val=2;val<=n;val++)
    {
        for (int di : divs[val]){
            for (int i=2;i<=k;i++){
                f[val][i]=(f[val][i]+f[di][i-1])%mode;
            }
        }
        res=(res+f[val][k])%mode;

    }
    cout << res;

}
