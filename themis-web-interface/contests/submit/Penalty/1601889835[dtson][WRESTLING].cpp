#include <bits/stdc++.h>;

using namespace std;
int n,a[1000000],b[1000000];
int main()
{
    freopen("wrestling.inp","r",stdin);
    freopen("wrestling.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) b[i+n]=b[i];

    int v=0,maxc=0;
    for(int i=1;i<=n;i++)
    {
        int sl=0,k=0;
        for(int j=i;j<=n+i-1;j++)
            {
                k++;
                if(a[k]==b[j]) sl++;
            }
        if(sl>maxc) {maxc=sl; v=i;}
    }
    cout<<v-1<<" "<<maxc;
    return 0;
}
