#include <bits/stdc++.h>

using namespace std;
long long n,x,y,z,h,maxn=1,i,t,u,q,s,k[100009];
int main()
{
    freopen("CANDIES.INP","r",stdin);
    freopen("CANDIES.OUT","w",stdout);
    cin>>t;
    for (u=1;u<=t;u++){
        cin>>n>>q;
        if (n>maxn){
        for (i=maxn+1;i<=n;i++){
            h=i;
            while (h!=0)
            {
                x=1;y=0;z=0;
                while (z<=h)
                {
                    z=x+y;
                    x=y;
                    y=z;
                }
                k[i]++;
                h=h-x;
            }
        }
        }
        for (i=1;i<=n;i++)
        {
            if (k[i]>=q)
                s+=k[i];
        }
        cout<<s<<endl;
        s=0;
        maxn=max(maxn,n);
    }
    return 0;
}
