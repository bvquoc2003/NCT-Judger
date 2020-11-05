#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="TANK";
const int nmax=1e5+5;
int n,M,a[nmax],f[nmax],res;

bool check(int mid) {
    for(int i=mid;i<=n;++i) {
        if(f[i]-f[i-mid]<M) return false;
    }
    return true;
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &M, &n);
    for(int i=1;i<=n;++i)   scanf("%lld", &a[i]);
    for(int i=1;i<=n;++i)   f[i]=f[i-1]+a[i];
    int l=1,r=n;
    while(l<=r) {
        int mid=(l+r)/2;
        if(!check(mid)) l=mid+1;
        else {
            res=mid;
            r=mid-1;
        }
    }
    printf("%lld", res);
    return 0;
}
