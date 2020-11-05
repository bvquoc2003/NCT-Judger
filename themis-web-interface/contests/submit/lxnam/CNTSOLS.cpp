#include <bits/stdc++.h>

using namespace std;
int k,t,i,j,u,z,h,si,su,sj,dem,d,m,n;
int luythua(int a,int d) {
     if (d==0) return 1;
     int b=luythua(a,d/2);
     b=(b*b) % n;
     if (d%2) b=(b*a) % n;
     return b;
}
int main()
{
    freopen("CNTSOLS.INP","r",stdin);
    freopen("CNTSOLS.OUT","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;k++)
    {
        scanf("%d%d%d%d",&u,&d,&m,&n);
        if (u<n)
            h=u+1;
        else h=n;
        for (i=0;i<h;i++)
            for (j=0;j<h;j++)
                for (u=0;u<h;u++)
                {
                    si=luythua(i,d);
                    sj=luythua(j,d);
                    su=luythua(u,d);
                    if ((si+sj+su)%n==m%n)
                        dem++;
                }
        printf("%d\n",dem);
        dem=0;
    }
    return 0;
}
