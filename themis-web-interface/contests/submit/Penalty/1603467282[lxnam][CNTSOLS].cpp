#include <bits/stdc++.h>

using namespace std;
int k,t,i,j,u,z,h,si,su,sj,dem,d,m,n;
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
                    si=1;
                    sj=1;
                    su=1;
                    for (z=1;z<=d;z++)
                    {
                        si=si*i;
                        sj=sj*j;
                        su=su*u;
                    }
                    if ((si+sj+su)%n==m%n)
                        dem++;
                }
        printf("%d\n",dem);
        dem=0;
    }
    return 0;
}
