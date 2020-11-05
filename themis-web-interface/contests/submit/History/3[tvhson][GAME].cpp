#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[100005];
int b[100005];
int res=LLONG_MAX;
void minimize(int &x, int y) {
    if (x>y) x=y;
}
int32_t main() {
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    scanf("%lld", &n);
    for (int i=1;i<=n;i++) scanf("%lld", &a[i]);
    for (int i=1;i<=n;i++) scanf("%lld", &b[i]);
    sort(b+1,b+1+n);
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b+1,b+n+1,a[i])-b;
        if (k<=n) minimize(res,abs(b[k]+a[i]));
        if (k>1) minimize(res,abs(b[k-1]+a[i]));
        k=lower_bound(b+1,b+n+1,-a[i])-b;
        if (k<=n) minimize(res,abs(b[k]+a[i]));
        if (k>1) minimize(res,abs(b[k-1]+a[i]));
    }
    printf("%lld", res);
}