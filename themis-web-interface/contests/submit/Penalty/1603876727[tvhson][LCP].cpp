#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[15][105];

// Sub n <= 10, m <= 10
int d[15][15];
int res = 0;
vector <int> x;

bool check() {
    if (x.empty()) return false;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < x.size(); j++) {
            if (d[i][x[j]] < d[i][x[j - 1]]) return false;
        }
    }
    return true;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        if (j) x.push_back(i);
        if (i >= n) {
            if (check()) res = max(res, int(x.size()));
        }
        else Try(i + 1);
        if (j) x.pop_back();
    }
}

// Sub m = 2
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

// Sub = 3
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
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        d[i][a[i][j]] = j;
    }
    if (m == 2) {
        Sub2();
        return 0;
    }
    if (m == 3) {
        Sub3();
        return 0;
    }
    Try(1);
    printf("%d", res);
}