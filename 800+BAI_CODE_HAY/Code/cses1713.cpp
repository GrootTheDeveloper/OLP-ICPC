#include <bits/stdc++.h>
using namespace std;
#define MAX 1000004
int res[MAX],a[MAX];
int main()
{
    int n,temp=0; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i], temp=max(temp,a[i]);
    for (int i=1;i<=temp;i++) for (int j=i;j<=temp;j+=i) res[j]+=1;
    for (int i=1;i<=n;i++) cout << res[a[i]] << "\n";
    return 0;

}
