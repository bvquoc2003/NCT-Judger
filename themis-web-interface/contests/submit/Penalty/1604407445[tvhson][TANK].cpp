#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

int n, m;
int a[N];
long long s[N];

bool check(int x) {
    for (int i = x; i <= n; i++) {
        if (s[i] - s[i - x] < m) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TANK.INP","r",stdin);
    freopen("TANK.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + (1LL * a[i]);

    int res = 0;    
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res;
}