#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,m,k;
int f[N],g[N],h[N];
map<pair<int,int>,int> mp;
int main(){
    scanf("%d",&T);
    while(T--){
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(h,0,sizeof(h));
        mp.clear();
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;++i){
            int x; scanf("%d",&x);
            f[x]=1;
        } 
        int ans=0;
        for(int i=1;i<=m;++i){
            int x,y; 
            scanf("%d %d",&x,&y);
            if(f[x]==f[y]&&f[x]==1) ans++;
            else{
                if(x==y){
                    g[x]++;
                    continue;
                }
                if(x>y) swap(x,y);
                if(f[x]==1) g[y]++;
                else if(f[y]==1) g[x]++;
                else mp[{x,y}]++;
            }
        }
        if(k-n<=1){
            printf("%d\n",m);
            continue;
        }
        for(auto &[x,y]:mp){
            pair<int,int> pos=x;
            int a=pos.first,b=pos.second;
            h[a]=max(h[a],g[a]+g[b]+y);
            h[b]=max(h[b],g[a]+g[b]+y);
        }
        vector<int> v;
		int res=0;
		for(int i=1;i<=k;i++){
			res=max(res,h[i]);
			if(!f[i]) v.push_back(g[i]);
		}
		sort(v.begin(),v.end());
		if(v.size()==1) res=max(res,v[0]);
		res=max(res,v[v.size()-1]+v[v.size()-2]);
		printf("%d\n",ans+res);
    }
    return 0;
}