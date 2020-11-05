#include <bits/stdc++.h>

using namespace std;
long long dem,v,c,j,i,n,kt[100000];
vector <int> b[100009];
struct q
{
    long long l, r, id;
};
q a[100009];
bool cmp(const q &x, const q &y)
{
    return x.r<y.r;
}
int main()
{
    freopen("box2.inp","r",stdin);
    freopen("box2.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for (i=1;i<n;i++)
    {
        v=a[i].l;c=a[i].r;
        if (kt[i]==0)
        b[i].push_back(a[i].id);
        kt[i]=1;
        for (j=i+1;j<=n;j++)
        {
            if (kt[j]==0)
            {
                if (a[j].l>v && a[j].r>c)
                {
                    b[i].push_back(a[j].id);
                    v=a[j].l;
                    c=a[j].r;
                    dem++;
                    kt[j]=1;
                }
            }
        }
    }
    cout<<dem<<endl;
    for (i=1;i<=n;i++)
    {
        if (b[i].size()>0)
        {
            cout<<b[i].size()<<" ";
            for (j=b[i].size()-1;j>=0;j--)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
