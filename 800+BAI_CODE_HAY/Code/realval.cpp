#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(int n)
{
    if (n<=5) return n;
    int s=0;
    while (n!=0) s+=n%10,n/=10;
    return solve(s/2);
}
main()
{
    int n; cin >> n;
    cout << solve(n);

}
