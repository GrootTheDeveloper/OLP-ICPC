#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset <int> S;
    multiset <int> :: iterator it;
    int n, ai;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ai);
        S.insert(ai);
        it = S.lower_bound(ai);
        it++;
        if (it != S.end()) S.erase(it);
    }
    printf("%d", S.size());
    return 0;
}
