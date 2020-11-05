#include <bits/stdc++.h>

using namespace std;
long long n,k,i,s,v=LONG_MAX;
struct q
{
    long long l;
    long long r;
    long long w;
};
q a[100009];
bool cmp(const q &x, const q &y)
{
    return x.w < y.w;
}
int main()
{
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r>>a[i].w;
    sort(a+1,a+1+n,cmp);
    for (i=1;i<=n;i++)
        a[i].r+=a[i].l;
    for (i=n;i>=1;i--)
    {
        if (a[i].r<=v)
        {
            s+=a[i].w;
            v=a[i].l-k;
        }
    }
    cout<<s;
    return 0;
}
