#include <bits/stdc++.h>

using namespace std;
long long n,k,i,s,sa,sb,a[19],b[19];
int main()
{
    freopen("BGAME.INP","r",stdin);
    freopen("BGAME.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    if (k==1)
    {
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);

        if (n%2==0)
        {
            sa=(a[n/2]+a[n/2+1])/2;
            sb=(b[n/2]+b[n/2+1])/2;
        }
        else {
            sa=a[n/2+1];
            sb=b[n/2+1];
        }
        for (i=1;i<=n;i++)
            s+=abs(a[i]-sa)+abs(b[i]-sb);
        cout<<s;
    }
    return 0;
}
