#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,s,t;
int head[N],ver[2*N],Next[2*N],f[N][25];
int d[N],v[N],tot;
queue<int>q;
void add(int x,int y){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
void bfs(){
	d[s]=1;q.push(s);
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(d[y]) continue;
			d[y]=d[x]+1;
			f[y][0]=x;
			for(int j=1;j<=t;++j){
				f[y][j]=f[f[y][j-1]][j-1];
			}	
			q.push(y);
		}
	}	
}	
int lca(int x,int y){
	if(d[x]>d[y]) swap(x,y);
	for(int i=t;i>=0;--i){
		if(d[f[y][i]]>=d[x]) y=f[y][i];
	}
	if(x==y) return x;
	for(int i=t;i>=0;--i){
		if(f[y][i]!=f[x][i]){
			y=f[y][i];
			x=f[x][i];
		}	
	}
	return f[x][0];
}	
int main(){
	scanf("%d %d %d",&n,&m,&s);
	t=((int)(log(n)/log(2)))+1;
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y);add(y,x);
	}
	bfs();
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}