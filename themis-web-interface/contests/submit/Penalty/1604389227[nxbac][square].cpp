#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("square.inp", "r", stdin);
    freopen("square.out", "w", stdout);

    long long k; cin >> k;
    if (k == 0) { cout << k; return 0; }

    int ans = INT_MAX;
    for (int i = 1; i <= (int)sqrt(k); i++) if (k % i == 0) {
        int a = i, b = k/i;
        double y = (double)(a + b) / 2, x = (double)max(a, b) - y;
        if (min(x, y) >= 0 && y == (int)y && x == (int)x)
            ans = min(ans, (int)y);
    }
    cout << ans;

    return 0;
}