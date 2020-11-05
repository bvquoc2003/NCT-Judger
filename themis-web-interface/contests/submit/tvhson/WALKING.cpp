#include <bits/stdc++.h>
#define int long long

using namespace std;
const int NM = 1e5 + 5;
const int INF = 1e9;

typedef long double lf;
int n, m;
struct data {
    int s, t;
    lf d;
};
data a[NM];

bool cmp(const data &x, const data &y) {
    return (x.s < y.s || (x.s == y.s && x.t > y.t));
}

int cur[NM];
int ans[NM];

int32_t main() {
    freopen("WALKING.INP", "r", stdin);
    freopen("WALKING.OUT", "w", stdout);
    scanf("%lld%lld", &m ,&n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].s, &a[i].t);
        a[i].d = ((1.0 * m) / (1.0 * a[i].t)) + (1.0 * a[i].s);
    }
    sort(a + 1, a + n + 1, cmp);
    
    int res = 0;
    vector <lf> b(n+1, 1.0 * INF);
    b[0] = 1.0 * -INF;
    for (int i = n; i >= 1; i--) {
        int k = lower_bound(b.begin(), b.end(), a[i].d) - b.begin();
        b[k] = a[i].d;
        res = max(res, k);
    }

    printf("%lld", res);
}