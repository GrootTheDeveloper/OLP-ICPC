#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,ai; cin >> n;
    for (int i=1; i<=n; i++) cin >> ai, a.push_back(ai);
    sort(a.begin(),a.end());
    int res=0;
    for (int i=0;i<=a.size()-3;i++)
        for (int j=i+1;j<=a.size()-2;j++)
        {
            int sum=a[i]+a[j];
            auto it=lower_bound(a.begin()+j+1,a.end(),sum);
            if (it==a.end()) res+=n-1-j;
            else
            {
                it--;
                res+=it-a.begin()-j;
            }
        }
    cout << res;
    return 0;   
}
