#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="WALKING";
const int nmax=1e5+5;
struct inf{int ti,sp,id,pos;}stdent[nmax];
int n,L,ti[nmax],pos[nmax];
bool cmp(const inf &A, const inf &B) {return A.ti<B.ti || (A.ti==B.ti && A.sp>B.sp);}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &L);
    for(int i=1;i<=n;++i) {
            scanf("%lld%lld", &stdent[i].ti, &stdent[i].sp);
            stdent[i].id=i;
    }
    sort(stdent+1,stdent+1+n,cmp);
    for(int i=1;i<=n;++i) {
        ti[i]=stdent[i].sp*L+stdent[i].ti;
        pos[stdent[i].id]=i;
    }
    for(int i=1;i<=n;++i) {
        if(ti[i]<ti[i-1]) {
            ti[i]=ti[i-1];
            pos[stdent[i].id]=i;
        }
    }
    for(int i=1;i<=n;++i)   printf("%lld\n", ti[pos[i]]);
    return 0;
}
