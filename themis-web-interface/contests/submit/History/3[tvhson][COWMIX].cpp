#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[10005];
bool cx[10005];
int x[10005];
int res;

bool check() {
    for (int i = 1; i < n; i++) {
        if (abs(x[i] - x[i + 1]) <= k) return false;
    }
    return true;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (cx[j]) continue;
        x[i] = j;
        cx[j] = true;
        if (i < n) Try(i + 1);
        else if (check()) res++;
        cx[j] = false;
    }
}

int32_t main() {
    freopen("COWMIX.INP","r",stdin);
    freopen("COWMIX.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    cout << res;
}