#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[100005], b[100005];
int res;
bool check(int x) {
    int k=0;
    for (int i=1;i<=n;i++) {
        if (k>=0 && k-(a[i]-a[i-1])<=0) k=0;
        else k-=(a[i]-a[i-1]);
        k-=(x-b[i]);
        // cout<<k<<endl;
    }
    if (k>=0) return true;
    return false;
}
int32_t main() {
    freopen("RICE.INP","r",stdin);
    freopen("RICE.OUT","w",stdout);
    scanf("%lld", &n);
    for (int i=1;i<=n;i++) scanf("%lld%lld", &a[i], &b[i]);
    a[0]=a[1];
    int l=0, r=1e12;
    while (l<=r) {
        int mid=(l+r)/2;
        if (check(mid)) {
            l=mid+1;
            res=mid;
        } else r=mid-1;
    }
    printf("%lld", res);
}