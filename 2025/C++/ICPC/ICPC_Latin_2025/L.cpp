#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // f[i][0]: số cách độ dài i, kết thúc bằng 0 M liên tiếp (tức bằng F)
    // f[i][1]: số cách độ dài i, kết thúc bằng 1 M
    // f[i][2]: số cách độ dài i, kết thúc bằng 2 M liên tiếp
    vector<array<long long,3>> f(N+1);
    f[0] = {1, 0, 0};  // dãy rỗng: 1 cách kết thúc "bằng F" giả định

    for(int i = 1; i <= N; i++) {
        // đặt F ở vị trí thứ i → phá hết M liên tiếp trước đó
        f[i][0] = ( (f[i-1][0] + f[i-1][1])  + f[i-1][2] ) ;

        // đặt M ở vị trí thứ i:
        // nếu trước đó kết thúc bằng 0 M (F), bây giờ thành ...M (1 M)
        f[i][1] = f[i-1][0] ;

        // nếu trước đó kết thúc bằng 1 M, bây giờ thành ...MM (2 M)
        f[i][2] = f[i-1][1] ;
    }

    // Tổng = mỗi trạng thái kết thúc
    long long result = ((f[N][0] + f[N][1])  + f[N][2]) ;
    cout << result << "\n";
    return 0;
}
