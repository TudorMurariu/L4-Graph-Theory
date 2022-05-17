#include <bits/stdc++.h>

using namespace std;
ifstream in("apm.in");
ofstream out("apm.out");
struct ura{
    int nod1,nod2,cost;
};
ura v[400005],ans[400005];
bool ord(ura a, ura b){
    if(a.cost<b.cost)
        return true;
    if(a.cost<b.cost && a.nod1<b.nod1)
        return true;
    return false;
}
int sef[200005];

int sefsuprem(int x)
{
    if(sef[x]==x)
        return x;
    return sef[x]=sefsuprem(sef[x]);
}
void unite(int x, int y)
{
    sef[sefsuprem(x)]=sefsuprem(y);
}

int main()
{
    int n,m,rez=0,costmin=0,i;
    in>>n>>m;
    for(i=1;i<=m;++i)
        in>>v[i].nod1>>v[i].nod2>>v[i].cost;
    for(i=1;i<=n;++i)
        sef[i]=i;
    sort(v+1,v+m+1,ord);
    for(i=1;i<=m && rez<n-1;++i)
        if(sefsuprem(v[i].nod1)!=sefsuprem(v[i].nod2)){
            ++rez;
            ans[rez]=v[i];
            costmin+=v[i].cost;
            unite(sefsuprem(v[i].nod1),sefsuprem(v[i].nod2));
        }
    out<<costmin<<'\n'<<n-1<<'\n';
    for(i=1;i<=n-1;++i)
        out<<ans[i].nod2<<" "<<ans[i].nod1<<'\n';
    return 0;
}
