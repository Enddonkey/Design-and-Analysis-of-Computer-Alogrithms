#include<bits/stdc++.h>
using namespace std;
int k,n;
int main(){
    scanf("%d %d",&n,&k);
    if(!k) printf("-1");
    else{
        printf("%d",k);
        for(int i=1;i<=n;++i){
            if(i!=k) printf(" %d",i);
        }
    }
    return 0;
}