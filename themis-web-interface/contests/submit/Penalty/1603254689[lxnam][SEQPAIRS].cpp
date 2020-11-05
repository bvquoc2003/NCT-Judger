#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int a[1004], b[1005];
int s_a[1005], s_b[1005];
int res;
map <int, int> d;
int32_t main() {
    freopen("SEQPAIRS.INP","r",stdin);
    freopen("SEQPAIRS.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        s_a[i]=s_a[i-1]+a[i];
    }
    for (int i=1; i<=m; i++) {
        scanf("%lld", &b[i]);
        s_b[i]=s_b[i-1]+b[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            d[s_a[j]-s_a[i-1]]++;
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=i;j<=m;j++) {
            res+=d[s_b[j]-s_b[i-1]];
        }
    }
    printf("%lld", res);
}