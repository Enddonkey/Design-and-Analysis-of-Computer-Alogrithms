#include <stdio.h>
#include <cmath>
#include <algorithm>
int n,a[1000010],ans=0,pre=0;
using namespace std;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        pre=max(pre+a[i],a[i]);
        ans=max(pre,ans);
    }
    printf("%d",ans);
    return 0;
}
