#include <bits/stdc++.h>

using namespace std;

int n;
int a[505];
int s;
int dp[505][100005];
int32_t main() {
    freopen("CANDY.INP", "r", stdin);
    freopen("CANDY.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c <= s; c++) {
            dp[i][c] = dp[i - 1][c];
            if (dp[i - 1][c + a[i]] != -1) dp[i][c] = max(dp[i][c], dp[i - 1][c + a[i]] + a[i]);
            if (dp[i - 1][abs(c - a[i])] != -1) dp[i][c]=max(dp[i][c], dp[i - 1][abs(c - a[i])] + a[i]);
        }
    }
    int res = s - dp[n][0] + dp[n][0]/2;
    printf("%d", res);
}