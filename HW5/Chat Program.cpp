#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,k,m,c,d;
long long a[N];
int ans[N];
bool cheak(long long x){
    int cnt=0;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;++i) cnt+=a[i]>=x?1:0;
    if(cnt>=k) return true;
    for(int p=1;p<=n-m+1;++p){
        long long tmp=0;
        for(int j=1;j<=m;++j){
            tmp+=(a[min(j+p-1,n)]+c+(j-1)*d)>=x?1:0;
            if(a[min(j+p-1,n)>=x]) tmp--;
        }
       if (cnt+tmp>=k) return true;
    }
    return false;

}
int main(){
    scanf("%d %d %d %d %d",&n,&k,&m,&c,&d);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    long long l=0,r=1e18,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(cheak(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",r);
    return 0;
}