#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5 + 5;
const int oo = 1e15;

int n, w1, w2;
int a[N];
int Lw1[N], Lw2[N], Rw1[N], Rw2[N];

int32_t main() {
    freopen("FIVESET.INP","r",stdin);
    freopen("FIVESET.OUT","w",stdout);
    scanf("%lld%lld%lld", &n, &w1, &w2);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        Lw1[i] = -oo;
        Rw1[i] = -oo;
        Lw2[i] = -oo;
        Rw2[i] = -oo;
    }
    
    for (int i = 1, j = n; i <= n; i++, j--) {
        Lw1[i] = max(Lw1[i - 1], a[i] * w1);
        Rw1[j] = max(Rw1[j + 1], a[j] * w1);
    }
    for (int i = 2, j = n - 1; i <= n; i++, j--) {
        Lw2[i] = max(Lw2[i - 1], Lw1[i - 1] + (a[i] * w2));
        Rw2[j] = max(Rw2[j + 1], Rw1[j + 1] + (a[j] * w2));
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << Lw1[i] <<" ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << Rw1[i] <<" ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << Lw2[i] <<" ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << Rw2[i] <<" ";
    // }
    // cout << endl;

    int res = -oo;
    for (int i = 3; i <= n - 2; i++) {
        res = max(res, Lw2[i - 1] + Rw2[i + 1] + a[i]);
    }

    printf("%lld", res);
}