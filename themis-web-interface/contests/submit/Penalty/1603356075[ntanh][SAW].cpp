#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="SAW";
const int nmax=1e5+5;
int n,m,k,h[nmax],mx=0,f[nmax];

bool check(int supp) {
    int s=0;
    int l=1,r=n;
    while(l<=r) {
        int mid=(l+r)/2;
        if(h[mid]<supp) l=mid+1;
        else r=mid-1;
    }
    while(h[l]<supp) ++l;
    s=(f[n]-f[l-1])-(supp*(n-l+1));
    if(s>=m) return true;
    else return false;
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &k);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &h[i]);
        mx=max(mx,h[i]);
    }
    sort(h+1,h+1+n);
    for(int i=1;i<=n;++i)   f[i]=f[i-1]+h[i];
    for(int j=1;j<=k;++j) {
        scanf("%lld", &m);
        int r=mx,l=0;
        int res=0;
        while(l<=r) {
            int mid=(l+r)/2;
            if(check(mid)) {
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%lld ", res);
    }
    return 0;
}
