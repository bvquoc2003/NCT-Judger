#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="BONUS";
int n,k,a[100005],s;
int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &k);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &a[i]);
        s+=a[i];
    }
    k=k%s;
    for(int i=1;i<=n;++i) {
        if(k-a[i]<0)    break;
        k-=a[i];
    }
    printf("%lld", k);
    return 0;
}
