#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="LEAVES";
const int nmax=1e5+5;
int n,s,f[nmax],in[nmax],res,Wused;
struct leaves{int w,id;}a[nmax];
bool cmp(const leaves &A,const leaves &B) {return A.w<B.w || (A.w==B.w && A.id<B.id);}

bool check(int mid) {
    int W=f[mid]+mid*in[mid];
    if(s>=W) {
        Wused=W;
        return true;
    }
    else return false;
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &s);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &a[i].w);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i) {
        f[i]=f[i-1]+a[i].w;
        in[i]=in[i-1]+a[i].id;
    }
    int l=1,r=n;
    while(l<=r) {
        int mid=(l+r)/2;
        if(check(mid)) {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(res==0) {
        printf("0");
        return 0;
    }
    printf("%lld %lld", res, Wused);
    return 0;
}
