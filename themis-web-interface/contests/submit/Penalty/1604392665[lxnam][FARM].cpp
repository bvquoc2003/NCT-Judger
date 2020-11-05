#include <bits/stdc++.h>

using namespace std;
long long t_,i,t,z,maxc,q_,p_,v,w[1009],a[1009],n,k,q,p,s[1009],j;
int main()
{
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin>>n>>k>>q_>>p_;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (v=1;v<=n-k;v++){
    z=0;
    q=q_;p=p_;
    for (i=v;i<=n;i=i+k)
    {
        z++;
        w[z]=a[i];
    }
    sort(w+1,w+1+z);
    for (i=z;i>=1;i--)
    {
        if (q>=p)
        {
            t+=w[i]*p;
            q-=p;
        }
        else {
            t+=w[i]*q;
            q=0;
        }
        if (q==0)
            break;
    }
    t_=max(t,t_);
    t=0;
    }
    cout<<t_;
    return 0;
}
