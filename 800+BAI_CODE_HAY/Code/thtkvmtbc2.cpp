#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mode=1e9+7;
int power(int a, int b){
    int res=1;
    while (b){
        if (b&1) res=(res*a)%mode;
        a=(a*a)%mode;
        b/=2;
    }
    return res;
}
int calc(int n){
    return n*(n+1)/2;
}
int fast(int n){
    return (((n*(n+1)%mode)*((2*n+1)%mode)%mode)*power(6,mode-2))%mode;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int l=1,r=(int)1e9;
    while (l<r){
        int mid=(l+r)/2;
        if (calc(mid)>n) r=mid-1;
        else l=mid+1;
    }
    while (calc(l-1)>=n) l--;
    while (calc(l)<n) l++;
    int k=n-calc(l-1);
    cout << (fast(l-1)+k*l)%mode;

}