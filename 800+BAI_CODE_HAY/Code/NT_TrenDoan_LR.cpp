#include <bits/stdc++.h>
using namespace std;
int a[15][15];
void xuli(int l,int r)
{
    vector<bool> nt(r-l+1,true);

    for (long long i=2;i*i<=r;i++)
        for (long long j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
            nt[j-l]=false;
    if (1>=l)
        nt[1-l]=false;
    for (long long i=l;i<=r;i++)
        if (nt[i-l]==true)
            cout << i << endl;
    cout << endl;
}



int main(){
    int n,l,r;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i][0] >> a[i][1];
    for (int i=1;i<=n;i++)
        xuli(a[i][0],a[i][1]);


    return 0;
}

