#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="SQUARE";
int k,f[2000005];
map<int, bool> cx;
void init() {
    for(int i=0;i<=2000000;++i) {
        f[i]=i*i;
        cx[i*i]=true;
    }
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld", &k);
    init();
    for(int i=0;i<=2000000;++i) {
        if(cx[k+f[i]]) {
            int pos=k+f[i];
            pos=trunc(sqrt(pos));
            printf("%lld", pos);
            return 0;
        }
    }
    printf("none");
    return 0;
}
