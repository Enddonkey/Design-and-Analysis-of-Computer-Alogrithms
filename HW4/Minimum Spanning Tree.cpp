#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=5e5+10;
struct node{
	int u,v,dis;
}edge[M];
int n,m,tot=1;
int fa[N];
long long ans;
bool cmp(node a,node b){
	return a.dis<b.dis;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].dis);
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<n;++i){
		while(find(edge[tot].u)==find(edge[tot].v)) tot++;
		fa[find(edge[tot].u)]=find(edge[tot].v);ans+=edge[tot].dis;
	}printf("%lld",ans);
	return 0;
}