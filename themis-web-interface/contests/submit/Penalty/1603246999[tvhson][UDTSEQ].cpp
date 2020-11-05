#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[100005];
int n, m;
int32_t main() {
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    int x, y, z;
    while (m--) {
        scanf("%lld%lld%lld", &x, &y, &z);
        a[x]+=z;
        a[y+1]-=z;
    }
    int s=0;
    for (int i=1;i<=n;i++) {
        s+=a[i];
        printf("%lld ", s);
    }
}