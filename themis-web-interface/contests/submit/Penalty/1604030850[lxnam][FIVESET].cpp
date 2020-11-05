#include <bits/stdc++.h>

using namespace std;
long long a[100009],b[100009],s,i,j,c[100009],w1,w2,v,n,vt1,vt2,vt4,vt5,max1,max2,max3;
int main()
{
    freopen("FIVESET.INP","r",stdin);
    freopen("FIVESET.OUT","w",stdout);
    cin>>n>>w1>>w2;
    max3=-LONG_MAX;
    for (i=1;i<=n;i++)
    {
        cin>>v;
        a[i]=w1*v;
        b[i]=w2*v;
        c[i]=v;
        max3=max(v,max3);
    }
    if (w1==0 && w2==0) cout<<max3;
    else {
    if (w1==0 && w2!=0)
    {
        max2=-LONG_MAX;
        max3=-LONG_MAX;
        for (i=1;i<=n-2;i++)
        for (j=i+2;j<=n;j++)
        {
            s=b[i]+b[j];
            if (s>max2)
            {
                max2=s;
                vt2=i;
                vt4=j;
            }
        }
        for (i=vt2+1;i<=vt4-1;i++)
            max3=max(max3,c[i]);
        cout<<max2+max3;
        return 0;
    }
    if (n<=100){
    max1=-LONG_MAX;
    max2=-LONG_MAX;
    max3=-LONG_MAX;
    for (i=1;i<=n-4;i++)
        for (j=i+4;j<=n;j++)
        {
            s=a[i]+a[j];
            if (s>max1)
            {
                max1=s;
                vt1=i;
                vt5=j;
            }
        }
    for (i=vt1+1;i<=vt5-1-2;i++)
        for (j=i+2;j<=vt5-1;j++)
        {
            s=b[i]+b[j];
            if (s>max2)
            {
                max2=s;
                vt2=i;
                vt4=j;
            }
        }
    for (i=vt2+1;i<=vt4-1;i++)
        max3=max(max3,c[i]);
    cout<<max1+max2+max3;
    return 0;
    }
    }
    return 0;
}
