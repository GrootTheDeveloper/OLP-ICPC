#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x; cin >> n >> x;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    int i=1,j=n,res=0;
    while (i<=j)
    {
        if (a[i]+a[j]<=x) res++,i++,j--;
        else j--,res++;
    }
    cout << res;

}
