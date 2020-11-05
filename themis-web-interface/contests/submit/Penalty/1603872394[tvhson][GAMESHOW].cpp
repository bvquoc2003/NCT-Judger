#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5;

int n, T;
int a[N];

int x[N];
int s = 0;
int res = 1e9;

void check() {
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) sum -= T;
        else {
            cnt++;
            sum += a[i];
        }
        if (sum <  0) return;
    }
    res = min(res, cnt);
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i >= n) {
            check();
        } else Try(i + 1);
    }
}

int32_t main() {
    freopen("GAMESHOW.INP","r",stdin);
    freopen("GAMESHOW.OUT","w",stdout);
    scanf("%lld%lld", &n, &T);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    // if (n <= 20) {
        s += a[1];
        x[1] = 1;
        if (s < 0) {
            printf("-1");
            return 0;
        }
        else Try(2);
        printf("%lld", res + 1);
        return 0;       
    // }
}