#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, k, h[100005];

bool check(int k, int m) {
    int s = 0;
    for (int i = 0; i < n; i++)
        if (h[i] > k) s += h[i] - k;
    return s >= m;
}

int query(int m) {
    int l = 0, r = 1000000, mid;
    int ans = 0;
    while (l <= r) {
        mid = (l + r)/2;
        if (check(mid, m)) {
            ans = mid;
            l = mid + 1;
        } else r = mid -1;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("saw.inp", "r", stdin);
    freopen("saw.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    while (k--) {
        int m; cin >> m;
        cout << query(m) << ' ';
    }

    return 0;
}