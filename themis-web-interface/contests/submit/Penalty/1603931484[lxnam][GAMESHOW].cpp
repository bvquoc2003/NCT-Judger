#include <bits/stdc++.h>

using namespace std;
int dem,i,n,s,a[1014],t;
int main()
{
    freopen("GAMESHOW.INP","r",stdin);
    freopen("GAMESHOW.OUT","w",stdout);
    scanf("%d%d",&n,&t);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
    {
        if (a[i]>0)
        {
            s+=a[i];
            dem++;
        }
        if (a[i]<0)
        {
            if (s>t && t<=abs(a[i]))
                s-=t;
            else
                s+=a[i];
        }
        if (s<0)
            break;
    }
    if (s>0)
    {
        if (s>=t)
        {
            s=s/t;
            dem-=s;
        }
        if (dem<0)
            dem=0;
        printf("%d",dem);
    }
    else printf("-1");
    return 0;
}
