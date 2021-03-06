#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k, h[100005];
ll sumH[100005];

bool check(int k, int m) {
    int i = lower_bound(h, h+n, k, greater<int>()) - h;
    int s = sumH[i-1] - i*k;
    return s >= m;
}

int query(int m) {
    int l = 0, r = h[0], mid;
    int ans = 0;
    while (l <= r) {
        mid = l + (r - l)/2;
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

    sort(h, h+n, greater<int>());
    sumH[0] = h[0];
    for (int i = 1; i < n; i++)
        sumH[i] = sumH[i-1] + h[i];
    
    while (k--) {
        int m; cin >> m;
        cout << query(m) << ' ';
    }

    return 0;
}