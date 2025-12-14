#include<bits/stdc++.h>
using namespace std;
const int N=25e2+10;
const int M=2e5;
struct node{
	int num,dis;
	bool operator <(const node &x) const {
		return x.dis<dis;
	} 
};
int n,m,s,t;
int head[N],ver[M],Next[M],edge[M];
int dis[N],v[N],tot;
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;Next[tot]=head[x];head[x]=tot;
}
void dijia(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(v,0,sizeof(v));
	dis[s]=0;
	for(int i=1;i<n;++i){
        int x=0;
        for(int j=1;j<=n;++j) if(!v[j]&&(x==0||dis[j]<dis[x])) x=j;
		v[x]=1;
        for(int i=head[x];i;i=Next[i]){
			int y=ver[i],z=edge[i];
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
			}
		}
    }
			
}	
int main(){
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dijia(s);
	printf("%d ",dis[t]);
	return 0;
}