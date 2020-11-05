#include <bits/stdc++.h>
#define int long long

using namespace std;
const int NM = 1e5 + 5;

int n, m;
struct data {
    int s, t, stt, d;
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
    scanf("%lld%lld", &n ,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].s, &a[i].t);
        a[i].stt = i;
        a[i].d = a[i].t * m + a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);

    // for (int i = 1; i <= n; i++) {
    //     printf("%lld %lld\n", a[i].s, a[i].t);
    // }

    for (int i = 1; i <= n; i++) {
        cur[i] = max(cur[i-1], a[i].d);
        ans[a[i].stt]=cur[i];
    }

    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
}