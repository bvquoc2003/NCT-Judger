#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5 + 5;

int n, m, t, k;
vector <int>  a[3];
int s[3];

int32_t main() {
    freopen("WATCHING.INP","r",stdin);
    freopen("WATCHING.OUT","w",stdout);
    scanf("%lld%lld%lld%lld", &n, &m, &t, &k);
    for (int i = 1, x; i <= n; i++) scanf("%lld", &x), a[0].push_back(x);
    for (int j = 1, x; j <= m; j++) scanf("%lld", &x), a[1].push_back(x);
    int Tr = 0;
    int j = 0;
    int i = 0;
    while (true) {
        if (a[j][i] >= t) {
            s[j] += (t - Tr);
            break;
        } else s[j] += (a[j][i] - Tr);
        Tr = a[j][i];
        int jj = (j + 1) % 2;
        int l = upper_bound(a[jj].begin(), a[jj].end(), Tr) - a[jj].begin();
        if (l == 0 || a[jj][l - 1] + k <= Tr) {
            i = l;
            j = jj;
        } else {
            Tr = a[j][i] + k;
            i++;
        }
    }
    printf("%lld %lld", s[0], s[1]);
}