#include <bits/stdc++.h>

using namespace std;
long long k,i,s,bien,h,h_,maxh=LONG_MIN;
int main()
{
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    scanf("%lld",&k);
    h=(int)sqrt(k);
    if (h*h==k)
        maxh=h;
    if (maxh!=LONG_MIN)
        printf("%lld",maxh);
    else {
    s=0;
    h_=1;
    bien=1;
    for (i=1;i<=50000000;i++)
    {
        s=bien+k;
        h_=h_+2;
        bien=bien+h_;
        if (s>=0)
        {
            h=(int)sqrt(s);

            if (h*h==s)
            {
                printf("%lld",h);
                return 0;
                break;
            }
        }
    }
    printf("none");
    }
    return 0;
}
