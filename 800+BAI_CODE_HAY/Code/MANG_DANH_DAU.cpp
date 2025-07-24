#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> b;
    int n,x,d=0;
    cin >> n >> x;
    int a[n+1];
    for (int i=1;i<=n;i++){
        cin >> a[i];
        b[a[i]]=0;
    }
    for (int i=1;i<=n;i++){
        b[a[i]]+=1;
        if (b[x-a[i]]!=0)
            d+=b[x-a[i]];
    }
    cout << d;


    return 0;
}
