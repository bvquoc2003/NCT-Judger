#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[10][105];

int f[105][105];
void Sub2() {
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (a[1][i] == a[2][j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i][j - 1], f[i - 1][j]);
        }
    }
    printf("%d", f[n][n]);
}

int F[105][105][105];
void Sub3() {
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            for (int k = 2; k <= n; k++) {
                if (a[1][i] == a[2][j] && a[1][i] == a[3][k]) F[i][j][k] = F[i - 1][j - 1][k - 1] + 1;
                else F[i][j][k] = max(F[i][j - 1][k], max(F[i - 1][j][k], F[i][j][k - 1]));
            }
        }
    }
    printf("%d", F[n][n][n]);
}

int32_t main() {
    freopen("LCP.INP","r",stdin);
    freopen("LCP.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    if (m == 2) {
        Sub2();
        return 0;
    }
    if (m == 3) {
        Sub3();
        return 0;
    }
}