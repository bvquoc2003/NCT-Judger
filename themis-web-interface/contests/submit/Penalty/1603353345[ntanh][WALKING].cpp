#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="WALKING";
const int nmax=1e5+5;
struct inf{int ti,sp,id;}stdent[nmax];
struct group{
    int ti,sp,di=0;
    vector<int> id;
}st[nmax];
int n,L,top,l[nmax];
bool cmp(const inf &A, const inf &B) {return A.ti<B.ti || (A.ti==B.ti && A.sp>B.sp);}

void solve() {
    st[top+1].sp=INT_MAX;
    int i=1;
    while(i<=top) {
        if(st[i].sp<=st[i+1].sp) {
            st[i].di=st[i].sp*L+st[i].ti;
            ++i;
        }
        else {
            double k=((long double)(st[i].ti/st[i].sp)-(long double)(st[i+1].ti/st[i+1].sp))/((long double)(1/st[i].sp)-(long double)(1/st[i+1].sp));
            int spmn=max(st[i].sp,st[i+1].sp);
            int pos=(k-st[i].ti)/st[i].sp;
            st[i].di=st[i+1].di=spmn*(L-pos);
            i+=2;
        }
    }
    for(int i=1;i<=top;++i) {
        for(int j=0;j<st[top].id.size();++j) {
            l[st[i].id[j]]=st[i].di;
        }
    }
    for(int i=1;i<=n;++i)   printf("%lld\n", l[i]);
}

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
        if(stdent[i].sp>st[top].sp) {
            st[++top].ti=stdent[i].ti;
            st[top].sp=stdent[i].sp;
        }
        if(stdent[i].ti>(st[top].sp+st[top].ti)) {
            st[++top].ti=stdent[i].ti;
            st[top].sp=stdent[i].sp;
        }
        if(stdent[i].ti<=(st[top].sp+st[top].ti) && stdent[i].sp>st[top].sp) {
            st[top].ti=stdent[i].ti;
            st[top].sp=stdent[i].sp;
        }
        st[top].id.push_back(stdent[i].id);
    }
    solve();
    return 0;
}
