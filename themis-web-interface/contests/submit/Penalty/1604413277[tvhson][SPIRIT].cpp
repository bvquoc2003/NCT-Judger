#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int32_t main() {
    freopen("SPIRIT.INP","r",stdin);
    freopen("SPIRIT.OUT","w",stdout);
    scanf("%d%d%d", &a, &b, &c);
    int s = ((a / c) + 1) * c;
    int t = (b / c) * c;
    int res = 0;
    if (s < b) {
        res++;
        res += (s - a) / 2;
        res += (((c - 1) / 2) + 1) * ((t - s) / c);
        res += (b - t) / 2;
    } else res = (b - a + 1) / 2;
    printf("%d", res);
}