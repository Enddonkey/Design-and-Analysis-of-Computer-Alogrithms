#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int n,q,u,v,k,a[maxn];
long long c[maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int x,long long y){
    for(;x<=n;x+=lowbit(x)) c[x]+=y;
}
long long ask(int x){
    long long ans=0;
    for(;x;x-=lowbit(x)) ans+=c[x];
    return ans;
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    while(q--){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %d",&u,&v,&k);
            add(u,k);
            add(v+1,-k);
        }
        else{
            scanf("%d",&u);
            printf("%lld\n",(ask(u)+(long long)a[u]));
        }
    }
    return 0;
}