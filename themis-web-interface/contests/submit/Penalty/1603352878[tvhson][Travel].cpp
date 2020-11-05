#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, s;
int a[45];
int f[100005];
int sum;
int res;

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        sum += a[i] * j;
        // cout << s << endl;
        if (sum == s) {
            res++;
        } else {
            if (sum < s && i < n) Try(i + 1);
        }
        sum -= a[i] * j;
    }
}

int32_t main() {
    freopen("Travel.INP", "r", stdin);
    freopen("Travel.OUT", "w", stdout);
    scanf("%lld%lld", &n, &s);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    Try(1);
    printf("%lld", res);
}