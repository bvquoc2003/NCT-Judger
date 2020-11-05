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
    for (int i = 1, x; i <= n; i++) {
        scanf("%lld", &x);
        if (x < t) a[0].push_back(x);
    }
    for (int j = 1, x; j <= m; j++) {
        scanf("%lld", &x);
        if (x < t) a[1].push_back(x);
    }
    int Tr = 0;
    int j = 0;
    int i = 0; 
    a[0].push_back(t);
    a[1].push_back(t);
    while (true) {
        if (a[j][i] >= t) {
            s[j] += max(a[j][i] - Tr,1LL * 0);
            break;
        } else s[j] += (a[j][i] - Tr);
        Tr = a[j][i];
        j = (j + 1) % 2;
        int l = upper_bound(a[j].begin(), a[j].end(), Tr) - a[j].begin();
        i = l;
        if (l != 0) {
            Tr = max(a[j][i - 1] + k, Tr);
        }
    }
    printf("%lld %lld", s[0], s[1]);
}