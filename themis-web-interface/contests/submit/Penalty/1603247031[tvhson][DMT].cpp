#include <bits/stdc++.h>
#define int long long

using namespace std;

int T;
int s[1000005];
int32_t main() {
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    scanf("%lld", &T);
    if (T!=1) {
        for (int i=1;i<=1e3;i++) {
            int j=1;
            int d=0;
            for (j=1;j*j<i;j++) if (i%j==0) {
                    d+=2;
                    if (d>8) break;
                }
                if (d==8 && j*j==i) s[i]=s[i-1]+1;
                else s[i]=s[i-1];
        }
        while (T--) {
            int a, b;
            scanf("%lld%lld", &a, &b);
            printf("%lld\n", s[b]-s[a-1]);
        }
    } else {
        int a, b;
        scanf("%lld%lld", a, b);
        for (int i=a;i<=b;i++) {
            int j=1;
            int d=0;
            int res=0;
            for (j=1;j*j<i;j++) if (i%j==0) {
                    d+=2;
                    if (d>8) break;
                }
                if (d==8 && j*j==i) res++;
        }
    }
    
}