int main() {
    int q;     if (!(cin >> q)) return 0;
    uint32_t x = 0; // 32-bit unsigned, initially 0
    while (q--) {
        int t; unsigned k; 
        cin >> t >> k;            // 0 <= k <= 31
        uint32_t mask = (1u << k);
        if (t == 1)      x |=  mask;  // set k-th bit
        else if (t == 2) x &= ~mask;  // clear k-th bit
        else             x ^=  mask;  // toggle k-th bit
        cout << x << '\n';
    }
    return 0;
}
