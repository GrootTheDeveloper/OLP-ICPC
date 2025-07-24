#include <bits/stdc++.h>
using namespace std;
#define max 10000
int main(){
    int a[max],b[max],n,m;
    vector <int> c;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=m;i++)
        cin >> b[i];
    sort(a,a+n+1);
    sort(b,b+m+1);
    int i=1 , j=1;
    while (j<=m || i<=n){
        if (j==m+1 || (i<=n && a[i]<=b[j]))
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }
    for (auto it : c)
        cout << it << " ";

    return 0;
}
