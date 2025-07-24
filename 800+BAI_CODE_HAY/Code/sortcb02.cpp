#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a>b;
}
int a[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1,cmp);
    cout << a[k];
    return 0;

}
