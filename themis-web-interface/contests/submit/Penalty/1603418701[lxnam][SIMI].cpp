#include <bits/stdc++.h>

using namespace std;
string z,s;
long long t,i,dem,j;
int main()
{
    freopen("SIMI.INP","r",stdin);
    freopen("SIMI.OUT","w",stdout);
    getline(cin,s);
    z=s;
    t=s.length();
    for(i=0;i<s.length();i++)
    {
        dem=0;
        z.erase(0,1);
        for (j=0;j<z.length();j++)
            if (z[j]==s[j])
                dem++;
            else break;
        t+=dem;
    }
    printf("%lld",t);
    return 0;
}
