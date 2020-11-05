#include <bits/stdc++.h>

using namespace std;

int n, t;
int a[1000005];

int32_t main() {
    freopen("DLIGHT.INP","r",stdin);
    freopen("DLIGHT.OUT","w",stdout);
    scanf("%d%d", &n, &t);
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x]++;
        a[y + 1]--;
    }
    int s = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        if (s % 3 == 0) res++;
    }
    printf("%d", res);
}