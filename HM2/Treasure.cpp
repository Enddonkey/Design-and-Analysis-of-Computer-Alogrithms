#include<bits/stdc++.h>
using namespace std;
int n,W,cnt;
long long v[110],w[110],m[110];
long long new_v[710],new_w[710];
long long f[40010],ans=0;
int main(){
    scanf("%d %d",&n,&W);
    for(int i=1;i<=n;++i){
        scanf("%lld %lld %lld",&v[i],&w[i],&m[i]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m[i];j<<=1){
            m[i]-=j;
            new_v[++cnt]=j*v[i];
            new_w[cnt]=j*w[i];
        }
        if(m[i]){
            new_v[++cnt]=m[i]*v[i];
            new_w[cnt]=m[i]*w[i];
            m[i]=0;
        }
    }
    for(int i=1;i<=cnt;++i){
        for(int j=W;j>=new_w[i];j--){
            f[j]=max(f[j],f[j-new_w[i]]+new_v[i]);
        }
    }
    printf("%lld",f[W]);
    return 0;
}