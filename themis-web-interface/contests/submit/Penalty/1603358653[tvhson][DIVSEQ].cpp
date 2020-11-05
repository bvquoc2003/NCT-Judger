#include <bits/stdc++.h>
#define int long long

using namespace std;
const int NM = 5 * 1e4 + 5;

int T;
int a[NM];
int s[NM];
int c[100005];
int n, d;

void Solve() {
    s[0] = 0;
    
    int res = 0;
    scanf("%lld%lld", &d, &n);
    for(int i=0;i<=d-1;i++) c[i]=0;
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
        res += c[s[i] % d];
        c[s[i] % d]++;
    }
    cout << res << endl;
}


// void Solve() {
//     s[0] = 0;
//     scanf("%lld%lld", &d, &n);
//     for (int i = 1; i <= n; i++) {
//         scanf("%lld", &a[i]);
//         s[i] = s[i - 1] + a[i];
//     }

//     int res = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0 ; j < i; j++) {
//             int cur = s[i] - s[j];
//             // cout << j << " -> " << i << " = " << cur << endl;
//             if (cur % d == 0) res++;
//         }
//     }
//     printf("%lld\n", res);
// }

int32_t main() {
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    scanf("%lld", &T);
    while (T--) {
        Solve();
    }
}

