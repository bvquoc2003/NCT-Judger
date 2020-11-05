#include <bits/stdc++.h>

using namespace std;
const int NM = 1e5 + 5;
const int oo = 1e9 + 9;

int n, m;
int a[5005];
int b[NM];
int dp[5005];
int B[NM];
int32_t main() {
    freopen("MARKET.INP", "r", stdin);
    freopen("MARKET.OUT", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = oo;
    }
    for (int j = 1; j <= m; j++) scanf("%d", &b[j]);

    B[m+1] = oo;
    for (int j = m; j >= 1; j--) B[j]=min(B[j + 1], b[j]);
    
    sort(a + 1, a + n +1);

    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= 0; j--) {
            dp[i] = min(dp[i], dp[j] + B[a[i] - a[j + 1] + 1]);
        }
    }
    printf("%d", dp[n]);
}