#include<bits/stdc++.h>
using namespace std;
int n,k,l=1,r=1,a[100005];
long long s[100005],f[100005][5],q[100005];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        while(i-q[l]>k &&l<=r) l++;
        f[i][1]=f[q[l]][0]-s[q[l]]+s[i];
        while((f[i][0]-s[i]) > (f[q[r]][0]-s[q[r]])) r--;
        r++;
        q[r]=i;
    }
    printf("%lld",max(f[n][0],f[n][1]));
    return 0;
}