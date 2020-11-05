#include<bits/stdc++.h>
using namespace std;

long long a[1000006], t,n, s;

int32_t main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
    scanf("%lld%lld", &n);
    s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    t = s / n;

    s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < t) s += t - a[i];
    }
   printf("%lld", s);

    return 0;
}
