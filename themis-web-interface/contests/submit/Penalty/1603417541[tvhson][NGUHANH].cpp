#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 1e9 + 7;

int n;
string a;
int k;
int res;
int luythua(int a, int d) {
    if (d == 0) return 1;
    int b = luythua(a, d/2);
    b = (b * b) % MOD;
    if (d % 2) b = (b * a) % MOD;
    return b;
}

int32_t main() {
    freopen("NGUHANH.INP","r",stdin);
    freopen("NGUHANH.OUT","w",stdout);
    cin >> a;
    cin >> k;
    n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == '0' || a[i] == '5') {
            for (int j = 0; j < k; j++)
            res += luythua(2, i + n * j);
        }
    }
    cout << res;
}