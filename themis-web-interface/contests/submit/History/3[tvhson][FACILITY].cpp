#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int MAX;

struct data {
    int s, t, z;
};
data a[N];
map <int, int> s;
int n, k;

bool cmp(const data &u, const data &v) {
    return (u.t < v.t || (u.t == v.t && u.s < v.s));
}

void update(int p, int val) {
    for (int i = p; i <= MAX; i += i & -i) s[i] = max(s[i], val);
}

int Find(int p) {
    int ans = 0;
    for (int i = p; i; i -= i & -i) ans = max(ans, s[i]);
    return ans;
}

int32_t main() {
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    scanf("%d%d", &n, &k);
    MAX = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].s, &a[i].t, &a[i].z);
        a[i].t += a[i].s + k;
        MAX = max(a[i].t, MAX);
    }
    int ans = 0;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int u = a[i].s, v = a[i].t, l = a[i].z;
        int res = l + Find(u);
        ans = max(res, ans);
        update(v, res);
    }
    printf("%d", ans);
}