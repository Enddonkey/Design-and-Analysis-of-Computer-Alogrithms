#include<bits/stdc++.h>
using namespace std;
int n,f[410][410],g[410][410],a[410];
int s[410],maxn,minn=1<<30;
int main(){
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f[i][i]=0;
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		s[i+n]=s[i+n-1]+a[i];
		f[i+n][i+n]=0;
	}
	for(int L=2;L<=n;++L){
		for(int i=1;i<=n+n;++i){
			int j=i+L-1;
			if(j>n*2) break;
			for(int k=i;k<j;++k){
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
				g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]+s[j]-s[i-1]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		maxn=max(maxn,g[i][i+n-1]);
		minn=min(minn,f[i][i+n-1]);
	}
	printf("%d\n%d\n",minn,maxn);
	return 0;
} 