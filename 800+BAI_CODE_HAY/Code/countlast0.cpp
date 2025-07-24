#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125,6103515625,30517578125,152587890625,762939453125,3814697265625,19073486328125,95367431640625,476837158203125,2384185791015625,11920928955078125,59604644775390625,298023223876953125};

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n,res=0; cin >> n;
        for (int i: vi)
            if (i<=n) res+=n/i;
            else break;
        cout << res << '\n';
    }

}
