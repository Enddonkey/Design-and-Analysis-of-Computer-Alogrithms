#include <bits/stdc++.h>
using namespace std;
int T,n,a[500010],b[500010];
long long ans;
void meargesort(int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    meargesort(l,mid);
    meargesort(mid+1,r);
    int p1=l,p2=mid+1,cnt=l;
    while(p1<=mid&&p2<=r){
        if(a[p1]<=a[p2]) b[cnt++]=a[p1++];
        else{
            b[cnt++]=a[p2++];
            ans+=(mid-p1+1);
        }
    }
    while(p1<=mid) b[cnt++]=a[p1++];
    while(p2<=r) b[cnt++]=a[p2++];
    for(int i=l;i<=r;++i) a[i]=b[i];
    return;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0;
        memset(a,0,sizeof(a+1));
        memset(b,0,sizeof(b+1));
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        meargesort(1,n);
        printf("%lld\n",ans);
    }


    return 0;
}