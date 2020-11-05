#include <bits/stdc++.h>

using namespace std;
long long n,k,j,bien,qq[100009],i,s,v=LONG_MAX;
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
    v=0;
    for (i=n;i>=1;i--)
    {
        for (j=a[i].l;j<=a[i].r;j++)
            if (qq[j]==1)
            {
                bien=1;
                break;
            }
        if (bien==0 && (a[i].l>=v || a[i].r<v))
        {
            qq[a[i].l]+=1;
            qq[a[i].r+1]-=1;
            s+=a[i].w;
            v=a[i].r+k;
            for (j=a[i].l+1;j<=a[i].r+1;j++)
                qq[j]=qq[j]+1;
        }
        bien=0;
    }
    cout<<s;
    return 0;
}
