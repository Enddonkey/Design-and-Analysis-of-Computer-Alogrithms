#include<bits/stdc++.h>
using namespace std;
const int N=4000010;
const int mod=998244353;
long long ans=0;
int n,m,fa[N],rankN[N];
bool flag=0;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        fa[i]=i;
        rankN[i]=1;
    } 
    for(int i=1;i<=m;++i){
        int u,v,op;
        scanf("%d %d %d",&op,&u,&v);
        if(!op){
            int fau=find(u);
            int fav=find(v);
            if(fau==fav) continue;
            if(rankN[fau]>rankN[fav]) swap(fau,fav);
            fa[fau]=fav;
            if(rankN[fau]==rankN[fav]) rankN[fav]++;
        }else{
            int fau=find(u);
            int fav=find(v);
            fau==fav?flag=1:flag=0;
            ans=((ans<<1)|(flag))%mod;
        }
    }
    printf("%lld",ans%mod);

    return 0;
}