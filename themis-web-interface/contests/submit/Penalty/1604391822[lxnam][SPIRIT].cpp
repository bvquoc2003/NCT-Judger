#include <bits/stdc++.h>

using namespace std;
long long i,a,b,c,dem;
int main()
{
    freopen("SPIRIT.INP","r",stdin);
    freopen("SPIRIT.OUT","w",stdout);
    cin>>a>>b>>c;
    if (c==2)
    {
        c=(b-a)/2;
        cout<<c;
    }
    else{
    while (a<b)
    {
        if ((a+2)%c!=0)
            a=a+2;
        else a=a+1;
        dem++;
        if (a>=b)
            break;
    }
    cout<<dem;
    }
    return 0;
}
