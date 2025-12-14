#include<stdio.h>
long long int x,k;
const int mod=998244353;
int main(){
    scanf("%lld %lld",&x,&k);
    long long ans=1;
    while(k){
        if(k&1){
            ans=(x*ans)%mod;
        }
        x=(x*x)%mod;
        k=k>>1;
    }
    printf("%lld",ans%mod);
    return 0;
}
