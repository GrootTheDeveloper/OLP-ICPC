#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int year;
    while (cin>>year && year != 0) {
        int bits = 4*(1<<((year-1960)/10));
        int n=1;
        double s=0.0;
        while (true) {
            s+=log2(n);
            if (s>bits)
                break;
            n++;
        }
        cout<<(n-1)<< endl;
    }
}