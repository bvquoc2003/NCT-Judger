#include <bits/stdc++.h>

using namespace std;
long long i,a,b,c,dem;
int main()
{
    freopen("SPIRIT.INP","r",stdin);
    freopen("SPIRIT.OUT","w",stdout);
    cin>>a>>b>>c;
    if (c>b)
    {
        if ((b-a)%2==0)
            cout<<(b-a)/2;
        else cout<<(b-a)/2+1;
        return 0;
    }
    if (c==2)
    {
        c=(b-a)/2;
        cout<<c;
    }
    else{
        if (c%2==0)
        {
            if (a%2==0)
            {
                dem++;
                a++;
            }
            if ((b-a)%2==0)
                dem+=(b-a)/2;
            else {
                dem++;
                dem+=(b-a)/2;
            }
            cout<<dem;
            return 0;
        }
        if ((b-a)%2==0)
            dem+=(b-a)/2;
        else {
            dem+=(b-a)/2;
            dem++;
        }
        dem+=(b-a)/c/2;
        a=(int)a/c;
        a++;
        a*=c;
        b=(int)b/c;
        b*=c;
        if (a%2==0 && b%2==0)
            dem++;
        if (a%2==1 && b%2==1)
            dem++;
        cout<<dem;
    }
    return 0;
}
