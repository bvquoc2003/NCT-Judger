#include<bits/stdc++.h>
using namespace std;

long long a[1000006], t, s;
int n,i;
int main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
    scanf("%lld", &n);
    s = 0;
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        s += a[i];
    }
    t = s / n;
    s = 0;
    for (i = 0; i < n; i++) {
        if (a[i] < t) s += t - a[i];
    }
   printf("%lld", s);

    return 0;
}
