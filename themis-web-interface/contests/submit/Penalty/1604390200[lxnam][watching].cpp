#include <bits/stdc++.h>

using namespace std;
long long s,m,n,t,p1,v__,k,v_,v,bp1,bp2,i,tg,h,a[100009],b[100009];
int main()
{
    freopen("watching.inp","r",stdin);
    freopen("watching.out","w",stdout);
    cin>>n>>m>>t>>k;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
    {
        if (a[i]>t || tg>t)
            break;
        if (a[i]-tg>0)
        {
            s+=(a[i]-tg);
            h=upper_bound(b+1,b+1+m,a[i])-b;
            if (h==v_)
            {
                s-=(a[i]-tg);
                bp1=1;
                break;
            }
            tg=b[h];
            if (tg<a[i]+k)
                tg=a[i]+k;
            v_=h;
        }
        if (a[i]<=tg)
        {
            v=a[i]+k;
            if (v>tg)
                tg=v;
        }
    }
    p1=s;
    s=0;
    tg=a[1];
    v_=0;
    for (i=1;i<=m;i++)
    {
        if (b[i]>t || tg>t)
            break;
        if (b[i]>tg)
        {
            s+=b[i]-tg;
            h=upper_bound(a+1,a+1+n,b[i])-a;
            if (h==v__)
            {
                s-=(b[i]-tg);
                bp2=1;
                break;
            }
            tg=a[h];
            if (tg<b[i]+k)
                tg=b[i]+k;
            v__=h;
        }
        if (b[i]<=tg)
        {
            v=b[i]+k;
            if (v>tg)
                tg=v;
        }
    }
    if (bp1==1)
        s+=(t-a[v__]);
    if (bp2==1)
        p1+=(t-b[v_]);
    cout<<p1<<" "<<s;
    return 0;
}
