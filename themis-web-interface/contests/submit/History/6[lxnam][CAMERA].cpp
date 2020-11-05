#include <bits/stdc++.h>

using namespace std;
unsigned long long n,i,j,maxc,k[100005],a[100005];
string s;
int main()
{
    freopen("CAMERA.INP","r",stdin);
    freopen("CAMERA.OUT","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    cin>>s;
    for (i=1;i<=n;i++)
    {
        maxc=0;
        if (s[i-1]=='E')
        {
            maxc=0;
            for (j=i+1;j<=n;j++)
                if (maxc<=a[j])
                {
                    k[i]++;
                    maxc=a[j];
                }
        }
        else {
            maxc=0;
            for (j=i-1;j>=1;j--)
                if (maxc<=a[j])
                {
                    k[i]++;
                    maxc=a[j];
                }
        }
    }
    for (i=1;i<=n;i++)
        cout<<k[i]<<" ";
    return 0;
}
