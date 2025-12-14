#include<bits/stdc++.h>
using namespace std;
long long f[11][121][1<<11];
int n,k,num[1<<11],s[1<<11],cnt=1;
bool cheak_state(int state1,int state2){
    if(state1&state2) return false;
    if((state1<<1)&state2) return false;
    if((state1>>1)&state2) return false;
    return true;
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<(1<<n);++i){
        if(!(i&(i>>1))) s[cnt++]=i;
        for(int j=0;j<n;++j){
            num[i]+=1&(i>>j);
        }
    }
    f[0][0][1]=1;
    for (int i=1;i<=n+1;++i){
        for(int j=0;j<=k;++j){
            for(int state=1;state<cnt;++state){
                for(int last_state=0;last_state<cnt;++last_state){
                    if(j>=num[s[state]]){
                        if(cheak_state(s[state],s[last_state])) f[i][j][state]+=f[i-1][j-num[s[state]]][last_state];
                    }
                }
            }
        }
    }
    printf("%lld",f[n+1][k][1]);
    return 0;
}