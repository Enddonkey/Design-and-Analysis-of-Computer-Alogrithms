#include<bits/stdc++.h>
using namespace std;
int n,cnt,sequence[100010],tail[100010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&sequence[i]);
    }
    for(int i=1;i<=n;++i){
        if(sequence[i]>tail[cnt]||(cnt==0)){
            tail[++cnt]=sequence[i];
        }else{
            int l=1,r=cnt;
            while(l<r){
                int mid=(l+r)>>1;
                if(tail[mid]>=sequence[i]) r=mid;
                else l=mid+1;
            }
            tail[r]=sequence[i];
        }
    }
    printf("%d",cnt);
    return 0;
}