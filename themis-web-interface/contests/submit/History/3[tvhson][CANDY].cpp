#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[1000005];
int s=0;
int32_t main() {
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
    scanf("%lld", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
        s+=a[i];
    }
    s/=n;
    int res=0;
    for (int i=1;i<=n;i++) {
        if (a[i]>s) res+=a[i]-s;
    }
    printf("%lld", res);
}