#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[10];
int res;

void dp(int i, int k) {
    if (k == 0 && i == 0) {
        res++;
        return;
    }
    for (int j = 0; j <= min(i, a[k]); j++) {
        dp(i - j, k - 1);
    }
}

int32_t main() {
    freopen("vuive9.inp","r",stdin);
    freopen("vuive9.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= m; i += 9) {
        dp(i, n);
    }
    printf("%d", res);
}