#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[15];
int n, k;

// k = 1 && 0 <= ai <= 100
void Sub1() {
    int ans = INT_MAX;
    for (int i = 0; i <= 100; i++) for (int j = 1; j <= 100; j++) {
        int res = 0;
        for (int u = 1; u <= n; u++) {
            res += abs(a[u].first - i) + abs(a[u].second - j);
        }
        ans = min(ans, res);
    }
    printf("%d", ans);
}

int32_t main() {
    freopen("BGAME.INP","r",stdin);
    freopen("BGAME.OUT","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    if (k == 1) {
        Sub1();
        return 0;
    }
}