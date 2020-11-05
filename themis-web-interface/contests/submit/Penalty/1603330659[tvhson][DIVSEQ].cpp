#include <bits/stdc++.h>
#define int long long

using namespace std;
const int NM = 5 * 1e4 + 5;

int T;
int a[NM];
int s[NM];
int c[100005];
int n, d;

void Solve() {
    s[0] = 0;
    scanf("%lld%lld", &d, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
        c[s[i] % d]++;
    }
    
    double res;
    for (int i = 0; i < d; i++) {
        res += double ((c[i] * (c[i] - 1)) / 2);
    }
    cout << res;
}

int32_t main() {
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    scanf("%lld", &T);
    while (T--) {
        Solve();
    }
}