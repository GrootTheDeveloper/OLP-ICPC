#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K; cin>>N>>K;
    vector<ll> x(N+1), w(N+1);
    for(int i=1;i<=N;i++) cin>>x[i]>>w[i];

    // prefix sums
    vector<ll> W(N+1,0), X(N+1,0);
    for(int i=1;i<=N;i++){
        W[i]=W[i-1]+w[i];
        X[i]=X[i-1]+w[i]*x[i];
    }

    // cost[l][r] với median trượt O(N²)
    vector<vector<ll>> cost(N+1, vector<ll>(N+1,0));
    for(int l=1;l<=N;l++){
        int m=l;                 // median chỉ trượt sang phải
        for(int r=l;r<=N;r++){
            ll total = W[r]-W[l-1];
            while(m<r && 2*(W[m]-W[l-1]) < total) ++m;

            ll xm = x[m];
            ll leftW = W[m]-W[l-1];
            ll leftX = X[m]-X[l-1];
            ll rightW = W[r]-W[m];
            ll rightX = X[r]-X[m];

            cost[l][r] = xm*leftW - leftX + rightX - xm*rightW;
        }
    }

    // DP
    vector<vector<ll>> dp(N+1, vector<ll>(K+1, INF));
    dp[0][0]=0;
    for(int p=1;p<=K;p++)
        for(int r=1;r<=N;r++)
            for(int l=p-1;l<r;l++)
                dp[r][p]=min(dp[r][p], dp[l][p-1]+cost[l+1][r]);

    cout<<dp[N][K]<<'\n';
}
