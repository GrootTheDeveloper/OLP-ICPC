#include <bits/stdc++.h>
using namespace std;
int a[111];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        unordered_map <int,int> f;
        int n; cin >> n;
        string res="NO";
        for (int i=1;i<=n;i++) {cin >> a[i]; f[a[i]]++;}
        for (int i=1;i<=n-1;i++)
        for (int j=i+1;j<=n;j++)
        {
            f[a[i]]--;
            f[a[j]]--;
            if (f[a[i]+a[j]]) res="YES";
            f[a[i]]++;
            f[a[j]]++;
        }

        cout << res << endl;
    }
}
