#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int n,q,u,v,k,a[maxn];
long long c[3][maxn],sum[maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int num ,int x,long long y){
    for(;x<=n;x+=lowbit(x)) c[num][x]+=y;
}
long long ask(int num ,int x){
    long long ans=0;
    for(;x;x-=lowbit(x)) ans+=c[num][x];
    return ans;
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    while(q--){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %d",&u,&v,&k);
            add(0,u,k);
            add(0,v+1,-k);
            add(1,u,(long long)u*k);
            add(1,v+1,-((long long)(v+1)*k));
        }
        else{
            scanf("%d %d",&u,&v);
            long long ans=sum[v]+(v+1)*ask(0,v)-ask(1,v);
            ans-=sum[u-1]+u*ask(0,u-1)-ask(1,u-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}