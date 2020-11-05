#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, s;
int a[45];
int f[100005];

void Sub1() {
    f[0] = 1;
    for (int i = 1; i <= s; i++) 
    for (int j = 1; j <= n; j++)
    if (i >= a[j])
    f[i] += f[i - a[j]];

    printf("%lld", f[s] / s);
}

int32_t main() {
    freopen("Travel.INP", "r", stdin);
    freopen("Travel.OUT", "w", stdout);
    scanf("%lld%lld", &n, &s);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    Sub1();
}