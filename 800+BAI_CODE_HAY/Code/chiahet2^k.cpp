#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[70];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    int ai;
    int res=0;
    for (int oo=1;oo<=n;oo++)
    {
        cin >> ai;
        int count_2=0;
        while (ai%2==0) count_2++,ai/=2;
        if (count_2>=k)
        {
            res+=(oo-1)*(oo-2)/2;
            cnt[count_2]++;
            continue;
        }
        int low=k-count_2;
        for (int i=0;i<=64;i++)
        {
            int sum=0;
            for (int j=max(low-i,i+1);j<=64;j++) sum+=cnt[j];
            res+=cnt[i]*sum;
            if (i+i>=low) res+=cnt[i]*(cnt[i]-1)/2;
        }
        cnt[count_2]++;
    }
    cout << res;

}
